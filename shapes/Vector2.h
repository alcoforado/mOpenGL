#ifndef VECTOR2_H
#define VECTOR2_H
#include <glm/glm.hpp>

class Vector2 : public glm::vec2
{
    using glm::vec2::vec2;
public:

  Vector2(float a,float b);
  Vector2();
};


#endif // VECTOR2_H
