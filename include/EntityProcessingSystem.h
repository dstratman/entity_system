#ifndef ENTITY_PROCESSING_SYSTEM_H
#define ENTITY_PROCESSING_SYSTEM_H

#include "EntitySystem.h"
#include "EntityManager.h"

class EntityProcessingSystem : public EntitySystem
{
public:
protected:
	virtual void process(int e);
	void processEntities(std::vector<int> mAllEntities, float timeDelta);
	bool checkProcessing() { return true; }
	float mDelta;
};

#endif