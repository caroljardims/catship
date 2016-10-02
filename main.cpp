/*
    INSTRUÇÕES:
    > Key Up (seta para cima): acelera e aumenta aceleração da nave
    > Key Down (seta para baixo): frea nave
    > Key Right (seta para direita): rotaciona nave para a direita
    > Key Left (seta para a esquerda): rotaciona nave para a esquerda
    > Key Space (barra de espaço): lança hariballs

    OBJETIVO DO JOGO:
    > Chegar na última fase e vencer.

    FUNCIONAMENTO DO JOGO:
    > catship inicia o jogo na fase 1, com 7 vidas e 0 pontos
    > ao acertar hairballs em flowers, catship ganha 1 ponto
    > ao capturar food, catship ganha 5 pontos
    > a cada 30 pontos, catship ganha uma vida
    > a cada 100 pontos, cartship passa de fase
    > a cada nível se a catship colidir com uma flower, ela perde o número da fase por número de vidas
        (fase 1, perde 1 vida; fase 2, perde 2 vidas)
    > se zerar as vidas, game over
*/

#include <QApplication>
#include "game.h"

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // começar o jogo
    game = new Game();
    game->show();

    return a.exec();
}
