#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Game.h"
#include <fstream>
/// <summary>
//nu stiam cum sa adaug citirea din fisier, am facut o clasa pentru dimensiunile ecranului
/// </summary>
Game* game = nullptr;
int main(int argc, char* argv[]) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;


   /* std::ifstream f("date.in.txt");
    int x;
    f >> x;
    std::cout << x;
    if (!f.is_open())
        std::cout << "NUUUU";
    exit(0); */
    game = new Game();
    game->init("Mini_Golf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 1280, false);
    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();
    return 0;
}
