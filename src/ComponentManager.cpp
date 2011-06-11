#include "ComponentManager.h"

ComponentManager* ComponentManager::mComponentManager;



ComponentManager* ComponentManager::getSingletonPtr( void ) 
{
    if( !mComponentManager ) 
	{
        mComponentManager = new ComponentManager();
    }

    return mComponentManager;
}