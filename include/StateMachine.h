#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include <SDL.h>
#include <ctime>
#include "button.h"
#include "graphic.h"
#include "timer.h"
#include "Text.h"

///асбстрактный класс машины состояний
class StateMachine
{
    protected:
        char type;              //тут храним тип состояния
    public:
        StateMachine();
        virtual ~StateMachine();

        char getState();                     //получить текущее состояние
        StateMachine* nextState;            //указатель на следующее состояние
        StateMachine* goNextState();        //переход в следующее состояние
        void setNextState(StateMachine*);   //установка следующего состояния

        SDL_Event event;            //событие

        virtual bool run(SDL_Renderer *renderer, graphic& graphic) = 0;
};

///класс состояния ожидания
class IdleState : public StateMachine
{
    public:
        IdleState();
        ~IdleState();
        bool run(SDL_Renderer *renderer, graphic& graphic) override;
};

///класс состояния вращения барабанов
class SpinState : public StateMachine
{
    public:
        SpinState();
        ~SpinState();
        StateMachine* nextState;
        bool run(SDL_Renderer *renderer, graphic& graphic) override;
    private:
        timer spin_time;
};

///класс состояния отображения выйгрыша
class ResState : public StateMachine
{
    public:
        ResState();
        ~ResState();
        StateMachine* nextState;
        bool run(SDL_Renderer *renderer, graphic& graphic) override;
    private:
        int result;
};

#endif // STATEMACHINE_H
