#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <math.h>
#include <time.h>
#include "EntitySystem.h"
#include "EntityProcessingSystem.h"
#include "EntityManager.h"
#include "FastMath.h"
#include "Utils.h"

class MovementSystem : public EntityProcessingSystem
{
public:
	MovementSystem();
	void initialize()
	{
		mEntityManager = EntityManager::getSingletonPtr();
	}
protected:
	void process(int e)
	{
		CVelocity *vel = mEntityManager->getComponent<CVelocity>(e);
		float v = vel->mVelocity;
		float r = FastMath<float>::deg2rad(vel->mAngle);

		CTransform2D *pos = mEntityManager->getComponent<CTransform2D>(e);
		float xn = pos->mX + (std::cos(r) * v * mDelta);
		float yn = pos->mY + (std::sin(r) * v * mDelta);

		pos->mX = xn;
		pos->mY = yn;
	}
private:
};

class CollisionSystem : public EntitySystem
{
public:
	CollisionSystem();
	void initialize()
	{
		mEntityManager = EntityManager::getSingletonPtr();
	}
protected:
private:
	bool collisionExists(int e1, int e2)
	{
		CTransform2D *t1 = mEntityManager->getComponent<CTransform2D>(e1);
		CTransform2D *t2 = mEntityManager->getComponent<CTransform2D>(e2);
		return Utils<float>::distance(t1->mX,t1->mY,t2->mX,t2->mY);
	}
};

class EnemyShipMovementSystem : public EntityProcessingSystem
{
public:
	EnemyShipMovementSystem();
protected:
	void process(int e)
	{
		CTransform2D* t = mEntityManager->getComponent<CTransform2D>(e);
		CVelocity* v = mEntityManager->getComponent<CVelocity>(e);

		if(t->mX > 320 || t->mX < 0)
			v->mAngle = (int)(v->mAngle + 180) % 360;
	}
private:
};

class EnemyShooterSystem : public EntityProcessingSystem
{
public:
	EnemyShooterSystem();
protected:
	void begin() 
	{ 
		//TODO get working time
		now = 0; 
	}
	void process(int e)
	{
		CWeapon* w = mEntityManager->getComponent<CWeapon>(e);

		if(w->mShotAt + 2000 < now)
		{
			CTransform2D *t = mEntityManager->getComponent<CTransform2D>(e);
		}
	}
private:
	long now;
};
 

#endif
