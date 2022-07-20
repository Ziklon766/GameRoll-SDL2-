#ifndef BUTTON_H
#define BUTTON_H

#include "SDL_ttf.h"
#include<SDL.h>
#include<string>

class button{
    public:
        bool flag;          ///���� ���������/������� �� ������
        bool hidden;
        SDL_Rect rect;      ///�������������, ������� ���������� ������ �� ������
        TTF_Font *font;     ///����� ������������ ��� ������ �� ������
        std::string name;   ///�������� ������

        button();
        virtual ~button();
        void Print(SDL_Renderer*, bool);        ///����� ������ �� �����
        void Set_Position(int, int, int, int);  ///��������� �������� � ������� ������
        void Set_Name(std::string);             ///��������� �������� ������
};

#endif // BUTTON_H
