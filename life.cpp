/*
    Funções da Vida
*/

#include "life.h"
#include <QFont>

Life::Life(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // jogo inicia com 7 vidas
   this->life= 7;
    setPos(10,40);
    // desenhar o texto
    setPlainText(QString("Lifes: ") + QString::number(this->life));
   setDefaultTextColor(Qt::green);
    setFont(QFont("lucida",16));
}
// diminui vida
void Life::decrease(){
    this->life--;
    setPlainText(QString("Lifes: ") + QString::number(this->life)); // Score: 1
}
// aumenta vida
void Life::increase(){
    this->life++;
    setPlainText(QString("Lifes: ") + QString::number(this->life)); // Score: 1
}
// retorna vida
int Life::getLife(){
    return this->life;
}
