#ifndef DRUM_H
#define DRUM_H

#include <iostream>
#include <SDL.h>
#include <vector>
#include <time.h>

typedef struct cell{
    SDL_Rect position;
    int value;
};

class drum
{
    public:
        drum();
        virtual ~drum();

        int posX;
        int speed;
        std::vector<cell> icons;

        void create(int shift);
        void spin();

    protected:

    private:
};

#endif // DRUM_H
