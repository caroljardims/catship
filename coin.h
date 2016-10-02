/*
    Header da Moeda
*/

#ifndef COIN_H
#define COIN_H
#include "ship.h"
#include <QObject>
#include <QTimer>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QGraphicsScene>
#include <QPainter>
#include <QList>

class Coin: public QObject, public QGraphicsPathItem{
    Q_OBJECT
public:
    Coin();
    QPainterPath food;
    QTimer *timer;
public slots:
    void move();
};

#endif // COIN_H
