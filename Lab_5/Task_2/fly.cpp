#include "fly.h"
#include "mainwindow.h"

#include <QIcon>

Fly::Fly(QPixmap flyPixmap)
{
    setFlyPixmap(flyPixmap);
}

Fly::~Fly()
{

}

QPixmap Fly::getFlyPixmap() const
{
    return flyPixmap;
}

void Fly::setFlyPixmap(QPixmap newFlyPixmap)
{
    flyPixmap = newFlyPixmap;
}
