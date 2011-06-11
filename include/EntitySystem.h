#ifndef ENTITY_SYSTEM_H
#define ENTITY_SYSTEM_H

#include <vector>
#include <set>
#include "EntityManager.h"
#include "Component.h"

class EntitySystem
{
public:
	EntitySystem();
	void initialize();
	void getAllEntitiesPosessing(Component c);
protected:
	virtual void begin();
	virtual void end();
	virtual void processEntities();
	virtual bool checkProcessing();
	virtual void added(int e);
	EntityManager* mEntityManager;
private:
	//long mSystemBit;
	//long mTypeFlags;
	//std::set<int> mListofEntities;

};

#endif