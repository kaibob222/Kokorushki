#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"
#include "AudioEngine.h"
#include "JsonAdapter.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* MenuMain::createScene()
{
	return MenuMain::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
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

	///

	auto backgroundMenu = Sprite::create("0.png");
	backgroundMenu->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	/*this->addChild(backgroundMenu, 0);*/
	Vector<SpriteFrame*> animFrames;

	animFrames.reserve(19);
	animFrames.pushBack(SpriteFrame::create("backMenu/0.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/1.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/2.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/3.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/4.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/5.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/6.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/7.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/8.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/9.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/10.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/11.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/12.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/13.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/14.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/15.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/16.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/17.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/18.png", Rect(0, 0, 1000, 600)));
	animFrames.pushBack(SpriteFrame::create("backMenu/19.png", Rect(0, 0, 1000, 600)));

	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	backgroundMenu->runAction(RepeatForever::create(animate));
	this->addChild(backgroundMenu);



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
	JsonAdapter::JsonInit(1);
	/*auto scene = JsonAdapter::createScene();
	Director::getInstance()->replaceScene(scene);*/
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