#ifndef FLY_H
#define FLY_H

#include <QObject>
#include <QPushButton>

class Fly
{
public:
    Fly(QPixmap flyPixmap);
    ~Fly();

    QPixmap getFlyPixmap() const;
    void setFlyPixmap(QPixmap newFlyPixmap);

private:
    QPixmap flyPixmap;

};

#endif // FLY_H
