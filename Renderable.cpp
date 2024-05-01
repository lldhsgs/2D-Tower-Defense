
#include "Renderable.h"
#include "utils.h"

Renderable::Renderable(){}

void Renderable::render()
{
    texture.render(texture.getX(),texture.getY());
}
bool Renderable::load(std::string path)
{
    bool success = true;
    if (!texture.loadFromFile(path)){
        printf("Unable to render texture\n");
        success = false;
    }
    return success;
}
void Renderable::setPosition(int x,int y)
{
    texture.setPosition(x,y);
}
int Renderable::getX()
{
    return texture.getX();
}
int Renderable::getY()
{
    return texture.getY();
}
int Renderable::getWidth()
{
    return texture.getWidth();
}
int Renderable::getHeight()
{
    return texture.getHeight();
}

void Renderable::free()
{
    texture.free();
}