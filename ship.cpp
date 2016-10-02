/*
    Funções da Nave
*/

#include "ship.h"
#include "shot.h"
#include "asteroid.h"
#include "coin.h"
#include <QGraphicsScene>
#include <stdlib.h>
#define PI 3.14159265359

Ship::Ship(){

    // matriz coordenadas desenho do gato
    xcoord[0] = 10; xcoord[1] = 20; xcoord[2] = 30; xcoord[3] = 40; xcoord[4] = 50;
    xcoord[5] = 50; xcoord[6] = 40; xcoord[7] = 25; xcoord[8] = 25; xcoord[9] = 30;
    xcoord[10] = 30; xcoord[11] = 30; xcoord[12] = 20; xcoord[13] = 20; xcoord[14] = 20;
    xcoord[15] = 25; xcoord[16] = 25; xcoord[17] = 10; xcoord[18] = 0; xcoord[19] = 0;

    ycoord[0] = 0; ycoord[1] = 20; ycoord[2] = 20; ycoord[3] = 0; ycoord[4] = 20;
    ycoord[5] = 40; ycoord[6] = 50; ycoord[7] = 50; ycoord[8] = 40; ycoord[9] = 35;
    ycoord[10] = 20; ycoord[11] = 35; ycoord[12] = 35; ycoord[13] = 20; ycoord[14] = 35;
    ycoord[15] = 40; ycoord[16] = 50; ycoord[17] = 50; ycoord[18] = 40; ycoord[19] = 20;

    for(int i=0;i<20;i++)
        this->spaceship << QPoint(xcoord[i],ycoord[i]);

    setPolygon(spaceship);
    setBrush(QBrush(Qt::gray, Qt::SolidPattern));
    setPen(QPen(Qt::darkGray, 2, Qt::DashDotLine, Qt::RoundCap));
    this->timer = new QTimer(this);
    this->count_a = 0;
}

void Ship::keyPressEvent(QKeyEvent *event){
    // define ângulo de rotação da esquerda
    if (event->key() == Qt::Key_Left){
        this->r-=5;
    } // define ângulo de rotação da direita
    else if (event->key() == Qt::Key_Right){
        this->r+=5;
    } // acelera nave
    else if (event->key() == Qt::Key_Up){
        if(this->count_a < 5){
            this->a=40;
            connect(timer, SIGNAL(timeout()), this, SLOT(update()));
            timer->start(this->a);
        }
        this->count_a++;
    } // frea nave
    else if (event->key() == Qt::Key_Down){
        timer->stop();
        this->a*=2;
        timer->start(this->a);
        if(this->a > 500){
            this->count_a = 0;
            timer->stop();
            timer->disconnect();
        }
    } // atira bolas de pelo
    else if (event->key() == Qt::Key_Space){
        // cria bolas de pelo
        Shot *hairball1 = new Shot(this->r);
        Shot *hairball2 = new Shot(this->r);
        hairball1->setPos(x(),y());
        hairball2->setPos(x()+40,y());
        scene()->addItem(hairball1);
        scene()->addItem(hairball2);
        printf("\nPEW!");
    }
    if(r < -360 || r > 360)
        this->r=0;
    rotateSpaceship();
}
// função de rotacionar nave
void Ship::rotateSpaceship(){
    double seno, cosseno;
    seno = sin(this->r*PI/180);
    cosseno = cos(this->r*PI/180);
    this->spaceship.clear();
    setPolygon(this->spaceship);
    for(int i=0;i<20;i++){
        this->spaceship << QPoint(xcoord[i]*cosseno-ycoord[i]*seno,xcoord[i]*seno+ycoord[i]*cosseno);
    }
    setPolygon(this->spaceship);
}
// atualiza posição da nave de acordo com o ângulo de rotação
void Ship::update(){
    double seno, cosseno;
    seno = sin(this->r*PI/180);
    cosseno = cos(this->r*PI/180);
    setPos(x()+5*seno,y()-5*cosseno);
    // gera portal para atravessar da cena de volta para a cena do outro lado
    if(x() <=0){
        setPos(800,y());
    } else if(x() >= 800){
        setPos(0,y());
    }
    if(y() <= 0){
        setPos(x(),600);
    } else if(y() >= 600){
        setPos(x(),0);
    }
}
// cria asteroides aleatoriamente
 void Ship::createAsteroid(){
     int posx = rand() % 800;
     Asteroid *flower = new Asteroid();
     flower->setPos(posx,0);
     scene()->addItem(flower);
 }
// cria moedas aleatoriamente
 void Ship::createCoin(){
     int posx = rand() % 800;
     Coin *food = new Coin();
     food->setPos(posx,600);
     scene()->addItem(food);
 }
