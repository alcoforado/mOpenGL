#pragma once



#include <utilities/EngineException.h>
#include <utilities/IArray.h>
#include <list>
#include <framework/IShapeWatcher.h>

enum TopologyType {POINTS,TRIANGLES,LINES,MIXED,EMPTY};

template<class VertexData>
class IShape
{
protected:
    std::list<IShapeWatcher<VertexData>* > _watchers;

public:
    virtual TopologyType GetTopologyType()=0;
	virtual unsigned nIndices()=0;
	virtual unsigned nVertices()=0;
    virtual void write(IArray<VertexData> &vertices, IArray<int> &indices)=0;
    virtual bool IsIndexed() {return nIndices() == 0;}



    virtual void TriggerChangedEvent() final
    {
        for (IShapeWatcher<VertexData>* watcher : _watchers)
        {
            watcher->ShapeChanged(this);

        }
    }

    virtual void AddWatcher(IShapeWatcher<VertexData> *watcher) final
    {
        _watchers.push_back(watcher);
    }

    virtual ~IShape()
    {
        for (IShapeWatcher<VertexData>* watcher : _watchers)
        {
            watcher->ShapeDeleted(this);
        }
    }


};

