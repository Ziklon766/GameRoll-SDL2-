#ifndef TIMER_H
#define TIMER_H

#include<SDL.h>

class timer{
    public:
        timer();
        virtual ~timer();
        unsigned int lasttime;

        void Reset();       ///обновление таймера
        int GetTimer();     ///значение таймера в данный момент
};

#endif // TIMER_H
