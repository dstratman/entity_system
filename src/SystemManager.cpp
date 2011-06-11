#include "SystemManager.h"

SystemManager* SystemManager::mSystemManager;

void SystemManager::initializeAll()
{
   for(unsigned int i=0;i < mAllSystems.size();i++)
      mAllSystems.at(i).initialize();
}

void SystemManager::addSystem(EntitySystem system)
{
   mAllSystems.insert(mAllSystems.end(), system);
}

void SystemManager::removeSystem(EntitySystem system)
{

}
