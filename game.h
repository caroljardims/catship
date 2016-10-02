#ifndef GAME_H
/*
    Header do Jogo
*/

#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ship.h"
#include "shot.h"
#include "asteroid.h"
#include "life.h"
#include "score.h"
#include "level.h"

class Game: public QGraphicsView{
public:
    Game();
    QGraphicsScene *scene;
    Ship *catship;
    Life *life;
    Score *score;
    Level *level;
};

#endif // GAME_H
