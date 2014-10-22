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
    template<class VerticeData,class MemberType>
    VertexArrayAttribute(std::string name,MemberType VerticeData::*member)
    {
        VerticeData data;

        this->Name=name;
        this->StructOffset= ((void*) data.*member) - ((void*) &data);
        this->ComponentSize=sizeof(MemberType);
    }
};

#endif // VERTEXARRAYATTRIBUTE_H
