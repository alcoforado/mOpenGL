attribute vec2 a_vertex;
attribute vec4 a_color;
varying vec4 f_color;
void main(void)
{
    gl_Position = vec4(a_vertex,0,1);
    f_color = a_color;
}
