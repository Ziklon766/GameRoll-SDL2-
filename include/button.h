#ifndef BUTTON_H
#define BUTTON_H

#include "SDL_ttf.h"
#include<SDL.h>
#include<string>

class button{
    public:
        bool flag;          ///флаг наведения/нажатия на кнопку
        bool hidden;
        SDL_Rect rect;      ///прямоугольник, который обозначает кнопку на экране
        TTF_Font *font;     ///шрифт используемый для текста на кнопке
        std::string name;   ///название кнопки

        button();
        virtual ~button();
        void Print(SDL_Renderer*, bool);        ///вывод кнопки на экран
        void Set_Position(int, int, int, int);  ///установка размеров и позиции кнопки
        void Set_Name(std::string);             ///установка названия кнопки
};

#endif // BUTTON_H
