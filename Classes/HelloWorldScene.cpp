#include "HelloWorldScene.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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

	auto sprite = Sprite::create("lightforest.jpg");
	if (sprite == nullptr)
	{
		problemLoading("'lightforest.jpg'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
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

	sprite1 = Sprite::create("player/Programmer7.png");
	sprite1->setPosition(pos);

	this->addChild(sprite1);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);// if you are using cocos2d-x 3.0alpha.1 and later!// if you are using cocos2d-x 3.0alpha.1 and later!

	auto menu_Item_1 = MenuItemFont::create("Exit", CC_CALLBACK_1(HelloWorld::Exit, this));
	auto *menu = Menu::create(menu_Item_1, NULL);
	menu->alignItemsVertically();
	menu->setPosition(Point(850, 570));
	this->addChild(menu);


	return true;
}

void HelloWorld::Exit(cocos2d::Ref *pSpender)
{
	CCLOG("Exit");
	auto scene = MenuMain::createScene();
	Director::getInstance()->replaceScene(scene);
	//Director::getInstance()->pause();
	//Director::getInstance()->popScene();
}
/*
void HelloWorld::Pause(cocos2d::Ref *pSpender)
{
	CCLOG("Pause");
	Director::getInstance()->pause();
}

void HelloWorld::Start(cocos2d::Ref *pSpender)
{
	CCLOG("Start");
	Director::getInstance()->startAnimation();
}
*/
void HelloWorld::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	CCLOG("Key with keycode %d pressed", keyCode);
	Vector<SpriteFrame*> animRightWalk;
	animRightWalk.reserve(7);
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer7.png", Rect(0, -4.5, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer71.png", Rect(1, 0, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer72.png", Rect(0, 1, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer73.png", Rect(1, 0, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer74.png", Rect(0, 1, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer75.png", Rect(1, 0, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer76.png", Rect(0, 1, 64, 128)));
	Animation* animation = Animation::createWithSpriteFrames(animRightWalk, 0.1f);
	Animate* animate = Animate::create(animation);
	Vector<SpriteFrame*> animLeftWalk;
	animLeftWalk.reserve(7);
	animLeftWalk.pushBack(SpriteFrame::create("player/Programmer3.png", Rect(-3.75, -4.2, 64, 128)));
	animLeftWalk.pushBack(SpriteFrame::create("player/Programmer31.png", Rect(1, 0, 64, 128)));
	animLeftWalk.pushBack(SpriteFrame::create("player/Programmer32.png", Rect(0, 1, 64, 128)));
	animLeftWalk.pushBack(SpriteFrame::create("player/Programmer33.png", Rect(1, 0, 64, 128)));
	animLeftWalk.pushBack(SpriteFrame::create("player/Programmer34.png", Rect(0, 1, 64, 128)));
	animLeftWalk.pushBack(SpriteFrame::create("player/Programmer35.png", Rect(1, 0, 64, 128)));
	animLeftWalk.pushBack(SpriteFrame::create("player/Programmer36.png", Rect(0, 1, 64, 128)));
	Animation* animation1 = Animation::createWithSpriteFrames(animLeftWalk, 0.1f);
	Animate* animate1 = Animate::create(animation1);
	if ((int)keyCode == 127)//key D was pressed
	{
		ActionInterval* move = MoveBy::create(0.5, Point(30, 0));
		sprite1->runAction(RepeatForever::create(Sequence::create(move, move, NULL)));
		sprite1->runAction(RepeatForever::create(animate));
		sprite1->setTexture("player/Programmer7.png");
	}
	if ((int)keyCode == 124)//key A was pressed
	{
		ActionInterval* move = MoveBy::create(0.5, Point(-30, 0));
		sprite1->runAction(RepeatForever::create(Sequence::create(move, move, NULL)));
		sprite1->runAction(RepeatForever::create(animate1));
		sprite1->setTexture("player/Programmer3.png");
	}
}

void HelloWorld::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	sprite1->stopAllActions();
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}