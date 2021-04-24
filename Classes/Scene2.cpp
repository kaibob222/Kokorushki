#include "Scene2.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"
#include "Anime.h"
#include "Hero.h"

USING_NS_CC;

int q;
bool motion = false;

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

	auto mySprite = Sprite::create("enemy/Skel.png");
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(10);
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(0, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(173, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(173, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(173, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(346, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(346, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(346, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(346, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(346, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(519, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(519, 0, 170, 251)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(0, 0, 170, 251)));
	/*animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(380, 33, 138, 230)));*/
	/*animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(700, 33, 150, 220)));
	animFrames.pushBack(SpriteFrame::create("enemy/Skel.png", Rect(1, 33, 150, 220)));*/

	mySprite->setPosition(Point(600, 205));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	mySprite->runAction(RepeatForever::create(animate));

	/*sprite2 = Sprite::create("enemy/Skel.png", Rect(1, 33, 170, 220));
	sprite2->setPosition(Point(600, 205));*/

	this->addChild(sprite1);
	this->addChild(mySprite);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Scene2::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Scene2::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	auto menu_Item_1 = MenuItemFont::create("Exit", CC_CALLBACK_1(Scene2::Exit, this));
	auto *menu = Menu::create(menu_Item_1, NULL);
	menu->alignItemsVertically();
	menu->setPosition(Point(850, 570));
	this->addChild(menu);

	this->scheduleUpdate();

	return true;
}

void Scene2::update(float dt) {
	Point pos = sprite1->getPosition();
	/*Point pos1 = sprite2->getPosition();*/

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
		for (int i = 1; i <= 8; i++)
		{
			sprite1->stopActionByTag(i);
		}
		Hero::goRight(sprite1);
	}
	if ((int)keyCode == 124 || (int)keyCode == 26)//keys A or <- pressed
	{
		for (int i = 1; i <= 8; i++)
		{
			sprite1->stopActionByTag(i);
		}
		Hero::goLeft(sprite1);
	}
	if ((int)keyCode == 133)//key J pressed
	{
		for (int i = 1; i <= 8; i++)
		{
			sprite1->stopActionByTag(i);
		}
		Hero::heroPunch(sprite1);
	}
	if ((int)keyCode == 59)//key Space was pressed
	{
		Hero::heroJump(sprite1);
	}
	if ((int)keyCode == 164)//key Enter was pressed
	{
		Hero::heroHurt(sprite1);
	}
	if ((int)keyCode == 139)//key Enter was pressed
	{
		Hero::heroDeath(sprite1);
	}
}

void Scene2::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	for (int i = 1; i <= 4; i++)
	{
		sprite1->stopActionByTag(i);
	}
	Hero::heroStop(sprite1);
}

void Scene2::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
