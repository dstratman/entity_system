#include "TagManager.h"

TagManager* TagManager::mTagManager;

TagManager::TagManager(void)
{
}

void TagManager::AddTag(std::string tag, int e)
{
	mEntityByTag.insert(std::pair<std::string,int>(tag, e));
}

void TagManager::RemoveTag(std::string tag)
{
	mEntityByTag.erase(tag);
}

bool TagManager::isRegistered(std::string tag)
{
	return false;
}

int TagManager::getEntity(std::string tag)
{
	return 0;
}

TagManager* TagManager::getSingletonPtr( void ) 
{
    if( !mTagManager ) 
	{
        mTagManager = new TagManager();
    }

    return mTagManager;
}
