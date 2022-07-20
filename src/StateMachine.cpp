#include "StateMachine.h"
using namespace std;

StateMachine::StateMachine()
{

}

StateMachine::~StateMachine()
{
    //dtor
}

StateMachine* StateMachine::goNextState(){
    return nextState;
}

void StateMachine::setNextState(StateMachine* next){
    nextState = next;
}

char StateMachine::getState(){
    return this->type;
}

///��������� �������� ������ ����
IdleState::IdleState(){
    type='I';
}

IdleState::~IdleState(){

}

bool IdleState::run(SDL_Renderer *renderer, graphic& graphic){
    //������ ��������� ������� � ������
    graphic.btnCont.hidden=1;
    graphic.btnStart.hidden=0;
    graphic.btnStop.hidden=1;
    graphic.info.Set_Text("Press 'START' or 'SPACE'");

    graphic.draw_idle(renderer);
    graphic.draw_slot(renderer);
    graphic.draw_btns(renderer);
    SDL_RenderPresent(renderer);
    while(1){
        if(SDL_PollEvent(&event)){
                ///�������� �� ������
                if(event.type==SDL_MOUSEMOTION){
                        //������� �� "Start"
                        if(event.motion.x > graphic.btnStart.rect.x && event.motion.x < graphic.btnStart.rect.x+graphic.btnStart.rect.w &&
                           event.motion.y > graphic.btnStart.rect.y && event.motion.y < graphic.btnStart.rect.y+graphic.btnStart.rect.h){
                            graphic.btnStart.flag=1;
                            graphic.btnStart.Print(renderer, 1);
                            SDL_RenderPresent(renderer);
                        }
                        else if(graphic.btnStart.flag==1){
                            graphic.btnStart.flag=0;
                            graphic.btnStart.Print(renderer, 1);
                            SDL_RenderPresent(renderer);
                        }
                }
                ///������� ������� �������� ������ "Start"
                if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE){
                    return 1;
                }
                ///������ ���
                if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
                    if(event.motion.x > graphic.btnStart.rect.x && event.motion.x < graphic.btnStart.rect.x+graphic.btnStart.rect.w &&
                       event.motion.y > graphic.btnStart.rect.y && event.motion.y < graphic.btnStart.rect.y+graphic.btnStart.rect.h){
                            return 1;
                    }
                }
                ///����� ������� ��� ESC
                if (event.type==SDL_QUIT || (event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)){
                    return 0;
                }

        }
    }
}
///--------------------------------------------------------------

///��������� �������� ���������
SpinState::SpinState(){
    type='S';
}

SpinState::~SpinState(){

}

bool SpinState::run(SDL_Renderer *renderer, graphic& graphic){
    int i;
    std::string left_time;
    srand(time(NULL));
    //������ ������ �������� �������� ���� ���������
    for(i=0;i<5;i++){
        graphic.drums[i].speed = rand()%12+3;
    }
    graphic.btnStart.hidden=1;
    graphic.btnStop.hidden=0;
    spin_time.Reset();
    graphic.info.Set_Text(std::to_string(5000 - spin_time.GetTimer()));

    while(spin_time.GetTimer() < 5000){
        i=5000 - spin_time.GetTimer();
        left_time = std::to_string(i/1000) + "." + std::to_string((i%1000)/100);
        graphic.info.Set_Text(left_time);
        SDL_RenderClear(renderer);
        graphic.draw_spin(renderer);
        graphic.draw_slot(renderer);
        graphic.draw_btns(renderer);
        SDL_RenderPresent(renderer);
//        _sleep(1000);
        if(SDL_PollEvent(&event)){
                ///�������� �� ������
                if(event.type==SDL_MOUSEMOTION){
                        //������� �� "Stop"
                        if(event.motion.x > graphic.btnStop.rect.x && event.motion.x < graphic.btnStop.rect.x+graphic.btnStop.rect.w &&
                           event.motion.y > graphic.btnStop.rect.y && event.motion.y < graphic.btnStop.rect.y+graphic.btnStop.rect.h){
                            graphic.btnStop.flag=1;
                            graphic.btnStop.Print(renderer, 1);
                            SDL_RenderPresent(renderer);
                        }
                        else if(graphic.btnStop.flag==1){
                            graphic.btnStop.flag=0;
                            graphic.btnStop.Print(renderer, 1);
                            SDL_RenderPresent(renderer);
                        }
                }
                ///������� ������� �������� ������ "Stop"
                if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE){
                    return 1;
                }
                ///������ ���
                if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
                    if(event.motion.x > graphic.btnStop.rect.x && event.motion.x < graphic.btnStop.rect.x+graphic.btnStop.rect.w &&
                       event.motion.y > graphic.btnStop.rect.y && event.motion.y < graphic.btnStop.rect.y+graphic.btnStop.rect.h){
                            return 1;
                    }
                }
                ///����� ������� ��� ESC
                if (event.type==SDL_QUIT || (event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)){
                    return 0;
                }

        }
    }
    return 1;
}
///--------------------------------------------------------------

