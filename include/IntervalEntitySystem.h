#ifndef INTERVAL_ENTITY_SYSTEM_H
#define INTERVAL_ENTITY_SYSTEM_H

#include "EntitySystem.h"

class IntervalEntitySystem : public EntitySystem
{
protected:
   bool checkProcessing()
   {
   }
private:
   int mAcc;
   int mInterval;
};

#endif
