#include "GameOver.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"
#include "Scene2.h"
#include "Win.h"
USING_NS_CC;

Scene* Win::createScene()
{
	return Win::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool Win::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Director::getInstance()->getOpenGLView()->setFrameSize(900, 600);
	Director::getInstance()->getOpenGLView()->setDesignResolutionSize(900, 600, ResolutionPolicy::EXACT_FIT);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto background = Sprite::create("victory.jpg");
	background->setScaleX(1.3);
	background->setScaleY(1.3);
	if (background == nullptr)
	{
		problemLoading("'gameover.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(background, 0);
	}
	auto menu_Item_1 = MenuItemFont::create("Menu", CC_CALLBACK_1(Win::Menu, this));
	auto *menu = Menu::create(menu_Item_1, NULL);
	menu->setPosition(Point(450, 240));
	this->addChild(menu);

	return true;
}

void Win::Menu(cocos2d::Ref *pSpender)
{
	CCLOG("Menu");
	auto scene = MenuMain::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Win::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	sprite1->stopAllActions();
}


void Win::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}