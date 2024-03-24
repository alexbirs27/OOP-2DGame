#include "GameObject.h"
#include "TextureManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Collider.h"
#include <fstream>
GameObject::GameObject(std::string FLName, int x, int y)
{
    objTexture = TextureManager::LoadTexture(FLName.c_str());
    aKey = sKey = dKey = wKey = 0;
    //wPress = SDLK_w;
    pos = Vector2D(x, y);
    velocity = Vector2D(0,0);

}
GameObject::GameObject(std::string FLName)
{
    objTexture = TextureManager::LoadTexture(FLName.c_str());
    aKey = sKey = dKey = wKey = 0;
    velocity = Vector2D(0, 0);
    pos = Vector2D(0, 0);
}
GameObject:: ~GameObject() 
{ 
    SDL_DestroyTexture(objTexture);
}

void GameObject::Update()
{
    velocity.SetX(dKey-aKey);
    Vector2D XX = velocity;
    Vector2D YY = Vector2D(velocity);
    std::cout << velocity;
    velocity.SetY(sKey - wKey);
    pos += velocity * Vector2D(speed,speed);
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.h = 32;
    srcRect.w = 32;
    destRect.h = 32;
    destRect.w = 32;
    destRect.x = pos.GetX();
    destRect.y = pos.GetY();
}

void GameObject::Get_Input1(const SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_w )//&& Collider::collision_up(destRect, map)==false)
            wKey = 1;
        if (event.key.keysym.sym == SDLK_s )//&& Collider::collision_down(destRect, map) == false)
            sKey = 1;
        if (event.key.keysym.sym == SDLK_d )//&& Collider::collision_right(destRect, map) == false)
            dKey = 1;
        if (event.key.keysym.sym == SDLK_a )//&& Collider::collision_left(destRect, map) == false)
            aKey = 1;
    }
    if (event.type == SDL_KEYUP)
    {
        if (event.key.keysym.sym == SDLK_w)
            wKey = 0;
        if (event.key.keysym.sym == SDLK_s)
            sKey = 0;
        if (event.key.keysym.sym == SDLK_d)
            dKey = 0;
        if (event.key.keysym.sym == SDLK_a)
            aKey = 0;
    }
}

void GameObject::Get_Input2(const SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_DOWN)
            sKey = 1;
        if (event.key.keysym.sym == SDLK_UP)
            wKey = 1;
        if (event.key.keysym.sym == SDLK_LEFT)
            aKey = 1;
        if (event.key.keysym.sym == SDLK_RIGHT)
            dKey = 1;
    }
    if (event.type == SDL_KEYUP)
    {
        if (event.key.keysym.sym == SDLK_DOWN)
            sKey = 0;
        if (event.key.keysym.sym == SDLK_UP)
            wKey = 0;
        if (event.key.keysym.sym == SDLK_LEFT)
            aKey = 0;
        if (event.key.keysym.sym == SDLK_RIGHT)
            dKey = 0;
    }
}



void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}