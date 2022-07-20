#include "graphic.h"

graphic::graphic(){
    //загружаем фон на поверзность
    surface = SDL_LoadBMP("backround.bmp");
    //задаем параметры кнопкам
    btnStart.Set_Name("Start");
    btnStart.Set_Position(800, 75, 150, 75);
    btnStop.Set_Name("Stop");
    btnStop.Set_Position(800, 380, 150, 75);
    btnCont.Set_Name("Continue");
    btnCont.Set_Position(300, 410, 200, 75);
    //загружаем иконки в массив
    SDL_Surface* picture;
    picture = SDL_LoadBMP("0.bmp");
    pictures.push_back(picture);
    picture = SDL_LoadBMP("1.bmp");
    pictures.push_back(picture);
    picture = SDL_LoadBMP("2.bmp");
    pictures.push_back(picture);
    picture = SDL_LoadBMP("3.bmp");
    pictures.push_back(picture);
    picture = SDL_LoadBMP("4.bmp");
    pictures.push_back(picture);
    //создаем 5 барабанов
    drum new_drum;
    for(int i=0;i<5;i++){
        new_drum.posX = 75+i*130;
        new_drum.create(i);
        drums.push_back(new_drum);
    }
}

graphic::~graphic()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void graphic::draw_slot(SDL_Renderer *renderer){
    SDL_Rect rect;
    SDL_SetRenderDrawColor(renderer, 158, 95, 45, 255);
    //верхняя и нижняя рамки
    rect.h=120; rect.w=670;
    rect.x=60; rect.y=0;
    SDL_RenderFillRect(renderer, &rect);
    rect.h=150; rect.y=395;
    SDL_RenderFillRect(renderer, &rect);
    //правая и левая рамки
    rect.h=300; rect.w=15;
    rect.x=60; rect.y=100;
    SDL_RenderFillRect(renderer, &rect);
    rect.x=715;
    SDL_RenderFillRect(renderer, &rect);

    //выделение
    SDL_SetRenderDrawColor(renderer, 237, 163, 36, 180);
    rect.w=652; rect.h=6;
    rect.x=69; rect.y=197;
    SDL_RenderFillRect(renderer, &rect);
    rect.y+=130;
    SDL_RenderFillRect(renderer, &rect);
    rect.w=5; rect.h=136;
    rect.x=67-130; rect.y=197;
    for(int i=0;i<6;i++){
        rect.x+=130;
        SDL_RenderFillRect(renderer, &rect);
    }
    info.Print(renderer);
}

//отрисовка статичных барабанов
void graphic::draw_idle(SDL_Renderer *renderer){
    SDL_Rect rect;
    int i,j;
    //рисуем барабаны
    SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);
    for(i=0;i<5;i++){
        for(j=0;j<drums[i].icons.size();j++){
            SDL_BlitSurface(pictures[drums[i].icons[j].value], NULL, surface, &drums[i].icons[j].position);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_DestroyTexture(texture);
}

//отрисовка вращения барабанов
void graphic::draw_spin(SDL_Renderer *renderer){
    SDL_Rect rect;
    int i,j;
    //рисуем барабаны
    SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);
    for(i=0;i<5;i++){
        for(j=0;j<drums[i].icons.size();j++){
            ///рандом барабанов
            //двигаем вниз с заданной скорость
            drums[i].icons[j].position.y+=drums[i].speed;
            //если картинка дошла до низа экрана, то обновляем картинку и перемещаем наверз
            if(drums[i].icons[j].position.y > 390){
                drums[i].icons[j].value = (drums[i].icons[j].value+2)%5;
                drums[i].icons[j].position.y=0;
            }
            SDL_BlitSurface(pictures[drums[i].icons[j].value], NULL, surface, &drums[i].icons[j].position);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_DestroyTexture(texture);
}

//отрисовка остановки и показ результата
void graphic::draw_stop(SDL_Renderer *renderer){
    SDL_Rect rect;
    int i,j;
    //рисуем барабаны
    SDL_SetRenderDrawColor(renderer, 100, 0, 0, 255);
    for(i=0;i<5;i++){
        for(j=0;j<drums[i].icons.size();j++){
            //двигаем вниз с заданной скоростью
            drums[i].icons[j].position.y+=drums[i].speed;
            //если картинка дошла до низа экрана, то обновляем картинку и перемещаем наверх
            if(drums[i].icons[j].position.y > 390){
                drums[i].icons[j].value = (drums[i].icons[j].value+2)%5;
                drums[i].icons[j].position.y=0;
            }
            //если картинка дошла до "области подсчета выйгрыша", то останавливаем" барабан(столбец картинок)
            if(drums[i].icons[j].position.y == 205){
                drums[i].speed=0;
            }
            SDL_BlitSurface(pictures[drums[i].icons[j].value], NULL, surface, &drums[i].icons[j].position);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_DestroyTexture(texture);
}

void graphic::draw_btns(SDL_Renderer *renderer){
    btnStart.Print(renderer, 1);
    btnStop.Print(renderer, 1);
    btnCont.Print(renderer, 1);
}
