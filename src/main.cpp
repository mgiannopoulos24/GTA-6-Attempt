#include "Game.h"
#include <iostream>

int main() {
    std::cout << "Why did I come here? I guess it was the weather." << std::endl;
    Game game;
    game.start();
    for (int i = 0; i < 10; ++i) {  
        game.update();
    }
    game.end();
    return 0;
}
