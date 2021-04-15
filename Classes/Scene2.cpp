#include "Scene2.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"

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

	auto background = Sprite::create("forest.jpg");
	if (background == nullptr)
	{
		problemLoading("'forest.jpg'");
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

	sprite1 = Sprite::create("player/Programmer7.png");
	sprite1->setPosition(Point(20, 150));
	sprite2 = Sprite::create("enemy/enemy2.png");
	sprite2->setPosition(Point(600, 160));

	/*auto spriteBody = PhysicsBody::createCircle(sprite1->getContentSize().width, PhysicsMaterial(0, 1, 0));
	sprite1->setPhysicsBody(spriteBody);*/

	this->addChild(sprite1);
	this->addChild(sprite2);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Scene2::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Scene2::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);// if you are using cocos2d-x 3.0alpha.1 and later!// if you are using cocos2d-x 3.0alpha.1 and later!

	auto menu_Item_1 = MenuItemFont::create("Exit", CC_CALLBACK_1(Scene2::Exit, this));
	auto *menu = Menu::create(menu_Item_1, NULL);
	menu->alignItemsVertically();
	menu->setPosition(Point(850, 570));
	this->addChild(menu);

	this->scheduleUpdate();

	return true;
}

bool isJumping1 = false;
bool isRight1 = false;
float jumpForce1 = 10;
int maxJump1 = 30;
bool grounded1 = true;
bool moveRight1 = false;
bool moveLeft1 = false;
bool goDown1 = false;

void Scene2::update(float dt) {
	Point pos = sprite1->getPosition();
	Point pos1 = sprite2->getPosition();

	if (sprite1->getPosition() < Point(10, 150)|| sprite2->getPosition() < Point(10, 150)) {
		q = 1;
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	}

	if (isJumping1)
	{
		if (jumpForce1 < maxJump1)
		{
			sprite1->setPosition(Point(pos.x, pos.y + jumpForce1));
			jumpForce1 += 2.5;
		}
		else
		{
			isJumping1 = false;
			goDown1 = true;
		}
	}
	if (isJumping1 == false && pos.y > 150)
	{
		goDown1 = true;
		grounded1 = false;
	}
	else
	{
		if (pos.y == 150)
		{
			goDown1 = false;
			grounded1 = true;
			moveRight1 = false;  
			moveLeft1 = false;
		}
	}
	Point gravity = Point(0, -2.5);
	if (goDown1) {
		if (pos.y > 150)
		{
			sprite1->setPosition(pos.x+gravity.x, pos.y + gravity.y);
			grounded1 = false;
		}
		else
		{
			if (pos.y == 150)
			{
				isJumping1 = false;
				goDown1 = false;
				grounded1 = true;
			}
		}

	}
	/*if (moveRight) {
		sprite1->setPosition(pos.x+20, pos.y+gravity.y);
		moveRight = false;
		goDown = true;
	}
	/*if (isJumping && jumpForce < maxJump) {
		ActionInterval* jump = JumpTo::create(0.5, Point(pos.x, pos.y), jumpForce++, 1);
		sprite1->runAction(jump);
	}*/
	/*if (pos.y <= 150 && pos.y >= 140) {
		grounded = true;
		moveLeft = false;
		moveRight = false;
	}
	else {
		grounded = false;
	}*/
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
	Vector<SpriteFrame*> animRightWalk;
	animRightWalk.reserve(7);
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer7.png", Rect(0, -4.5, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer71.png", Rect(1, 0, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer72.png", Rect(0, 1, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer73.png", Rect(1, 0, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer74.png", Rect(0, 1, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer75.png", Rect(1, 0, 64, 128)));
	animRightWalk.pushBack(SpriteFrame::create("player/Programmer76.png", Rect(0, 1, 64, 128)));
	Animation* animation = Animation::createWithSpriteFrames(animRightWalk, 0.05f);
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
	Animation* animation1 = Animation::createWithSpriteFrames(animLeftWalk, 0.05f);
	Animate* animate1 = Animate::create(animation1);
	Point pos = sprite1->getPosition();
	Point pos1 = sprite2->getPosition();
	if ((int)keyCode == 127 || (int)keyCode == 27)//keys D or -> pressed
	{
		isRight1 = true;
		if (grounded1)
		{
			ActionInterval* move = MoveBy::create(0.15, Point(50, 0));
			sprite1->runAction(RepeatForever::create(Sequence::create(move, move, NULL)));
			sprite1->runAction(RepeatForever::create(animate));
		}
		else {
			moveRight1 = true;
		}
	}
	if ((int)keyCode == 124 || (int)keyCode == 26)//keys A or <- pressed
	{
		isRight1 = false;
		if (grounded1)
		{
			ActionInterval* move = MoveBy::create(0.15, Point(-50, 0));
			sprite1->runAction(RepeatForever::create(Sequence::create(move, move, NULL)));
			sprite1->runAction(RepeatForever::create(animate1));
		}
		else {
			moveLeft1 = true;
		}
	}
	if ((int)keyCode == 59)//key Space was pressed
	{
		isJumping1 = true;
	}

	
}

void Scene2::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (isJumping1 == false) sprite1->stopAllActions();

	if (isJumping1 == true)
	{
		goDown1 = true;
		isJumping1 = false;
	}
	if (isRight1) {
		sprite1->setTexture("player/Programmer7.png");
	}
	else {
		sprite1->setTexture("player/Programmer7.png");
	}
	jumpForce1 = 10;
}


void Scene2::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
