#include <SDL2/SDL_image.h>
#include "game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include <iostream>
#include <stdlib.h>
#include<list> 
//ROK :)
GameObject* player;
Map* map;
SDL_Texture* playerTex;
SDL_Rect srcR, destR;
SDL_Renderer* Game::renderer=nullptr;
int count,playerx=0, playery=0, windowY,windowX, zoom=64;
GameObject* arrayi[3][20];
GameObject* tmpGameObject;
bool moveUp=1,moveDown=1,moveRight=1,moveLeft=1;
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
        //tmpGameObject= new GameObject("assets/arena.png",0,0,0);
        arrayi[0][0]=new GameObject("assets/arena.png",40,60,4);
        arrayi[0][1]=new GameObject("assets/arena.png",150,160,4);
        arrayi[0][2]=NULL;
        arrayi[1][0]=NULL;
        arrayi[2][0]=NULL;

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
    if(keyboard[SDL_SCANCODE_W]&&playery!=((-windowY/2)+32)&&moveUp){
        playery -= 1;}
    if(keyboard[SDL_SCANCODE_A]&&playerx!=((-windowX/2)+32)&&moveLeft)
        playerx -= 1;
    if(keyboard[SDL_SCANCODE_S]&&playery!=(((sizeof(map->map)/(sizeof(map->map[0]))*zoom)-windowY/2)-16)&&moveDown)
        playery += 1;
    if(keyboard[SDL_SCANCODE_D]&&playerx!=(((sizeof(map->map[0])/sizeof(map->map[0][0])*zoom)-windowX/2)-16)&&moveRight)
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
    //tmpGameObject->Update(1,1,zoom,-playerx,-playery);
    for(int i=0;i<20;i++)
    arrayi[0][0]->Update(300,1,zoom,-playerx,-playery);
    arrayi[0][1]->Update(1,400,zoom,-playerx,-playery);
    player->checkCollisions(arrayi,player,&moveRight,&moveLeft,&moveUp,&moveDown);
}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    map->DrawMap(-playerx,-playery,zoom);
    //cout<<"Rendering player: ";
    player->Render();
    //cout<<"Rendering tmp: ";
    //tmpGameObject->Render();
    arrayi[0][0]->Render();
    //cout<<"arena 0 ustvarjena"<<endl;
    arrayi[0][1]->Render();
    //cout<<"arena 1 ustvarjena"<<endl;
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout<<"Pocistu use!"<<endl;
}
