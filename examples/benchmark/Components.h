#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "Component.h"

typedef enum ComponentType
{
	CTransform2DType
} ComponentType;

/*
CTransform2D Component
*/
struct CTransform2D : public Component
{
	static const int familyId = CTransform2DType;
	float mX, mY, mRotation;
};

#endif
