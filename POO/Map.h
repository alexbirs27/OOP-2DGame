#pragma once
#include "Game.h"
class Map
{
public:
	Map();
	~Map();
	void FillMap();
	void LoadMap(int arr[40][50]);
	void DrawMap();
	int getMatrice() const {
		return map[40][50];
	}
	int GetVal(int x, int y) const { return map[x][y]; }
private:
	SDL_Rect src, dest;
	SDL_Texture* wall;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[40][50];

};

