#ifndef TEXT_H
#define TEXT_H

#include "SDL_ttf.h"
#include "SDL.h"
#include<iostream>
#include<string>

class text{
    public:
        TTF_Font* font;                        ///�����
        bool flag;                             ///���� ����������� ������
        std::string str;                       ///�����
        int x,y;                               ///���������� ������

        void Print(SDL_Renderer* renderer);    ///����� ������ �� �����
        void Set_Pos(int, int);                ///��������� ��������� ������
        void Set_Text(std::string);            ///���������� ������
        text();
        ~text();
};

#endif // TEXT_H
