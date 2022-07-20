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
        button btnStart, btnStop, btnCont;           //������
        text info;                          //�����

        //��������� ���������
        void draw_idle(SDL_Renderer*);         //���������
        void draw_spin(SDL_Renderer*);         //��������
        void draw_stop(SDL_Renderer*);         //��������� � ����� ����������

        void draw_slot(SDL_Renderer*);          //��������� �������� � ������
        void draw_btns(SDL_Renderer*);          //��������� ������
};

#endif // GRAPHIC_H
