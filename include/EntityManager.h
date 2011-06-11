#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <unordered_map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include "Component.h"

class EntityManager
{
public:
	~EntityManager(void);

	int createEntity();
	void removeEntity(int entity);

	int getTotalCreated() { return mTotalCreated; }
	int getTotalRemoved() { return mTotalRemoved; }

	static EntityManager* getSingletonPtr(void);
private:
	EntityManager( void );
	EntityManager( const EntityManager& ) { }
	EntityManager & operator = ( const EntityManager& );


	int generateNewEntityID();

	int mLowestUnassignedEntityID;
	int mTotalCreated;
	int mTotalRemoved;

	std::set<int> mAllEntities;
	std::map<int, std::map<int, Component*> > mComponentStore;

	static EntityManager *mEntityManager;
public:
	
	template<class T> void addComponent(int entity, T* comp)
	{
		mComponentStore[T::familyId].insert(std::pair<int, T*>(entity, comp));
	}
	
	template<class T> void removeComponent(int entity, T* comp)
	{
		mComponentStore[T::familyId].remove(std::pair<int, T*>(entity, comp));
	}

	template<class T> void getEntities(std::set<int> &result)
	{
		std::map<int, Component*> m = mComponentStore[T::familyId];
		for(std::map<int, Component*>::iterator it = m.begin(); it != m.end(); ++ it)
			result.insert(it->first);
	}
	
	template<class T> T *getComponent(int entity)
	{
		std::map<int, Component*> &store = mComponentStore[T::familyId];
		return (T*)store[entity];
	}
};

#endif