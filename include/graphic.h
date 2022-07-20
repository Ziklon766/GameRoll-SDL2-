#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <iostream>
#include <SDL.h>
#include <vector>
#include "button.h"
#include "drum.h"
#include "Text.h"

class graphic{
    public:
        graphic();
        virtual ~graphic();

        SDL_Texture* texture;
        SDL_Surface* surface;
        std::vector<drum> drums;
        std::vector<SDL_Surface*> pictures;
        button btnStart, btnStop, btnCont;           //кнопки
        text info;                          //текст

        //отрисовка барабанов
        void draw_idle(SDL_Renderer*);         //статичных
        void draw_spin(SDL_Renderer*);         //вращение
        void draw_stop(SDL_Renderer*);         //остановка и показ результата

        void draw_slot(SDL_Renderer*);          //отрисовка автомата и текста
        void draw_btns(SDL_Renderer*);          //отрисовка кнопок
};

#endif // GRAPHIC_H
