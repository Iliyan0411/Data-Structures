#include "Tests.h"



int main()
{
    doctest::Context().run(); // тестове

    Game game;
    game.run();	



    return 0;
}
