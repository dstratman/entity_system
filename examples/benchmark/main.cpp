#include <iostream>
#include <stdio.h>
#include "EntityManager.h"
#include "Components.h"

int main ( int argc, char *argv[] )
{
   EntityManager* mEntityManager = EntityManager::getSingletonPtr();

   int Ship = mEntityManager->createEntity();

   CTransform2D *t = new CTransform2D();
   t->mX = 50;
   t->mY = 50;
   t->mRotation = 90;

   mEntityManager->addComponent<CTransform2D>(Ship, t);
        
   CTransform2D *pos = mEntityManager->getComponent<CTransform2D>(Ship);
   std::cout<<"Did it work?"<<std::endl;
   
   std::set<int> positionList;
   mEntityManager->getEntities<CTransform2D>(positionList);

   std::cout<<positionList.size()<<std::endl;
   
   int test;
   std::cin>>test;

   return 0;
}
