/*#pragma once
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Map.h"

class Collider
{
public:
	SDL_Rect collider;
	Vector2D* Pos;
	Vector2D prevPos;
	Collider(GameObject* player);
	void update()
	{
		prevPos = Vector2D(Pos->GetX(), Pos->GetY());
		collider.x = Pos->GetX();
		collider.y = Pos->GetY();
	}
	static bool collision_up(const SDL_Rect& A, Map map)
	{
		float i = (A.x / 32);
		float j = (A.x / 32);
		if (map.GetVal(i, j) == 2)
			return true;
		return false;
	}
	static bool collision_down(const SDL_Rect& A, Map map)
	{
		float i = A.x / 32+1;
		float j = A.x / 32;
		if (map.GetVal(i, j) == 2)
			return true;
		return false;
	}
	static bool collision_left(const SDL_Rect& A, Map map)
	{
		float i = A.x / 32;
		float j = A.x / 32;
		if (map.GetVal(i, j) == 2)
			return true;
		return false;
	}
	static bool collision_right(const SDL_Rect& A, Map map)
	{
		float i = A.x / 32;
		float j = A.x / 32+1;
		if (map.GetVal(i, j) == 2)
			return true;
		return false;
	}
};
*/
