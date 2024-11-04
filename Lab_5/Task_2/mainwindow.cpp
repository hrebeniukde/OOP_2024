#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <QRandomGenerator>
#include <QMessageBox>

#include "classicfly.h"
#include "greenfly.h"
#include "blackfly.h"
#include "bluefly.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    flies.push_back(ClassicFly());
    flies.push_back(GreenFly());
    flies.push_back(BlackFly());
    flies.push_back(BlueFly());

    flyInitialPos = ui->flyObject->pos();
    flyLevel = -1;
    updateFlyLevel();

    QPixmap trapPlantPixmap(":/assets/plant_trap.png");
    ui->trapPlantObject->setIcon(QIcon(trapPlantPixmap));
    ui->trapPlantObject->setIconSize(QSize(256, 256));
    ui->trapPlantObject->stackUnder(ui->flyObject);

    QPixmap windowPixmap(":/assets/window.png");
    ui->windowObject->setIcon(QIcon(windowPixmap));
    ui->windowObject->setIconSize(QSize(128, 128));
    ui->windowObject->stackUnder(ui->flyObject);

    this->setMouseTracking(true);
    ui->centralwidget->setMouseTracking(true);
    ui->flyObject->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent *event)
{
    if (event->type() == QEvent::MouseMove) {
        QPoint mousePos = ui->centralwidget->mapFromGlobal(QCursor::pos());
        QPoint flyPos = ui->flyObject->pos();

        double mouseDistance = calculateDistance(flyPos, mousePos);
        if (mouseDistance <= FLY_MOVE_DIST_CONDITION) {
            QPoint newFlyPos(0, 0);

            while (true) {
                int randomX = generateRandomXY();
                int randomY = generateRandomXY();

                newFlyPos.setX(flyPos.x() + randomX);
                newFlyPos.setY(flyPos.y() + randomY);

                int windowMoveLimitForX = this->size().width() - ui->flyObject->iconSize().width();
                if (newFlyPos.x() < 0 || newFlyPos.x() > windowMoveLimitForX)
                    continue;

                int windowMoveLimitForY = this->size().height() - ui->flyObject->iconSize().height();
                if (newFlyPos.y() < 0 || newFlyPos.y() > windowMoveLimitForY)
                    continue;

                break;
            }

            ui->flyObject->move(newFlyPos);
        }

        if (ui->trapPlantObject->geometry().contains(flyPos)) {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Муха спіймана, спробуйте ще раз :)");
            msgBox.exec();

            ui->flyObject->move(flyInitialPos);
        }

        if (ui->windowObject->geometry().contains(flyPos)) {
            if (flyLevel + 1 == MAX_LEVEL) {
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setText("Вау, вітаю! Ти пройшов гру \"Піймай муху\" 😍");
                msgBox.exec();

                flyLevel = -1;
            } else {
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setText(QString("Побіг вдався 😁\nВи пройшли: %1/%2.").arg(QString::number(flyLevel + 1), QString::number(MAX_LEVEL)));
                msgBox.exec();
            }

            ui->flyObject->move(flyInitialPos);
            updateFlyLevel();
        }
    }

    return QMainWindow::event(event);
}

int MainWindow::generateRandomXY() {
    return QRandomGenerator::global()->bounded(-FLY_MOVE_DIST_CONDITION, FLY_MOVE_DIST_CONDITION);
}

double MainWindow::calculateDistance(QPoint &firstPoint, QPoint &secondPoint) {
    return sqrt(pow(secondPoint.x() - firstPoint.x(), 2) + pow(secondPoint.y() - firstPoint.y(), 2));
}

void MainWindow::updateFlyLevel()
{
    flyLevel += 1;
    ui->flyObject->setIcon(QIcon(flies[flyLevel].getFlyPixmap()));
    ui->flyObject->setIconSize(QSize(64, 64));
}
