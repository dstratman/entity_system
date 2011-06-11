#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "Component.h"

typedef enum ComponentType
{
   CTransform2DType,
   CVelocityType,
   CEnemyType,
   CExpiresType,
   CPlayerType,
   CSpatialFormType,
   CWeaponType,
   CHealthType
} ComponentType;

/*
CTransform2D Component
*/
struct CTransform2D : public Component
{
   static const int familyId = CTransform2DType;
   float mX, mY, mRotation;
};

/*
CVelocity Component
*/
struct CVelocity : public Component
{
   static const int familyId = CVelocityType;
   float mVelocity, mAngle;
};

/*
CEnemy Component
*/
struct CEnemy : public Component
{
   static const int familyId = CEnemyType;
};

/*
CExpires Component
*/
struct CExpires : public Component
{
   static const int familyId = CExpiresType;
   int mLifeTime;
};

/*
CHealth Component
*/
struct CHealth : public Component
{
   static const int familyId = CHealthType;
   float mHealth, mMaxHealth;
};

/*
CPlayer Component
*/
struct CPlayer : public Component
{
   static const int familyId = CPlayerType;
};

/*
CSpatialForm Component
*/
struct CSpatialForm : public Component
{
   static const int familyId = CSpatialFormType;
   std::string mSpatialFormFile;
};

/*
CWeapon Component
*/
struct CWeapon : public Component
{
   static const int familyId = CWeaponType;
   long mShotAt;
};

#endif
