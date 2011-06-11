#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

class ComponentManager
{
public:
	~ComponentManager(void);

	static ComponentManager* getSingletonPtr(void);
private:
	ComponentManager( void );
	ComponentManager( const ComponentManager& ) { }
	ComponentManager & operator = ( const ComponentManager& );


	static ComponentManager *mComponentManager;
};

#endif