#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include <SDL.h>
#include <ctime>
#include "button.h"
#include "graphic.h"
#include "timer.h"
#include "Text.h"

///������������ ����� ������ ���������
class StateMachine
{
    protected:
        char type;              //��� ������ ��� ���������
    public:
        StateMachine();
        virtual ~StateMachine();

        char getState();                     //�������� ������� ���������
        StateMachine* nextState;            //��������� �� ��������� ���������
        StateMachine* goNextState();        //������� � ��������� ���������
        void setNextState(StateMachine*);   //��������� ���������� ���������

        SDL_Event event;            //�������

        virtual bool run(SDL_Renderer *renderer, graphic& graphic) = 0;
};

///����� ��������� ��������
class IdleState : public StateMachine
{
    public:
        IdleState();
        ~IdleState();
        bool run(SDL_Renderer *renderer, graphic& graphic) override;
};

///����� ��������� �������� ���������
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

///����� ��������� ����������� ��������
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
