/*
    Funções do Tiro
*/

#include "shot.h"
#include "asteroid.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#define PI 3.14159265359

extern Game * game;

Shot::Shot(int r){
    this->r = r;
    // desenha quadrado  munição
    setRect(0,0,5,5);
    setPen(QPen(Qt::white, 2, Qt::DashDotLine, Qt::RoundCap));
    setBrush(QBrush(Qt::gray, Qt::SolidPattern));
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
            timer->start(20);
}
// movimento do tiro de acordo com a rotação da nave
void Shot::move(){
    double seno, cosseno;
    seno = sin(this->r*PI/180);
    cosseno = cos(this->r*PI/180);
    if(r == 0)
        setPos(x(),y()-10);
    else
        setPos(x()+10*seno,y()-10*cosseno);

    // lista de objetos que colidem
    QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Asteroid)){
                // se o tiro acerta um asteroide, aumenta um ponto do score
                game->score->increase();
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
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                // deleta objetos
                delete colliding_items[i];
                delete this;
                return;
            }
        }

    if((pos().y() < 0 || pos().y() > 600) &&(pos().x() < 0 || pos().x() > 800)){
        scene()->removeItem(this);
        delete this;
    }
}
