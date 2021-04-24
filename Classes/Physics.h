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
	cocos2d::PhysicsWorld *sceneWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld *world) {
		sceneWorld = world;
	};
};
#endif
