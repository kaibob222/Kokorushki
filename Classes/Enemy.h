#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Unit.h"

class Enemy : public Unit
{	public:
	static void enemyPhysics(cocos2d::Sprite* heroSprite);
	static void enemyAttack(cocos2d::Sprite* heroSprite);
};
#endif
