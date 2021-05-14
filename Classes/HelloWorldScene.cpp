#include "HelloWorldScene.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "Scene2.h"
#include "GameOver.h"
#include "Anime.h"
#include "Hero.h"

USING_NS_CC;

extern int q;
extern int xp;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Director::getInstance()->getOpenGLView()->setFrameSize(900, 600);
	Director::getInstance()->getOpenGLView()->setDesignResolutionSize(900, 600, ResolutionPolicy::EXACT_FIT);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("2.png");
	if (background == nullptr)
	{
		problemLoading("'2.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(background, 0);
	}
	
	auto label = Label::createWithTTF("SCENE 1", "fonts/Marker Felt.ttf", 24);
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

	if (q == 0) {
		sprite1 = Sprite::create("Adv.png", Rect(1, 33, 137, 131));
		sprite1->setPosition(Point(50, 150));
		q = 0;
	}
	if (q == 1) {
		sprite1 = Sprite::create("Adv.png", Rect(18, 1264, 137, 131));
		sprite1->setPosition(Point(880, 150));
		q = 0;
	}

	this->addChild(sprite1);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);// if you are using cocos2d-x 3.0alpha.1 and later!// if you are using cocos2d-x 3.0alpha.1 and later!

	auto menu_Item_1 = MenuItemFont::create("Exit", CC_CALLBACK_1(HelloWorld::Exit, this));
	//auto menu_Item_0 = MenuItemFont::create("Pause", CC_CALLBACK_1(HelloWorld::Pause, this));
	auto menu_Item_2 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
	auto menu_Item_3 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
	auto menu_Item_4 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));

	auto *menu = Menu::create(menu_Item_1, NULL);
	//auto *menu0 = Menu::create(menu_Item_0, NULL);
	auto *menu2 = Menu::create(menu_Item_2, NULL);
	auto *menu3 = Menu::create(menu_Item_3, NULL);
	auto *menu4 = Menu::create(menu_Item_4, NULL);
	//menu->alignItemsVertically();
	menu->setPosition(Point(850, 570));
	//menu0->setPosition(Point(750, 570));
	menu2->setPosition(Point(20, 570));
	menu3->setPosition(Point(60, 570));
	menu4->setPosition(Point(100, 570));
	this->addChild(menu);
	//this->addChild(menu0);
	this->addChild(menu2);
	this->addChild(menu3);
	this->addChild(menu4);
	this->scheduleUpdate();

	if (xp == 2) {
		auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
		auto *menu4 = Menu::create(menu_Item_4, NULL);
		menu4->setPosition(Point(100, 570));
		this->addChild(menu4);
	}
	if (xp == 1) {
		auto menu_Item_3 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
		auto *menu3 = Menu::create(menu_Item_3, NULL);
		auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
		auto *menu4 = Menu::create(menu_Item_4, NULL);
		menu3->setPosition(Point(60, 570));
		menu4->setPosition(Point(100, 570));
		this->addChild(menu3);
		this->addChild(menu4);
	}

	return true;
}

void HelloWorld::Heart(cocos2d::Ref *pSpender)
{
	CCLOG("Image Button");
}

void HelloWorld::update(float dt) {
	Point pos = sprite1->getPosition();

	if (pos > Point(880, 150)) {
		auto scene = Scene2::createScene();
		Director::getInstance()->replaceScene(scene);
	}
}

void HelloWorld::Exit(cocos2d::Ref *pSpender)
{
	CCLOG("Exit");
	auto scene = MenuMain::createScene();
	Director::getInstance()->replaceScene(scene);
}

/*void HelloWorld::Pause(cocos2d::Ref *pSpender)
{
	CCLOG("Pause");
	//auto pausedSet = this->getScheduler()->pauseAllTargets();
	Director::getInstance()->pause();
}*/

void HelloWorld::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	CCLOG("Key with keycode %d pressed", keyCode);
	Point pos = sprite1->getPosition();
	if ((int)keyCode == 164)
	{
		xp--;
		if (xp == 2) {
			auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
			auto *menu4 = Menu::create(menu_Item_4, NULL);
			menu4->setPosition(Point(100, 570));
			this->addChild(menu4);
			Hero::heroHurt(sprite1);
		}
		if (xp == 1) {
			auto menu_Item_3 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
			auto *menu3 = Menu::create(menu_Item_3, NULL);
			menu3->setPosition(Point(60, 570));
			this->addChild(menu3);
			Hero::heroHurt(sprite1);
		}
		if (xp == 0) {
			auto menu_Item_2 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
			auto *menu2 = Menu::create(menu_Item_2, NULL);
			menu2->setPosition(Point(20, 570));
			this->addChild(menu2);
			Hero::heroDeath(sprite1);
			xp = 3;
			auto scene = GameOver::createScene();
			Director::getInstance()->replaceScene(scene);
		}
	}


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
	/*if ((int)keyCode == 164)//key Enter was pressed
	{
		Hero::heroHurt(sprite1);
	}*/
	if ((int)keyCode == 139)//key Enter was pressed
	{
		Hero::heroDeath(sprite1);
	}
}

void HelloWorld::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	for (int i = 1; i <= 4; i++)
	{
		sprite1->stopActionByTag(i);
	}
	Hero::heroStop(sprite1);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
