#include <SDL2/SDL_image.h>
#include "game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include <iostream>
#include <stdlib.h>
#include<list> 

GameObject* player;
Map* map;
SDL_Texture* playerTex;
SDL_Rect srcR, destR;
SDL_Renderer* Game::renderer=nullptr;
int count,playerx=0, playery=0, windowY,windowX, zoom=64;
GameObject* arene[10];
GameObject* tmpGameObject;
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
        player=new GameObject("assets/player.png",(width/2)-48,(height/2)-48,0);
        tmpGameObject= new GameObject("assets/arena.png",0,0,0);
        arene[0]=new GameObject("assets/arena.png",40,60,4);
        arene[1]=new GameObject("assets/arena.png",150,160,4);
        map= new Map();
        destR.w=64;
        destR.h=64;
        windowY=height;
        windowX=width;
        isRunning = true;
    }
}

void Game::handleEvents(){
    SDL_Event event;
    const Uint8* keyboard = SDL_GetKeyboardState(NULL);
    if(keyboard[SDL_SCANCODE_W]&&playery!=(-windowY/2)+32){
        playery -= 1;}
    if(keyboard[SDL_SCANCODE_A]&&playerx!=(-windowX/2)+32)
        playerx -= 1;
    if(keyboard[SDL_SCANCODE_S]&&playery!=(((sizeof(map->map)/sizeof(map->map[0]))*zoom)-windowY/2)-16)
        playery += 1;
    if(keyboard[SDL_SCANCODE_D]&&playerx!=((sizeof(map->map[0])/sizeof(map->map[0][0])*zoom)-windowX/2)-16)
        playerx += 1;
    if(keyboard[SDL_SCANCODE_KP_PLUS])
        zoom++;
    if(keyboard[SDL_SCANCODE_KP_MINUS])
        zoom--;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        
    }
}

void Game::update(){
    player->Update(0,0,zoom,0,0);
    tmpGameObject->Update(1,1,zoom,-playerx,-playery);
    arene[0]->Update(300,1,zoom,-playerx,-playery);
    arene[1]->Update(1,400,zoom,-playerx,-playery);
}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    map->DrawMap(-playerx,-playery,zoom);
    cout<<"Rendering player: ";
    player->Render();
    cout<<"Rendering tmp: ";
    tmpGameObject->Render();
    arene[0]->Render();
    cout<<"arena 0 ustvarjena"<<endl;
    arene[1]->Render();
    cout<<"arena 1 ustvarjena"<<endl;
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout<<"Pocistu use!"<<endl;
}