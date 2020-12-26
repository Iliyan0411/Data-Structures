#include "Tests.h"


int PTree::indexCounter = 0;

int main()
{
    doctest::Context().run();

    Game game;
    game.run();	



    return 0;
}
