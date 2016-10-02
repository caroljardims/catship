/*
    Funções da Pontuação
*/

#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // jogo inicia com 0 pontos
   this->score = 0;
    this->extraLife = 1;
    this->nextLevel = 1;
    setPos(10,70);
    // desenhar o texto
    setPlainText(QString("Score: ") + QString::number(this->score));
   setDefaultTextColor(Qt::green);
    setFont(QFont("lucida",16));
}
// aumenta pontos
void Score::increase(){
    this->score++;
    setPlainText(QString("Score: ") + QString::number(this->score));
}
// retorna pontos
int Score::getScore(){
    return this->score;
}
// variavel que decide se ganha vida extra
int Score::getExtraLife(){
    return this->extraLife;
}
// variavel que decide se passa de nível
int Score::getNextLevel(){
    return this->nextLevel;
}
// retorna vida extra
void Score::increaseExtraLife(){
    this->extraLife++;
}
// retorna próxima fase
void Score::increaseNextLevel(){
    this->nextLevel++;
}
