#ifndef VECTOR3_H
#define VECTOR3_H
#include <glm/glm.hpp>

class Vector3 : public glm::vec3
{
    using glm::vec3::vec3;
public:

  Vector3(float a,float b,float c);
  Vector3();
};

#endif // VECTOR3_H
