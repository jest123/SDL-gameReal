#pragma once
#include "game.hpp"
class GameObject{
    public:
        GameObject(const char* texturesheet, int x, int y);
        ~GameObject();

        void Update(int,int,int);
        void Render();
        void checkTileCollisions(int map[][25],int tileSize);
    private:
        int  xpos;
        int  ypos;
        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
};