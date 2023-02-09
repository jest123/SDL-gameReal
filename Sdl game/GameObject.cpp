#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet,  int x, int y, int objectType){
    objTexture=TextureManager::LoadTexture(textureSheet);
    destRect.x=x;
    destRect.y=y;
    type=objectType;
}
void GameObject::Update(int x,int y,int size,int xoffset, int yoffset){
    srcRect.h= size;
    srcRect.w=size;
    srcRect.x=0;
    srcRect.y=0;
    if(x!=NULL)
        destRect.x=x+xoffset;
    if(y!=NULL)
        destRect.y=y+yoffset;
    destRect.w=srcRect.w*2;
    destRect.h=srcRect.h*2;
}
void GameObject::Render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
    cout<<"Rendered"<<endl;
}
void GameObject::checkCollisions(GameObject *start){
    
}