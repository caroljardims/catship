/*
    Header da Pontuação
*/

#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent=0);
    void increase();
    int getScore();
    int getExtraLife();
    int getNextLevel();
    void increaseExtraLife();
    void increaseNextLevel();
private:
    int score, extraLife, nextLevel;
};
#endif // SCORE_H
