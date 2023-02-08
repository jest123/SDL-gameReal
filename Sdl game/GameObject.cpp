#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet,  int x, int y){
    objTexture=TextureManager::LoadTexture(textureSheet);
    destRect.x=x;
    destRect.y=y;

}
void GameObject::Update(int x,int y){
    srcRect.h= 32;
    srcRect.w=32;
    srcRect.x=0;
    srcRect.y=0;
    if(x!=NULL)
        destRect.x=x;
    if(y!=NULL)
        destRect.y=y;
    destRect.w=srcRect.w*2;
    destRect.h=srcRect.h*2;
}
void GameObject::Render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}