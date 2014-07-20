#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H
#include <list>
template<class Subject>
class IObservable
{
    std::list<Subject*>  _listeners;
public:
    IObservable();
    Changed()
};

#endif // IOBSERVABLE_H
