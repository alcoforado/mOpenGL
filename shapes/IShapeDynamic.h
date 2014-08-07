#ifndef ISHAPEDYNAMIC_H
#define ISHAPEDYNAMIC_H
#include <list>
#include <shapes/IShapeWatcher.h>

template<class VertexData>
class IShapeDynamic : public IShape<VertexData>
{
protected:
    std::list<IShapeWatcher<VertexData>* > _watchers;
public:

    void TriggerChangedEvent()
    {
        for (IShapeWatcher<VertexData>* watcher : _watchers)
        {
            watcher->ShapeChanged(this);

        }

    }

    void AddWatcher(IShapeWatcher<VertexData> *watcher)
    {
        _watchers.push_back(watcher);

    }

    ~IShapeDynamic()
    {
        for (IShapeWatcher<VertexData>* watcher : _watchers)
        {
            watcher->ShapeDeleted(this);
        }
    }

};

#endif // ISHAPEDYNAMIC_H
