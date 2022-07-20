#include<iostream>
#include<SDL.h>
#include <ctime>
#include "StateMachine.h"
#include "text.h"
#include "button.h"

#define screen_w 1025
#define screen_h 530

using namespace std;

int main(int argc, char* argv[]){
    srand(time(NULL));

    SDL_Window *window;         //окно
    SDL_Renderer *renderer;     //поверхность ренедра

    //графика
    graphic graphic;
    //машина состояний
    StateMachine* currentState;
    IdleState state_idle;
    SpinState state_spin;
    ResState state_res;
    //устоновка следующих состояний
    state_idle.setNextState(&state_spin);
    state_spin.setNextState(&state_res);
    state_res.setNextState(&state_idle);
    //начальное состояние
    currentState = &state_idle;

    bool state;
    //инициализация видео
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)<0){
        cout<<"FAIL init SDL";
        return 1;
    }
    //создание окна
	window = SDL_CreateWindow("Симулятор автомата", 100, 100, screen_w, screen_h, SDL_WINDOW_OPENGL);
    //проверка создания окна
    if (window == nullptr)
    {
        std::cout << "Window could not be created! SDL Error: %s\n", SDL_GetError();
    }
	renderer = SDL_CreateRenderer(window, -1, 0);           //создание рендера
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);    //установка начального цвета
	SDL_RenderClear(renderer);                              //установка рендера
	SDL_RenderPresent(renderer);                            //устанвка обновления рендера
	//проверка создания рендера
	if (renderer == NULL)
	{
		std::cout << "Can't create renderer: " << SDL_GetError() << std::endl;
		return 1;
	}

    state = currentState->run(renderer, graphic);
    while(state){
        currentState = currentState->goNextState();
//        cout<<currentState->getState()<<endl;
        state = currentState->run(renderer, graphic);
    }

    //очистка памяти
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;

}
