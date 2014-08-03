#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H
#include <list>
template<class Type>
class IWatcher
{
public:
    virtual void Changed(Type* type)=0;
    virtual void Deleted(Type* type)=0;
};


template<class Type>
class IObservable
{
    std::list<IWatcher<Type> >  _listeners;
public:
    IObservable();
   ~IObservable()
    {
        for(IWatcher<Type> *subj : _listeners)
        {
            subj->Deleted((Type*) this);
        }

    }
    void AddWatcher(IWatcher<Type>* subj){_listeners.add(subj);};


    virtual void Changed()
    {
        for(IWatcher<Type>* subj : _listeners)
        {
            subj->Changed((Type*)this);
        }

    }



};

#endif // IOBSERVABLE_H
