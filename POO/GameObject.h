#pragma once
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2D.h"
#include "Map.h"
#include "Collider.h"
#include <string>
class GameObject
{
public:
    GameObject(std::string FLName);
    GameObject(std::string FLName, int x, int y);
    ~GameObject();
    void Update();
    void Get_Input1(const SDL_Event& event);
    void Get_Input2(const SDL_Event& event);
    void Render();
    Vector2D Get_Pos() { return pos; }
    friend std::istream& operator>>(std::istream& input, GameObject* Player);
private:
    Vector2D pos;
    Vector2D velocity;
    const int speed = 3;
    bool aKey, sKey, dKey, wKey;
    SDL_KeyCode up, down, left, right;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};

