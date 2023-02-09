#pragma once
#include "game.hpp"
class GameObject{
    public:
        GameObject(const char* texturesheet, int x, int y,int type);
        //~GameObject();

        void Update(int,int,int,int xoffset, int yoffset);
        void Render();
        void checkCollisions(GameObject*);
    private:
        int  xpos;
        int  ypos;
        int type; //0=player,1=enemy,2=friendly,3=others,4=arene
        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
};