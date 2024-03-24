#include "Map.h"
#include "TextureManager.h"
#include <iostream>
#include <cstdlib>
#include <queue>
#include <random>
#include <ctime>
int lvl1[40][50];
Map::Map(){
	wall = TextureManager::LoadTexture("brick.png");
	grass = TextureManager::LoadTexture("grass1.png");
	water = TextureManager::LoadTexture("water.png");

    FillMap();
    LoadMap(lvl1);

    src.x = src.y = 0;
    src.w = src.h = 32;
    dest.w = dest.h = 32;

    dest.x = dest.y = 0;
}
Map::~Map()
{
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
    SDL_DestroyTexture(wall);
}

void Map::FillMap() {
    // Implementăm o logică pentru a completa matricea
    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j < 50; ++j) {
            lvl1[i][j] = 1;
        }
    }
    for (int i = 0; i < 40; i++)
        lvl1[i][0] = lvl1[i][49] = 0;
    for (int j = 0; j < 50; j++)
        lvl1[0][j] = lvl1[39][j] = 0;
    int n = 38;
    int m = 48;
    int viz[40][50];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            viz[i][j] = 0;
    srand(time(nullptr));
    int x = 1, y = 1;
    viz[2][2] = true;
    int dx[2] = { 0,1 }, dy[2] = { 1,0 };
    int nr = 100;
    while (x != n || y != m)
    {
        int t = rand() % 2;
        std::cout << x << " " << y << '\n';
        if (lvl1[x + dx[t]][y + dy[t]] != 0)
        {
            x = x + dx[t];
            y = y + dy[t];
        }
        viz[x][y] = true;
    }
 /*   std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, n * m - 1); */
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
             if(viz[i][j]==0)
                 lvl1[i][j] = rand() % 2 + 1;

    ///bordez matricea cu vid adica cu 0(water)
    ///inca un rand de bordare cu 2(care este wall)
    /// in rest pun 1(iarba)
    
}
void Map::LoadMap(int arr[40][50]) {
    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 50; j++)
            map[i][j] = arr[i][j];
}

void Map::DrawMap()
{
    int tip = 0;
    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 50; j++)
        {
            tip = map[i][j];
            dest.x = j * 32;
            dest.y = i * 32;
            if(tip==0)
                TextureManager::Draw(water, src, dest);
            else
            if(tip==1)
                TextureManager::Draw(grass, src, dest);
            else
                TextureManager::Draw(wall, src, dest);
        }
}