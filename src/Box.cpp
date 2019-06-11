#include "Box.hpp"


Box :: Box(){
    boxRect = new SDL_Rect();
    boxColor = new SDL_Color();
    boxRect->w = mWidth;
    boxRect->h = mHeight;
    boxColor->r= 0;
    boxColor->g= 0;
    boxColor->b= 0;
    boxColor->a= 0;
}

Box :: ~Box(){
    delete boxRect;
    delete boxColor;
}

SDL_Color* Box :: getColor(){

    return boxColor;
}
SDL_Rect* Box :: getRect(){

    return boxRect;
}
int Box :: getWidth(){

    return mWidth;
}
int Box :: getHeight(){

    return mHeight;
}