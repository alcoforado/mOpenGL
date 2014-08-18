#ifndef VECTOR4_H
#define VECTOR4_H
#include <glm/glm.hpp>

class Vector4 : public glm::vec4
{
public:
  //using glm::vec4::glm::vec4;

  Vector4();
  Vector4(float a, float b, float c, float d);

  Vector4& operator=(const glm::vec4 &vec)
  {
      *this=vec;
      return *this;
  }
};

#endif // VECTOR4_H
