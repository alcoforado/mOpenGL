#ifndef VERTEXARRAYATTRIBUTE_H
#define VERTEXARRAYATTRIBUTE_H
#include <string>
class VertexArrayAttribute
{
    std::string Name;
    int StructOffset;
    int ComponentSize;

public:
    std::string getName(){return Name;}
    int getStructOffset(){return StructOffset;}
    int getComponentSize() {return ComponentSize;}
    VertexArrayAttribute(std::string name,int structOffset)
    {
        Name=name;
        StructOffset=structOffset;
    }
};

#endif // VERTEXARRAYATTRIBUTE_H
