/*
    Funções do Nível
*/

#include "level.h"
#include <QFont>

Level::Level(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // nivel começa em 1
   this->level= 1;
    setPos(10,100);
    // desenhar o texto
    setPlainText(QString("Level: ") + QString::number(this->level));
   setDefaultTextColor(Qt::green);
    setFont(QFont("lucida",16));
}
// aumenta nível
void Level::increase(){
    this->level++;
    setPlainText(QString("Level: ") + QString::number(this->level)); // Score: 1
}
// retorna nível
int Level::getLevel(){
    return this->level;
}
