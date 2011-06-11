#ifndef TAG_MANAGER_H
#define TAG_MANAGER_H

#include <iostream>
#include <string>
#include <map>
//TODO: Not fulling working, finish

class TagManager
{
public:
   ~TagManager(void);

   void AddTag(std::string tag, int e);
   void RemoveTag(std::string);

   bool isRegistered(std::string tag);
   int getEntity(std::string tag);

   static TagManager* getSingletonPtr(void);
private:
   TagManager( void );
   TagManager( const TagManager& ) { }
   TagManager & operator = ( const TagManager& );

   std::map<std::string, int> mEntityByTag;

   static TagManager *mTagManager;
};

#endif
