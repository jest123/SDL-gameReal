#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
//#include "TextureManager.hpp"
using namespace std;

class Game{
    public:
        Game();
        ~Game();

        void init(const char *title, int x, int y, int width, int height, Uint32 flags);
        void handleEvents();
        void update();
        void render();
        void clean();
        
        bool running(){
            return isRunning;
        }
        static SDL_Renderer *renderer;

    private:
        bool isRunning;
        SDL_Window *window;
};

#endif