
#include "ColorShader2D.h"
#include <glsl/Color2D_VS.h>
#include <glsl/Color2D_PS.h>


ColorShader2D::ColorShader2D(GL &gl)
    :_gl(gl),_program(gl,Color2D_VS,Color2D_PS)
{

}
