#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "fly.h"

#define FLY_OBJECT_WIDTH 48
#define FLY_OBJECT_HEIGHT 48

#define FLY_MOVE_DIST_CONDITION 70

#define MAX_LEVEL 3

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QPoint flyInitialPos;

    int flyLevel;

    std::vector<Fly> flies;

    QTimer *frogTimer;

    int frogKills;

    std::vector<QPushButton*> flyUIObjects;

    bool event(QEvent * event) override;

    void moveFly(QPushButton* flyUI, double distance);

    int generateRandomXY();
    double calculateDistance(const QPoint &firstPoint, const QPoint &secondPoint);

    void updateFlyLevel();

private slots:
    void frogTimerCallback();

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // MAINWINDOW_H
