#ifndef TEXT_H
#define TEXT_H

#include "SDL_ttf.h"
#include "SDL.h"
#include<iostream>
#include<string>

class text{
    public:
        TTF_Font* font;                        ///шрифт
        bool flag;                             ///флаг отображения текста
        std::string str;                       ///текст
        int x,y;                               ///координаты текста

        void Print(SDL_Renderer* renderer);    ///вывод текста на экран
        void Set_Pos(int, int);                ///установка координат центра
        void Set_Text(std::string);            ///назначение текста
        text();
        ~text();
};

#endif // TEXT_H
