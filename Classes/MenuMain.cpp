#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* MenuMain::createScene()
{
	return MenuMain::create();
}

int musMenu;
bool MenuMain::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	//music
	musMenu = AudioEngine::play2d("menu1.mp3", true, 1.0);

	Director::getInstance()->getOpenGLView()->setFrameSize(900, 600);
	Director::getInstance()->getOpenGLView()->setDesignResolutionSize(900, 600, ResolutionPolicy::EXACT_FIT);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Point pos = Point(20, (visibleSize.height / 2) - 150);

	auto menu_Item_1 = MenuItemFont::create("Play", CC_CALLBACK_1(MenuMain::Play, this));
	auto menu_Item_2 = MenuItemFont::create("Highscores", CC_CALLBACK_1(MenuMain::Highscores, this));
	auto menu_Item_3 = MenuItemFont::create("Settings", CC_CALLBACK_1(MenuMain::Settings, this));
	auto menu_Item_4 = MenuItemImage::create("CloseNormal2.png", "CloseNormal2.png", CC_CALLBACK_1(MenuMain::ImageButton, this));
	
	auto *menu = Menu::create(menu_Item_1, menu_Item_2, menu_Item_3, menu_Item_4, NULL);
	
	menu->alignItemsVertically();
	this->addChild(menu);

	return true;
}

void MenuMain::Play(cocos2d::Ref *pSpender)
{
	CCLOG("Play");
	auto scene = HelloWorld::createScene();
	AudioEngine::stop(musMenu);
	Director::getInstance()->replaceScene(scene);
}

void MenuMain::Highscores(cocos2d::Ref *pSpender)
{
	CCLOG("Highscores");
}

void MenuMain::Settings(cocos2d::Ref *pSpender)
{
	CCLOG("Settings");
}

void MenuMain::ImageButton(cocos2d::Ref *pSpender)
{
	CCLOG("Image Button");
	Director::getInstance()->end();
}

void MenuMain::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	sprite1->stopAllActions();
}


void MenuMain::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}