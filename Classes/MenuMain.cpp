/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* MenuMain::createScene()
{
	return MenuMain::create();
}
// on "init" you need to initialize your instance
bool MenuMain::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	Director::getInstance()->getOpenGLView()->setFrameSize(900, 600);
	Director::getInstance()->getOpenGLView()->setDesignResolutionSize(900, 600, ResolutionPolicy::EXACT_FIT);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Point pos = Point(20, (visibleSize.height / 2) - 150);

	


	//auto StartButton=Button


	/////////////////////////////////////////////////////////////////////////////////рср ъ охььсссссс

	auto menu_Item_1 = MenuItemFont::create("Play", CC_CALLBACK_1(MenuMain::Play, this));
	auto menu_Item_2 = MenuItemFont::create("Highscores", CC_CALLBACK_1(MenuMain::Highscores, this));
	auto menu_Item_3 = MenuItemFont::create("Settings", CC_CALLBACK_1(MenuMain::Settings, this));
	auto menu_Item_4 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(MenuMain::ImageButton, this));
	/*
	menu_Item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 4));
	menu_Item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 3));
	menu_Item_3->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 2));
	menu_Item_4->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 1));
	*/
	////tut ne to
	auto *menu = Menu::create(menu_Item_1, menu_Item_2, menu_Item_3, menu_Item_4, NULL);
	//menu->setPosition(Point(0, 0));
	menu->alignItemsVertically();
	this->addChild(menu);

	return true;
}

/////////////рср ъ охьсссс
void MenuMain::Play(cocos2d::Ref *pSpender)
{
	CCLOG("Play");
	//auto scene = NewScene::createScene();
	//Director::getInstance()->pushScene(scene);
	auto scene = HelloWorld::createScene();
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
}

void MenuMain::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	sprite1->stopAllActions();
}


void MenuMain::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

