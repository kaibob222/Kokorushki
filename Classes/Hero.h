#pragma once
#ifndef __HERO_H__
#define __HERO_H__

#include "cocos2d.h"
#include "Unit.h"
#include "HelloWorldScene.h"
#include "Anime.h"

class Hero : public Unit
{
public:
	static void goRight(cocos2d::Sprite* heroSprite);
	static void goLeft(cocos2d::Sprite* heroSprite);
	static void heroPunch(cocos2d::Sprite* heroSprite);
	static void heroJump(cocos2d::Sprite* heroSprite);
	static void heroStop(cocos2d::Sprite* heroSprite);
	static void heroHurt(cocos2d::Sprite* heroSprite);
	static void heroDeath(cocos2d::Sprite* heroSprite);
};
#endif
