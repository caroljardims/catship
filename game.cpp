/*
    Funções do Jogo
*/

#include "game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>

Game::Game(){
    // cria tela e cena do jogo
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/img/img/universe.png")));

    // adiciona nave no jogo
    catship = new Ship();
    scene->addItem(catship);
    catship->setPos(400,300);
    catship->setFlag(QGraphicsItem::ItemIsFocusable);
    catship->setFocus();

    // cria vidas
    life= new Life();
    scene->addItem(life);

    // cria pontuação
    score = new Score();
    scene->addItem(score);

    // cria fase
    level = new Level();
    scene->addItem(level);

    if(score->getNextLevel() < 6){
        // cria asteroides
        QTimer * timer1 = new QTimer();
        QObject::connect(timer1,SIGNAL(timeout()),catship,SLOT(createAsteroid()));
        timer1->start(3000);

        // cria moedas
        QTimer * timer2 = new QTimer();
        QObject::connect(timer2,SIGNAL(timeout()),catship,SLOT(createCoin()));
        timer2->start(5000);
    }

    setScene(scene);
}


