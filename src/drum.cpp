#include "drum.h"

drum::drum()
{
    speed=0;
}

drum::~drum()
{

}

void drum::create(int shift){
    icons.clear();
    cell new_cell;
    srand(time(NULL));
    for(int i=0;i<3;i++){
        new_cell.position.y = 75+i*130;
        new_cell.position.x=posX;
//        new_cell.value = rand()%5;
        new_cell.value = (i+shift+4)%5;
        icons.push_back(new_cell);
    }
}
