#pragma once

#include "utils.h"
#include "constants.h"

class Renderable
{
    public:
        Renderable();
        void render();
        bool load(std::string path);
        void setPosition(int,int);
        int getX();
        int getY();
        int getWidth();
        int getHeight();
        void free();
    private:
        LTexture texture;
};