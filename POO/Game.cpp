#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Map.h"
#include "Collider.h"
GameObject* GolfBall;
GameObject* Golf1;
Map* map;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Game::Game() {}


Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    cnt = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialised!.." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window)
        {
            std::cout << "Window Created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created!" << std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
    //   BackGroundImage = new GameObject("image.jpg", renderer);


   // BackGroundImage = TextureManager::LoadTexture("image.jpg");
    GolfBall = new GameObject("minge_golf.png", 32, 32);
    Golf1 = new GameObject("minge_golf.png", 0, 600);
    map = new Map();

    /*  GolfBall = TextureManager::LoadTexture("minge_golf.png", renderer);
      SDL_Surface* tmpSurface = IMG_Load("image.jpg");
      BackGroundImage = SDL_CreateTextureFromSurface(renderer, tmpSurface);
      tmpSurface = IMG_Load("minge_golf.png");
      GolfBall = SDL_CreateTextureFromSurface(renderer, tmpSurface);
      SDL_FreeSurface(tmpSurface); */
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
    GolfBall->Get_Input1(event,*map);
    Golf1->Get_Input2(event);
    GolfBall->Update();
    Golf1->Update();
  //  std::cout << "1";
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
  //  SDL_RenderCopy(renderer, BackGroundImage, NULL, NULL);
    GolfBall->Render();
    Golf1->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}
bool Game::running()
{
    return isRunning;
}