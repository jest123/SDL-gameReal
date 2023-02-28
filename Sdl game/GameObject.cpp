#include "GameObject.hpp"
#include "TextureManager.hpp"
using namespace std;

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
}
void GameObject::checkCollisions(GameObject *arrays[][20],GameObject *self, bool *moveRight,bool *moveLeft, bool *moveUp, bool *moveDown){
    *moveRight=true;
    *moveDown=true;
    *moveUp=true;
    *moveLeft=true;
    for(int j=0;j<3;j++)
    for(int i=0;i<20;i++){
        if(arrays[j][i]==NULL)
            return;
        if((self->destRect.x+(self->srcRect.w))==(arrays[j][i]->destRect.x-(arrays[j][i]->srcRect.w/2))&&((self->destRect.y)<=(arrays[j][i]->destRect.y+(arrays[j][i]->srcRect.h))&&(self->destRect.y)>=(arrays[j][i]->destRect.y-2*(arrays[j][i]->srcRect.h)))){
            *moveRight=false;
            cout<<(self->destRect.x)<<"       "<<(arrays[j][i]->destRect.x)<<endl;
        }
        if((self->destRect.x-(self->srcRect.w))==(arrays[j][i]->destRect.x+(arrays[j][i]->srcRect.w/2))&&((self->destRect.y)<=(arrays[j][i]->destRect.y+(arrays[j][i]->srcRect.h))&&(self->destRect.y)>=(arrays[j][i]->destRect.y-2*(arrays[j][i]->srcRect.h)))){
            *moveLeft=false;
            cout<<(self->destRect.x)<<"       "<<(arrays[j][i]->destRect.x)<<endl;
        }
        if((self->destRect.y-(self->srcRect.h))==(arrays[j][i]->destRect.y+(arrays[j][i]->srcRect.h/2))&&((self->destRect.x-(self->srcRect.w/2))<=(arrays[j][i]->destRect.x+(arrays[j][i]->srcRect.w))&&(self->destRect.x)>=(arrays[j][i]->destRect.x-2*(arrays[j][i]->srcRect.w))))
            *moveUp=false;
        if((self->destRect.y+(self->srcRect.h))==(arrays[j][i]->destRect.y-(arrays[j][i]->srcRect.h/2))&&((self->destRect.x)<=(arrays[j][i]->destRect.x+(arrays[j][i]->srcRect.w))&&(self->destRect.x)>=(arrays[j][i]->destRect.x-2*(arrays[j][i]->srcRect.w))))
            *moveDown=false;     
    }
}