#include "mainwindow.h"
#include "qpainter.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <QRandomGenerator>
#include <QMessageBox>

#include "classicfly.h"
#include "greenfly.h"
#include "bluefly.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    flies.push_back(ClassicFly());
    flies.push_back(GreenFly());
    flies.push_back(BlueFly());

    flyInitialPos = ui->flyObject->pos();
    flyLevel = -1;
    updateFlyLevel();

    ui->frogKillsCount->setVisible(false);
    frogKills = 0;

    this->setMouseTracking(true);
    ui->centralwidget->setMouseTracking(true);
    ui->flyObject->setMouseTracking(true);

    flyUIObjects.push_back(ui->flyObject);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete frogTimer;
}

bool MainWindow::event(QEvent *event)
{
    if (event->type() != QEvent::MouseMove)
        return QMainWindow::event(event);

    if (flyLevel == 2)
        return QMainWindow::event(event);

    QPoint mousePos = ui->centralwidget->mapFromGlobal(QCursor::pos());

    for (auto flyUI : flyUIObjects)
    {
        QPoint flyPos = flyUI->pos();
        double distance = calculateDistance(flyPos, mousePos);
        moveFly(flyUI, distance);

        flyPos = ui->centralwidget->mapFromGlobal(
            flyUI->mapToGlobal(flyUI->rect().center())
        );

        if (ui->trapPlantObject->geometry().contains(flyPos)) {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Муха спіймана, спробуйте ще раз :)");
            msgBox.exec();

            for (auto flyUI : flyUIObjects)
            {
                flyUI->move(flyInitialPos);
            }
        }

        if (ui->windowObject->geometry().contains(flyPos, true)) {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText(QString("Побіг вдався 😁\nВи пройшли: %1/%2.").arg(QString::number(flyLevel + 1), QString::number(MAX_LEVEL)));
            msgBox.exec();

            switch (flyLevel) {
            case 0: {
                updateFlyLevel();
                break;
            }
            case 1: {
                updateFlyLevel();

                QPixmap frogPixmap(":/assets/frog.png");
                ui->frogObject->setIcon(QIcon(frogPixmap));
                ui->frogObject->setIconSize(QSize(FLY_OBJECT_WIDTH, FLY_OBJECT_HEIGHT));

                frogTimer = new QTimer(this);
                frogTimer->setInterval(32);
                connect(frogTimer, &QTimer::timeout, this, &MainWindow::frogTimerCallback);
                frogTimer->start();

                ui->frogKillsCount->setVisible(true);

                break;
            }
            default:
                break;
            }

            for (auto flyUI : flyUIObjects)
            {
                flyUI->move(flyInitialPos);
            }
        }
    }

    return QMainWindow::event(event);
}

void MainWindow::moveFly(QPushButton* flyUI, double distance)
{
    if (distance > FLY_MOVE_DIST_CONDITION)
        return;

    QPoint flyPos = flyUI->pos();
    QPoint newFlyPos(0, 0);

    if (flyLevel == 2) {
        QPoint frogPosCenter = ui->centralwidget->mapFromGlobal(
            ui->frogObject->mapToGlobal(ui->frogObject->rect().center())
        );

        if (flyUI->geometry().contains(frogPosCenter)) {
            frogKills += 1;
            ui->frogKillsCount->setText(QString("Рахунок: %1").arg(frogKills));
        }
    }

    while (true) {
        int randomX = generateRandomXY() + 10;
        int randomY = generateRandomXY();

        newFlyPos.setX(flyPos.x() + randomX);
        newFlyPos.setY(flyPos.y() + randomY);

        int windowMoveLimitForX = this->size().width() - flyUI->iconSize().width();
        if (newFlyPos.x() < 0 || newFlyPos.x() > windowMoveLimitForX)
            continue;

        int windowMoveLimitForY = this->size().height() - flyUI->iconSize().height();
        if (newFlyPos.y() < 0 || newFlyPos.y() > windowMoveLimitForY)
            continue;

        break;
    }

    flyUI->move(newFlyPos);
}

int MainWindow::generateRandomXY() {
    return QRandomGenerator::global()->bounded(-FLY_MOVE_DIST_CONDITION, FLY_MOVE_DIST_CONDITION);
}

double MainWindow::calculateDistance(const QPoint &firstPoint, const QPoint &secondPoint) {
    return sqrt(pow(secondPoint.x() - firstPoint.x(), 2) + pow(secondPoint.y() - firstPoint.y(), 2));
}

void MainWindow::updateFlyLevel()
{
    flyLevel += 1;

    if (flyLevel >= flies.size())
        return;

    if (flyLevel != 1) {
        ui->flyObject->setIcon(QIcon(flies[flyLevel].getFlyPixmap()));
        ui->flyObject->setIconSize(QSize(FLY_OBJECT_WIDTH, FLY_OBJECT_HEIGHT));
    }

    if (flyLevel == 0)
    {
        flyUIObjects.clear();
        flyUIObjects.push_back(ui->flyObject);

        ui->duplicateFly->setVisible(false);
    }
    else if (flyLevel == 1)
    {
        flyUIObjects.clear();
        flyUIObjects.push_back(ui->flyObject);
        flyUIObjects.push_back(ui->duplicateFly);

        ui->duplicateFly->setIcon(QIcon(flies[flyLevel].getFlyPixmap()));
        ui->duplicateFly->setIconSize(QSize(FLY_OBJECT_WIDTH, FLY_OBJECT_HEIGHT));
        ui->duplicateFly->move(ui->flyObject->pos());

        ui->duplicateFly->setVisible(true);
    }
    else if (flyLevel == 2)
    {
        flyUIObjects.clear();
        flyUIObjects.push_back(ui->flyObject);

        ui->duplicateFly->setVisible(false);
    }
}

void MainWindow::frogTimerCallback()
{
    double speed = 2.0;

    QPoint flyPosCenter = ui->centralwidget->mapFromGlobal(
        ui->flyObject->mapToGlobal(ui->flyObject->rect().center())
    );
    QPoint frogPosCenter = ui->centralwidget->mapFromGlobal(
        ui->frogObject->mapToGlobal(ui->frogObject->rect().center())
    );

    QPoint flyPos = ui->flyObject->pos();
    QPoint frogPos = ui->frogObject->pos();

    moveFly(ui->flyObject, calculateDistance(flyPos, frogPosCenter));

    double dx = flyPosCenter.x() - frogPos.x();
    double dy = flyPosCenter.y() - frogPos.y();
    double distance = calculateDistance(frogPos, flyPosCenter);

    QPoint newFrogPos(
        frogPos.x() + ((dx / distance) * speed),
        frogPos.y() + ((dy / distance) * speed)
    );
    ui->frogObject->move(newFrogPos.x(), newFrogPos.y());
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap background((flyLevel == 2) ? ":/assets/room_bg_no_window.png" : ":/assets/room_bg.png");

    painter.drawPixmap(0, 0, width(), height(), background);

    ui->centralwidget->update();
    QMainWindow::paintEvent(event);
}
