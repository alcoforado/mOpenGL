#ifndef VECTOR2_H
#define VECTOR2_H
#include <glm/glm.hpp>

class Vector2 : public glm::vec2
{
    using glm::vec2::vec2;
public:

  Vector2(float a,float b);
  Vector2();
  void operator=(const glm::vec2& v2)
  {
      glm::vec2 *base = this;
      *base=v2;
  }


};


#endif // VECTOR2_H
