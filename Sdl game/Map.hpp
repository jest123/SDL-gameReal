#pragma once

#include "game.hpp"

class Map{
    public:
        Map();
        ~Map();
        void LoadMap(int arr[20][25]);
        void DrawMap(int xoffset, int yoffset,int tileSize);
        int map[20][25];
    private:
        SDL_Rect src,dest;
        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;

        
};