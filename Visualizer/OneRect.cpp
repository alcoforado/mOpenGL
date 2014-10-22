#include "OneRect.h"
#include <iostream>
#include <shapes2D/Rect2D.h>

void OneRect::initialize()
{
    Vector2 vec2=  {1.0f,2.0f};

    std::cout << vec2.x;
    Rect2D<ColorShader2D::VerticeData>  Rec(
        {1,2},
        {1,3});


}
