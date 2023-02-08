#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

const int WIDTH = 800, HEIGHT = 600;

int main( int argc, char *argv[] ){
    
    SDL_Window *window;


    if (SDL_Init(SDL_INIT_VIDEO) > 0){
        cout<<"napaka: "<< SDL_GetError()<<endl;
    }
    else {
        cout<<"SDL dela"<<endl;
    }


    window = SDL_CreateWindow("Resevanje bikca ferdinanda", 500, 200, 640, 480, SDL_WINDOW_SHOWN); //ime okna, x koordinata, y koordinata, sirina, dolzina, flag


    bool igraSeIzvaja = true;
    while (igraSeIzvaja){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){  //ce zelimo ugasniti igrico se neskoncna zanka prekine
                igraSeIzvaja = false;
            }

            if (event.type == SDL_MOUSEMOTION){
                cout<<"Miska se je premaknila"<<endl;
            }

            if (event.type == SDL_KEYDOWN){
                cout<<"Tipka je bila pritisnjena"<<endl; 
                if(event.key.keysym.sym == SDLK_0){   //keycodes: https://wiki.libsdl.org/SDL2/SDL_Keycode
                    cout<<"Pritisnjena je bila 0"<<endl;
                }
                else {
                    cout<<"0 ni bila pritisnjena"<<endl;
                }
            }
        }
    }
    
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}