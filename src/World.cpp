#include "World.h"

World::World()
{
   mEntityManager = EntityManager::getSingletonPtr();
   mTagManager = TagManager::getSingletonPtr();
}
int World::createEntity()
{
   return mEntityManager->createEntity();
}
void World::removeEntity(int e)
{
   mEntityManager->removeEntity(e);
}
