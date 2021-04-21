#ifndef __ANIME_H__
#define __ANIME_H__
#include "cocos2d.h"

class Anim
{
private:
	int hp;
	float x;
	float y;


public:
	static cocos2d::Animation* walkRight();
	static cocos2d::Animation* walkLeft();
	static cocos2d::Animation* noLeftPunch();
	static cocos2d::Animation* noRightPunch();
	static cocos2d::Animation* leftPunch();
	static cocos2d::Animation* rightPunch();
	static cocos2d::Animation* leftPunchi();
	static cocos2d::Animation* rightPunchi();
	static cocos2d::Animation* leftJump();
	static cocos2d::Animation* rightJump();
};


#endif