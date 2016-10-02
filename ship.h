/*
    Header da Nave
*/

#ifndef SHIP_H
#define SHIP_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QPolygon>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsPolygonItem>

class Ship: public QObject, public QGraphicsPolygonItem{
    Q_OBJECT
private:
    QPolygon spaceship;
    QTimer *timer;
    // ângulo de rotação
    int r=0;
    // aceleração
    int a, count_a;
public:
    Ship();
    int xcoord[20];
    int ycoord[20];
public slots:
    void keyPressEvent(QKeyEvent *event);
    void rotateSpaceship();
    void update();
    void createAsteroid();
    void createCoin();
};


#endif // SHIP_H
