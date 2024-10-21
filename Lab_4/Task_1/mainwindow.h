#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define FLY_MOVE_DIST_CONDITION 70

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

    bool event(QEvent * event) override;

    int generateRandomXY();
    double calculateDistance(QPoint &firstPoint, QPoint &secondPoint);
};
#endif // MAINWINDOW_H
