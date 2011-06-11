#ifndef WORLD_H
#define WORLD_H

#include "EntityManager.h"
#include "TagManager.h"
#include "SystemManager.h"

class World
{
public:
   World();

   int createEntity();
   void removeEntity(int e);
   void setDelta(int delta) { mDelta = delta; }
   int getDelta() { return mDelta; }
   void loopStart();
   
private:
   EntityManager* mEntityManager;
   TagManager* mTagManager;
   SystemManager* mSystemManager;

   int mDelta;
};

#endif
