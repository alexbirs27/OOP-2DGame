#pragma once
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2D.h"
#include "Map.h"
#include "Collider.h"
Map map;
class GameObject
{
public:
    GameObject(const char* FLName, int x, int y);
    ~GameObject();
    void Update();
    void Get_Input1(const SDL_Event& event, const Map& map);
    void Get_Input2(const SDL_Event& event);
    void Render();
private:
    Vector2D pos;
    Vector2D velocity;
    int speed = 3;
    bool aKey, sKey, dKey, wKey;
    SDL_KeyCode up, down, left, right;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};

