#include "Hero.h"
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "Anime.h"
#include "Scene2.h"

USING_NS_CC;

bool isJumping = false;
bool isRight = false;
float jumpForce = 10;
int maxJump = 40;
bool isWalking = false;
bool isPunching = false;
bool moveRight = false;
bool moveLeft = false;
bool goDown = false;
//cocos2d::Sprite* heroSprite;

/*void startClass()
{
	if (Hero::sceneId == 1)
	{
		heroSprite = HelloWorld::sprite1;
	}
	else if (Hero::sceneId == 2)
	{
		heroSprite = Scene2::sprite1;
	}
}*/
void Hero::goRight(Sprite* heroSprite)
{
	if (isPunching)
	{
		Animate* nopunchanimate = Animate::create(Anim::noRightPunch());
		heroSprite->runAction(nopunchanimate);
		isPunching = false;
	}
	isWalking = true;
	isRight = true;
	if (!isJumping)
	{
		ActionInterval* move = MoveBy::create(0.15, Point(50, 0));
		auto repeatForever = cocos2d::RepeatForever::create(Sequence::create(move, move, NULL));
		repeatForever->setTag(1);
		heroSprite->runAction(repeatForever);
		Animate* animate = Animate::create(Anim::walkRight());
		auto repAnimate = cocos2d::RepeatForever::create(RepeatForever::create(animate));
		repAnimate->setTag(2);
		heroSprite->runAction(repAnimate);
	}
	else {
		moveRight = true;
	}
}

void Hero::goLeft(cocos2d::Sprite* heroSprite)
{
	if (isPunching)
	{
		Animate* noLeftpunchanimate = Animate::create(Anim::noLeftPunch());
		heroSprite->runAction(noLeftpunchanimate);
		isPunching = false;
	}
	isWalking = true;
	isRight = false;
	if (!isJumping)
	{
		ActionInterval* move1 = MoveBy::create(0.15, Point(-50, 0));
		auto repeatForever1 = cocos2d::RepeatForever::create(Sequence::create(move1, move1, NULL));
		repeatForever1->setTag(3);
		heroSprite->runAction(repeatForever1);
		Animate* animate1 = Animate::create(Anim::walkLeft());
		auto repAnimate1 = cocos2d::RepeatForever::create(RepeatForever::create(animate1));
		repAnimate1->setTag(4);
		heroSprite->runAction(repAnimate1);
	}
	else {
		moveLeft = true;
	}
}

void Hero::heroPunch(cocos2d::Sprite* heroSprite)
{
	if (!isWalking)
	{
		if (!isPunching)
		{
			if (isRight)
			{
				Animate* punchanimate = Animate::create(Anim::rightPunch());
				heroSprite->runAction(punchanimate);
				isPunching = true;
			}
			else
			{
				Animate* punchLeftanimate = Animate::create(Anim::leftPunch());
				punchLeftanimate->setTag(6);
				heroSprite->runAction(punchLeftanimate);
				isPunching = true;
			}
		}
		else
		{
			if (isRight)
			{
				Animate* punchianimate = Animate::create(Anim::rightPunchi());
				punchianimate->setTag(7);
				heroSprite->runAction(punchianimate);
			}
			else
			{
				Animate* punchiLeftanimate = Animate::create(Anim::leftPunchi());
				punchiLeftanimate->setTag(8);
				heroSprite->runAction(punchiLeftanimate);
			}
		}
	}
}

void Hero::heroJump(cocos2d::Sprite* heroSprite)
{
	Point pos = heroSprite->getPosition();
	if (pos.y == 150)
	{
		if (isWalking)
		{
			if (isRight)
			{
				isJumping = true;
				Animate* Jumpanimate = Animate::create(Anim::rightJump());
				ActionInterval* jump = JumpBy::create(0.5, Point(80, 0), 60, 1);
				heroSprite->runAction(jump);
				heroSprite->runAction(Jumpanimate);
			}
			else
			{
				isJumping = true;
				Animate* JumpLeftanimate = Animate::create(Anim::leftJump());
				ActionInterval* jump1 = JumpBy::create(0.5, Point(-80, 0), 60, 1);
				heroSprite->runAction(jump1);
				heroSprite->runAction(JumpLeftanimate);
			}
		}
		else
		{
			if (isRight)
			{
				isJumping = true;
				Animate* Jumpanimate = Animate::create(Anim::rightJump());
				ActionInterval* jump = JumpBy::create(0.5, Point(0, 0), 60, 1);
				heroSprite->runAction(jump);
				heroSprite->runAction(Jumpanimate);
			}
			else
			{
				isJumping = true;
				Animate* JumpLeftanimate = Animate::create(Anim::leftJump());
				ActionInterval* jump1 = JumpBy::create(0.5, Point(0, 0), 60, 1);
				heroSprite->runAction(jump1);
				heroSprite->runAction(JumpLeftanimate);
			}
		}
	}
	isJumping = false;
}

void Hero::heroStop(cocos2d::Sprite* heroSprite)
{
	isWalking = false;
	if (isRight) {
		heroSprite->setTexture("Adv.png");
		heroSprite->setTextureRect(Rect(1, 33, 137, 131));
	}
	else {
		heroSprite->setTexture("Adv.png");
		heroSprite->setTextureRect(Rect(18, 1264, 137, 131));
	}
	jumpForce = 10;
}