///��������� ����������� ����������
ResState::ResState(){
    type='R';
}

ResState::~ResState(){
}

bool ResState::run(SDL_Renderer *renderer, graphic& graphic){
    int i, j, count=0;
    int result[] = {0,0,0,0,0};
    bool stop=1;        //���� 0 - ������ ��� ������������
    srand(time(NULL));
    //������ ������ �������� �������� ���� ���������
    for(i=0;i<5;i++){
        graphic.drums[i].speed = 1;
    }
    graphic.btnStop.hidden=1;
    graphic.btnCont.hidden=0;
    graphic.info.Set_Text("Wait...");

    //���� ��� �� ������������ - �����������
    while(stop){
        SDL_RenderClear(renderer);
        graphic.draw_stop(renderer);
        graphic.draw_slot(renderer);
        graphic.draw_btns(renderer);
        SDL_RenderPresent(renderer);
        //���� ��� �������� �����������(�������� �������� ����� 0), �� ������� �� �����
        if(graphic.drums[0].speed == 0 && graphic.drums[1].speed == 0 && graphic.drums[2].speed == 0 &&
            graphic.drums[3].speed ==0 &&  graphic.drums[4].speed == 0)
            {
            stop = 0;
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
            //���� ������ ��������
            if(graphic.drums[i].icons[j].position.y == 205){
                result[graphic.drums[i].icons[j].value]++;
            }
        }
    }
    graphic.info.Set_Text("YOU LOSE!!!");
    for(i=0;i<5;i++){
        if(result[i]>2)
            graphic.info.Set_Text("YOU WON!!!");
    }
    SDL_RenderClear(renderer);
    graphic.draw_stop(renderer);
    graphic.draw_slot(renderer);
    graphic.draw_btns(renderer);
    SDL_RenderPresent(renderer);
    while(1){
        if(SDL_PollEvent(&event)){
                ///�������� �� ������
                if(event.type==SDL_MOUSEMOTION){
                        //������� �� "Start"
                        if(event.motion.x > graphic.btnCont.rect.x && event.motion.x < graphic.btnCont.rect.x+graphic.btnCont.rect.w &&
                           event.motion.y > graphic.btnCont.rect.y && event.motion.y < graphic.btnCont.rect.y+graphic.btnCont.rect.h){
                            graphic.btnCont.flag=1;
                            graphic.btnCont.Print(renderer, 1);
                            SDL_RenderPresent(renderer);
                        }
                        else if(graphic.btnCont.flag==1){
                            graphic.btnCont.flag=0;
                            graphic.btnCont.Print(renderer, 1);
                            SDL_RenderPresent(renderer);
                        }
                }
                ///������ ���
                if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
                    if(event.motion.x > graphic.btnCont.rect.x && event.motion.x < graphic.btnCont.rect.x+graphic.btnCont.rect.w &&
                        event.motion.y > graphic.btnCont.rect.y && event.motion.y < graphic.btnCont.rect.y+graphic.btnCont.rect.h){
                            return 1;
                    }
                }
                ///������� ������� �������� ������
                if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE){
                    return 1;
                }
                ///����� ������� ��� ESC
                if (event.type==SDL_QUIT || (event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)){
                    return 0;
                }
        }
    }
}

///--------------------------------------------------------------
