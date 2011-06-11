#include "EntityManager.h"

EntityManager* EntityManager::mEntityManager;

EntityManager::EntityManager(void)
{
	mLowestUnassignedEntityID = 1;
	mTotalCreated = 0;
	mTotalRemoved = 0;
}
EntityManager::~EntityManager(void)
{
}

int EntityManager::createEntity()
{
	int newID = generateNewEntityID();

	if(newID < 1)
	{
		return 0;
	}
	else
	{
		mAllEntities.insert(newID);
		return newID;
	}
}

void EntityManager::removeEntity(int entity)
{
	++mTotalRemoved;
	std::set<int>::iterator it = mAllEntities.find(entity);
	mAllEntities.erase(it);
}

int EntityManager::generateNewEntityID()
{
	++mTotalCreated;
	if( mLowestUnassignedEntityID < INT_MAX)
	{
		return (++mLowestUnassignedEntityID);
	}
	else
	{
		std::set<int>::iterator it;
		for(int i=1; i<INT_MAX; i++)
		{
			it = mAllEntities.find(i);
			if(it == mAllEntities.end())
				return i;
		}
		return -1;
	}
}

EntityManager* EntityManager::getSingletonPtr( void ) 
{
    if( !mEntityManager ) 
	{
        mEntityManager = new EntityManager();
    }

    return mEntityManager;
}