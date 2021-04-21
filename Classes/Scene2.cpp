#include "Scene2.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"
#include "Anime.h"

USING_NS_CC;

int q;

Scene* Scene2::createScene()
{
	return Scene2::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Scene2::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Director::getInstance()->getOpenGLView()->setFrameSize(900, 600);
	Director::getInstance()->getOpenGLView()->setDesignResolutionSize(900, 600, ResolutionPolicy::EXACT_FIT);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("scene2.jpg");
	if (background == nullptr)
	{
		problemLoading("'scene2.jpg'");
	}
	else
	{
		// position the sprite on the center of the screen
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(background, 0);
	}
	
	auto label = Label::createWithTTF("SCENE 2", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	sprite1 = Sprite::create("Adv.png", Rect(1, 33, 137, 131));
	sprite1->setPosition(Point(50, 150));
	sprite2 = Sprite::create("enemy/enemy2.png");
	sprite2->setPosition(Point(600, 185));

	this->addChild(sprite1);
	this->addChild(sprite2);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Scene2::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Scene2::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	auto menu_Item_1 = MenuItemFont::create("Exit", CC_CALLBACK_1(Scene2::Exit, this));
	auto *menu = Menu::create(menu_Item_1, NULL);
	menu->alignItemsVertically();
	menu->setPosition(Point(880, 570));
	this->addChild(menu);

	this->scheduleUpdate();

	return true;
}

bool isJumping1 = false;
bool isRight1 = false;
float jumpForce1 = 10;
int maxJump1 = 40;
bool isWalking1 = false;
bool isPunching1 = false;
bool moveRight1 = false;
bool moveLeft1 = false;
bool goDown1 = false;

void Scene2::update(float dt) {
	Point pos = sprite1->getPosition();
	Point pos1 = sprite2->getPosition();

	if (pos < Point(50, 150)) {
		q = 1;
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	}
}

void Scene2::Exit(cocos2d::Ref *pSpender)
{
	CCLOG("Exit");
	auto scene = MenuMain::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Scene2::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	CCLOG("Key with keycode %d pressed", keyCode);
	Point pos = sprite1->getPosition();
	if ((int)keyCode == 127 || (int)keyCode == 27)//keys D or -> pressed
	{
		CCLOG("right");
		for (int i = 1; i <= 8; i++)
		{
			sprite1->stopActionByTag(i);
		}
		if (isPunching1)
		{
			Animate* nopunchanimate = Animate::create(Anim::noRightPunch());
			sprite1->runAction(nopunchanimate);
			isPunching1 = false;
		}
		isWalking1 = true;
		isRight1 = true;
		if (!isJumping1)
		{
			ActionInterval* move = MoveBy::create(0.15, Point(50, 0));
			auto repeatForever = cocos2d::RepeatForever::create(Sequence::create(move, move, NULL));
			repeatForever->setTag(1);
			sprite1->runAction(repeatForever);
			Animate* animate = Animate::create(Anim::walkRight());
			auto repAnimate = cocos2d::RepeatForever::create(RepeatForever::create(animate));
			repAnimate->setTag(2);
			sprite1->runAction(repAnimate);
		}
		else {
			moveRight1 = true;
		}
	}
	if ((int)keyCode == 124 || (int)keyCode == 26)//keys A or <- pressed
	{
		CCLOG("left");
		for (int i = 1; i <= 8; i++)
		{
			sprite1->stopActionByTag(i);
		}
		if (isPunching1)
		{
			Animate* noLeftpunchanimate = Animate::create(Anim::noLeftPunch());
			sprite1->runAction(noLeftpunchanimate);
			isPunching1 = false;
		}
		isWalking1 = true;
		isRight1 = false;
		if (!isJumping1)
		{
			ActionInterval* move1 = MoveBy::create(0.15, Point(-50, 0));
			auto repeatForever1 = cocos2d::RepeatForever::create(Sequence::create(move1, move1, NULL));
			repeatForever1->setTag(3);
			sprite1->runAction(repeatForever1);
			Animate* animate1 = Animate::create(Anim::walkLeft());
			auto repAnimate1 = cocos2d::RepeatForever::create(RepeatForever::create(animate1));
			repAnimate1->setTag(4);
			sprite1->runAction(repAnimate1);
		}
		else {
			moveLeft1 = true;
		}
	}
	if ((int)keyCode == 133)//key J pressed
	{
		CCLOG("fight!");
		for (int i = 1; i <= 8; i++)
		{
			sprite1->stopActionByTag(i);
		}
		if (!isWalking1)
		{
			if (!isPunching1)
			{
				if (isRight1)
				{
					Animate* punchanimate = Animate::create(Anim::rightPunch());
					sprite1->runAction(punchanimate);
					isPunching1 = true;
				}
				else
				{
					Animate* punchLeftanimate = Animate::create(Anim::leftPunch());
					punchLeftanimate->setTag(6);
					sprite1->runAction(punchLeftanimate);
					isPunching1 = true;
				}
			}
			else
			{
				if (isRight1)
				{
					Animate* punchianimate = Animate::create(Anim::rightPunchi());
					punchianimate->setTag(7);
					sprite1->runAction(punchianimate);
				}
				else
				{
					Animate* punchiLeftanimate = Animate::create(Anim::leftPunchi());
					punchiLeftanimate->setTag(8);
					sprite1->runAction(punchiLeftanimate);
				}
			}
		}
	}
	if ((int)keyCode == 59)//key Space was pressed
	{
		CCLOG("jump");
		Point posi = sprite1->getPosition();
		if (posi.y == 150)
		{
			CCLOG("hey");
			if (isWalking1)
			{
				if (isRight1)
				{
					isJumping1 = true;
					Animate* Jumpanimate = Animate::create(Anim::rightJump());
					ActionInterval* jump = JumpBy::create(0.5, Point(80, 0), 60, 1);
					sprite1->runAction(jump);
					sprite1->runAction(Jumpanimate);
				}
				else
				{
					isJumping1 = true;
					Animate* JumpLeftanimate = Animate::create(Anim::leftJump());
					ActionInterval* jump1 = JumpBy::create(0.5, Point(-80, 0), 60, 1);
					sprite1->runAction(jump1);
					sprite1->runAction(JumpLeftanimate);
				}
			}
			else
			{
				if (isRight1)
				{
					isJumping1 = true;
					Animate* Jumpanimate = Animate::create(Anim::rightJump());
					ActionInterval* jump = JumpBy::create(0.5, Point(0, 0), 60, 1);
					sprite1->runAction(jump);
					sprite1->runAction(Jumpanimate);
				}
				else
				{
					isJumping1 = true;
					Animate* JumpLeftanimate = Animate::create(Anim::leftJump());
					ActionInterval* jump1 = JumpBy::create(0.5, Point(0, 0), 60, 1);
					sprite1->runAction(jump1);
					sprite1->runAction(JumpLeftanimate);
				}
			}
		}
		isJumping1 = false;
	}

}

void Scene2::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	for (int i = 1; i <= 4; i++)
	{
		sprite1->stopActionByTag(i);
	}
	isWalking1 = false;
	if (isRight1) {
		sprite1->setTexture("Adv.png");
		sprite1->setTextureRect(Rect(1, 33, 137, 131));
	}
	else {
		sprite1->setTexture("Adv.png");
		sprite1->setTextureRect(Rect(18, 1264, 137, 131));
	}
	jumpForce1 = 10;
}


void Scene2::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
