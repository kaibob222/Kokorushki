#pragma once
#ifndef __PHYSICS_H__
#define __PHYCICS_H__

#include "cocos2d.h"
#include "Unit.h"

class Physics
{
public:
	void setPhysics(Unit unit);
private:
	void update(float dt);
};
#endif
