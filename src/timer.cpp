#include "timer.h"

timer::timer()
{
    //ctor
}

timer::~timer()
{
    //dtor
}

void timer::Reset(){
    lasttime = SDL_GetTicks();
}

int timer::GetTimer(){
    return SDL_GetTicks()-lasttime;
}
