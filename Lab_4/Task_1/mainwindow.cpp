#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap flyPixmap(":/assets/fly.png");
    ui->flyObject->setIcon(QIcon(flyPixmap));
    ui->flyObject->setIconSize(QSize(64, 64));
    flyInitialPos = ui->flyObject->pos();

    QPixmap trapPlantPixmap(":/assets/plant_trap.png");
    ui->trapPlantObject->setIcon(QIcon(trapPlantPixmap));
    ui->trapPlantObject->setIconSize(QSize(256, 256));
    ui->trapPlantObject->stackUnder(ui->flyObject);

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
        QPoint trapPlantPos = ui->trapPlantObject->pos();

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
            msgBox.setText("Муха спіймана, кінець гри :)");
            msgBox.exec();

            ui->flyObject->move(flyInitialPos);
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
