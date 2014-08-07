attribute vec2 a_vertex;
attribute vec4 a_color;
varying vec2 f_color;
void main(void)
{
    gl_Position = a_vertex;
    f_color = a_color;
}
