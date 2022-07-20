#include "button.h"

button::button(){
    if (TTF_Init() != 0)
    {
        SDL_Quit();
    }
    font = TTF_OpenFont("Cavorting.ttf", 40);
    rect.h=50;
    rect.w=150;
    rect.x=760;
    rect.y=700;
    flag=0;
    hidden=0;
}

button::~button(){
    TTF_CloseFont(font);
}

void button::Print(SDL_Renderer* renderer, bool display){
    int texW = 3;
    int texH = 3;
    SDL_Color color;

    color = { 45, 69, 46 };
    if(hidden){
        SDL_SetRenderDrawColor(renderer, 247, 232, 143, 180);
        color = { 30, 71, 32 };
    }
    else if(flag) SDL_SetRenderDrawColor(renderer, 247, 140, 25, 180);
         else SDL_SetRenderDrawColor(renderer, 247, 160, 25, 180);
    if(display){
        SDL_RenderFillRect(renderer, &rect);
        SDL_Surface* surface = TTF_RenderUTF8_Blended (font, name.c_str(), color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
        SDL_Rect dstrect = { rect.x+rect.w/2-surface->w/2, rect.y+rect.h/2-surface->h/2, texW, texH };
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }else{
        SDL_RenderFillRect(renderer, &rect);
    }
}

void button::Set_Position(int x, int y, int w, int h){
    rect.h=h;
    rect.w=w;
    rect.x=x;
    rect.y=y;
}

void button::Set_Name(std::string str){
    name=str;
}
