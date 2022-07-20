#include "text.h"

#include "SDL_ttf.h"

text::text(){
    if (TTF_Init() != 0)
    {
        SDL_Quit();
    }
    font = TTF_OpenFont("Cavorting.ttf", 40);
    x=415;
    y=60;
};

text::~text(){
    TTF_CloseFont(font);
    TTF_Quit();
};

void text::Print(SDL_Renderer* renderer){
    int texW = 300;
    int texH = 60;
    SDL_Color color = { 247, 214, 25 };
    SDL_Surface* surface = TTF_RenderUTF8_Blended (font, str.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { x-surface->w/2 , y-surface->h/2, texW, texH };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);


}

void text::Set_Pos(int center_X, int center_Y){
   x = center_X;
   y = center_Y;
}

void text::Set_Text(std::string temp){
   str = temp;
}


