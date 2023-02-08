#include <SDL2/SDL_image.h>
#include "game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

GameObject* player;
Map* map;
SDL_Texture* playerTex;
SDL_Rect srcR, destR;
SDL_Renderer* Game::renderer=nullptr;
int count,playerx, playery;
Game::Game(){

}

Game::~Game(){

}



void Game::init(const char *title, int x, int y, int width, int height, Uint32 flags){

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        isRunning = false;
        cout<<"Neki ne dela tko k more:/"<<endl;
        cout<<"napaka: "<< SDL_GetError()<<endl;
    }
    else {
        cout<<"Zaenkat use dela tko k more:)"<<endl;

        window = SDL_CreateWindow(title, x, y, width, height, flags);
        if (window){
            cout<<"Okno ustvarjeno"<<endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            cout<<"Renderer ustvarjen"<<endl;
        }
        player=new GameObject("assets/player.png",400,400);
        map= new Map();
        destR.w=64;
        destR.h=64;
        isRunning = true;
    }
}

void Game::handleEvents(){
    SDL_Event event;
    const Uint8* keyboard = SDL_GetKeyboardState(NULL);
    if(keyboard[SDL_SCANCODE_W]){
        playery -= 1;}
    if(keyboard[SDL_SCANCODE_A])
        playerx -= 1;
    if(keyboard[SDL_SCANCODE_S])
        playery += 1;
    if(keyboard[SDL_SCANCODE_D])
        playerx += 1;
    SDL_PollEvent(&event);
    switch (event.type){
        /*case SDL_KEYDOWN:
        switch( event.key.keysym.sym ){
                    case SDLK_LEFT:
                        playerx -= 1;
                        break;
                    case SDLK_RIGHT:
                        playerx += 1;
                        break;
                    case SDLK_UP:
                        playery -= 1;
                        break;
                    case SDLK_DOWN:
                        playery += 1;
                        break;
                    default:
                        break;
                }
            break;*/
        case SDL_QUIT:
            isRunning = false;
            break;

        
    }
}

void Game::update(){
    player->Update(0,0);
}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    map->DrawMap(-playerx,-playery,64);
    player->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout<<"Pocistu use!"<<endl;
}