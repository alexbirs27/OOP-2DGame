#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include "TextureManager.h"
class GameObject;
class Game
{
public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running();
    static SDL_Event event;
    static SDL_Renderer* renderer;
private:
    SDL_Texture* BackGroundImage;
    GameObject* GolfBall;
    GameObject* Golf1;
    int cnt;
    bool isRunning;
    SDL_Window* window;
};

