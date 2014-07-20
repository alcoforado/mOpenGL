#ifndef VECTOR4_H
#define VECTOR4_H
#include <glm/glm.hpp>

class Vector4 : public glm::vec4
{
public:
  //using glm::vec4::glm::vec4;

  Vector4();
  Vector4(float a, float b, float c, float d);
};

#endif // VECTOR4_H
