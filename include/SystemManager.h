#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <vector>
#include <algorithm>
#include <iterator>
#include "EntitySystem.h"

class SystemManager
{
public:
	~SystemManager(void);

	void initializeAll();
	void addSystem(EntitySystem system);
	void removeSystem(EntitySystem system);

	static SystemManager* getSingletonPtr(void);
private:
	SystemManager( void );
	SystemManager( const SystemManager& ) { }
	SystemManager & operator = ( const SystemManager& );

	std::vector<EntitySystem> mAllSystems;

	static SystemManager *mSystemManager;
};

#endif