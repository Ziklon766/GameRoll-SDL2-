#ifndef TIMER_H
#define TIMER_H

#include<SDL.h>

class timer{
    public:
        timer();
        virtual ~timer();
        unsigned int lasttime;

        void Reset();       ///���������� �������
        int GetTimer();     ///�������� ������� � ������ ������
};

#endif // TIMER_H
