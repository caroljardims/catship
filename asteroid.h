/*
    Header do Asteroide
*/

#ifndef ASTEROID_H
#define ASTEROID_H
#include "ship.h"
#include "shot.h"
#include "life.h"
#include <QObject>
#include <QTimer>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QGraphicsScene>
#include <QPainter>
#include <QList>

class Asteroid: public QObject, public QGraphicsPathItem{
    Q_OBJECT
public:
    Asteroid();
    int level=1;
    QPainterPath flower;
    QTimer *timer;
public slots:
    void move();
};

#endif // ASTEROID_H
