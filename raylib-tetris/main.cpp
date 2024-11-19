#include "Game.h"
#include "Settings.h"

int main()
{
    Game game(settings::screenWidth,
                settings::screenHeight,
                settings::fps,
                "Tetris");
    
    while (!game.GameShouldContinue()) {
        game.Tick();
    }
    return 0;
}