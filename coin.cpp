/*
    Funções da Moeda
*/

#include "coin.h"
#include "game.h"
#define PI 3.14159265359

extern Game * game;

Coin::Coin(){

    // circunferencia da moeda
    this->food.addEllipse(0,0,20,20);

    setBrush(QBrush(Qt::darkRed, Qt::SolidPattern));
    setPen(QPen(Qt::yellow, 2, Qt::DashDotLine, Qt::RoundCap));
    setPath(this->food);

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
            timer->start(50);
}

// movimento da moeda (subida)
 void Coin::move(){
     setPos(x(),y()-1);
     if((y() < 0 || y() > 600) &&(x() < 0 || x() > 800)){
         scene()->removeItem(this);
         delete this;
     }

     // lista de objetos que colidem
     QList<QGraphicsItem *> colliding_items = collidingItems();
         for (int i = 0, n = colliding_items.size(); i < n; ++i){
             if (typeid(*(colliding_items[i])) == typeid(Ship)){
                 // soma 5 pontos no score do jogador
                  for(int i=0;i<5;i++){
                      game->score->increase();
                  }
                  // quando soma 30 pontos no score, aumenta uma vida
                  if(game->score->getScore() >= game->score->getExtraLife()*30){
                      game->life->increase();
                      game->score->increaseExtraLife();
                  }
                  // se chegar a 100 pontos no score, passa de fase
                  if(game->score->getScore() >= 100*game->score->getNextLevel()){
                      game->level->increase();
                      game->score->increaseNextLevel();
                      // muda background da fase
                      if(game->score->getNextLevel() == 2)
                          game->setBackgroundBrush(QBrush(QImage(":/img/img/desert.jpg")));
                      else if(game->score->getNextLevel() == 3)
                          game->setBackgroundBrush(QBrush(QImage(":/img/img/water.jpg")));
                      else if(game->score->getNextLevel() == 4)
                          game->setBackgroundBrush(QBrush(QImage(":/img/img/wood.jpg")));
                      else if(game->score->getNextLevel() == 5)
                          game->setBackgroundBrush(QBrush(QImage(":/img/img/fire.png")));
                      else if(game->score->getNextLevel() >= 6){
                          game->setBackgroundBrush(QBrush(QImage(":/img/img/gold.jpg")));
                          game->life->setPlainText("YOU WIN!");
                          game->life->setFont(QFont("lucida",45));
                          game->life->setDefaultTextColor(Qt::black);
                          game->life->setPos(200,250);
                          scene()->removeItem(game->score);
                          scene()->removeItem(game->level);
                      }
                  }
                 // remove moeda que colidiu
                 scene()->removeItem(this);
                 delete this;
                 return;
             }
         }
 }
