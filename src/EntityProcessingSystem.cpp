#include "EntityProcessingSystem.h"

void EntityProcessingSystem::processEntities(std::vector<int> mAllEntities, float timeDelta)
{
   mDelta = timeDelta;
   for(int i=0, s= mAllEntities.size(); s>i; i++)
   {
      process(mAllEntities.at(i));
   }
}
