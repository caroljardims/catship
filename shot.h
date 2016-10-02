/*
    Header do Tiro
*/

#ifndef SHOT_H
#define SHOT_H

#include <QGraphicsRectItem>
#include <QObject>

class Shot: public QObject, public QGraphicsRectItem{
  Q_OBJECT
public:
    // ângulo de rotação
    int r;
    Shot(int r);
public slots:
    void move();
};
#endif // SHOT_H
