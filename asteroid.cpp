/*
    Funções do Asteroide
*/

#include "asteroid.h"
#include "game.h"
#define PI 3.14159265359

extern Game * game;

Asteroid::Asteroid(){

    // curva bezier do asteroide
    this->flower.moveTo(0,20);
    this->flower.cubicTo(0,10, 10,0, 20,0);
    this->flower.cubicTo(20,10, 40,10, 40,0);
    this->flower.cubicTo(50,0, 60,10, 60,20);
    this->flower.cubicTo(50,20, 50,40, 60,40);
    this->flower.cubicTo(60,50, 50,60, 40,60);
    this->flower.cubicTo(40,50, 20,50, 20,60);
    this->flower.cubicTo(10,60, 0,50, 0,40);
    this->flower.cubicTo(10,40, 10,20, 0,20);
    this->flower.moveTo(30,40);
    this->flower.cubicTo(20,40, 20,20, 30,20);
    this->flower.cubicTo(40,20, 40,40, 30,40);

    // cor do asteroide dependendo da fase atual do jogador
    if(this->level == 1 )
        setBrush(QBrush(Qt::magenta, Qt::SolidPattern));
    else if(this->level==2)
        setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    else if(this->level==3)
        setBrush(QBrush(Qt::darkCyan, Qt::SolidPattern));
    else if(this->level==4)
        setBrush(QBrush(Qt::darkGreen, Qt::SolidPattern));
    else if(this->level==5)
        setBrush(QBrush(Qt::white, Qt::SolidPattern));
    else if(this->level>=6)
        setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    setPen(QPen(Qt::white, 2, Qt::DashDotLine, Qt::RoundCap));
    setPath(this->flower);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
            timer->start(50);
}
 void Asteroid::move(){
     // movimento do asteroide (queda)
     setPos(x(),y()+1);
     if((y() < 0 || y() > 600) &&(x() < 0 || x() > 800)){
         scene()->removeItem(this);
         delete this;
     }

     // altera cor de todos os asteroides da tela dependendo da fase atual do jogador
     if(game->score->getNextLevel() == 2){
         setBrush(QBrush(Qt::blue, Qt::SolidPattern));
         this->level = 2;
     } else if(game->score->getNextLevel() == 3){
         setBrush(QBrush(Qt::darkCyan, Qt::SolidPattern));
         this->level = 3;
     } else if(game->score->getNextLevel() == 4){
         setBrush(QBrush(Qt::darkGreen, Qt::SolidPattern));
         this->level = 4;
     } else if(game->score->getNextLevel() == 5){
         setBrush(QBrush(Qt::white, Qt::SolidPattern));
         this->level = 5;
     } else if(game->score->getNextLevel() == 6){
         setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
         this->level = 6;
     }

     // lista de objetos que colidem
     QList<QGraphicsItem *> colliding_items = collidingItems();
         for (int i = 0, n = colliding_items.size(); i < n; ++i){
             if (typeid(*(colliding_items[i])) == typeid(Ship)){
                 // perde vida ao colidir com asteroide
                 for(int i=0; i<game->score->getNextLevel();i++){
                     if(game->score->getNextLevel() < 6)
                         game->life->decrease();
                 }
                 // perde o jogo se a vida for menor ou igual a zero
                  if(game->life->getLife() <= 0 ){
                      scene()->removeItem(colliding_items[i]);
                      delete colliding_items[i];

                      // anuncia fim de jogo
                      game->life->setPlainText(QString("GAME OVER!"));
                      game->life->setFont(QFont("lucida",45));
                      game->life->setDefaultTextColor(Qt::red);
                      game->life->setPos(200,250);
                  }
                 // remove asteroide que colidiu
                 scene()->removeItem(this);
                 delete this;
                 return;
             }
         }
 }
