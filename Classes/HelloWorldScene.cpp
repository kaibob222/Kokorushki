#include "HelloWorldScene.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "Scene2.h"

USING_NS_CC;

extern int q;

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
	
	sprite1 = Sprite::create("Adv.png", Rect(30, 50, 110, 150));
	sprite1->setPosition(Point(50, 150));

	if (q == 1) {
		sprite1->setPosition(Point(900, 110));
		q = 0;
	}

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

	this->scheduleUpdate();
	return true;
}

bool isJumping = false;
bool isRight = false;
float jumpForce = 10;
int maxJump = 40;
bool isWalking = false;
//bool grounded = true;
bool isPunching = false;
bool moveRight = false;
bool moveLeft = false;
bool goDown = false;
float HeroWidth = 110;
float HeroHeight = 145;

void HelloWorld::update(float dt) {
	Point pos = sprite1->getPosition();

	if (sprite1->getPosition() > Point(900, 110)) {
		auto scene = Scene2::createScene();
		Director::getInstance()->replaceScene(scene);
	}

	if (isJumping && !isWalking)
	{
		if (jumpForce < maxJump)
		{
			sprite1->setPosition(Point(pos.x, pos.y + jumpForce));
			jumpForce += 5;
		}
		else
		{
			isJumping = false;
			goDown = true;
		}
	}
	if (isJumping == false && pos.y > 110)
	{
		goDown = true;
		//grounded = false;
	}
	else
	{
		if (pos.y == 110)
		{
			goDown = false;
			//grounded = true;
			moveRight = false;  
			moveLeft = false;
		}
	}
	Point gravity = Point(0, -5);
	if (goDown) {
		if (pos.y > 110)
		{
			sprite1->setPosition(pos.x+gravity.x, pos.y + gravity.y);
			//grounded = false;
		}
		else
		{
			if (pos.y == 110)
			{
				isJumping = false;
				goDown = false;
				//grounded = true;
			}
		}

	}
	/*if (moveRight) {
		if (pos.y > 150)
		{
			float x = 2.5;
			float y = 2 * x;
			sprite1->setPosition(pos.x + x, pos.y - y);
			x -= 0.5;
			//moveRight = false;
			//goDown = true;
		}
		//moveRight = false;
		//goDown = true;
	}*/
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

void HelloWorld::Exit(cocos2d::Ref *pSpender)
{
	CCLOG("Exit");
	auto scene = MenuMain::createScene();
	Director::getInstance()->replaceScene(scene);
}

void HelloWorld::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	CCLOG("Key with keycode %d pressed", keyCode);
	Vector<SpriteFrame*> animRightWalk;
	animRightWalk.reserve(8);
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(20, 195, HeroWidth, HeroHeight)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(175, 195, HeroWidth, HeroHeight)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(330, 195, HeroWidth, HeroHeight)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(494, 195, HeroWidth, HeroHeight)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(648, 195, HeroWidth, HeroHeight)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(805, 195, HeroWidth, HeroHeight)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(955, 195, HeroWidth, HeroHeight)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(1110, 195, HeroWidth, HeroHeight)));
	Animation* animation = Animation::createWithSpriteFrames(animRightWalk, 0.05f);
	Animate* animate = Animate::create(animation);
	Vector<SpriteFrame*> animLeftWalk;
	animLeftWalk.reserve(8);
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(40, 1428, HeroWidth, HeroHeight)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(197, 1428, HeroWidth, HeroHeight)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(350, 1428, HeroWidth, HeroHeight)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(511, 1428, HeroWidth, HeroHeight)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(670, 1428, HeroWidth, HeroHeight)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(822, 1428, HeroWidth, HeroHeight)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(975, 1428, HeroWidth, HeroHeight)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(1128, 1428, HeroWidth, HeroHeight)));
	Animation* animation1 = Animation::createWithSpriteFrames(animLeftWalk, 0.05f);
	Animate* animate1 = Animate::create(animation1);
	Point pos = sprite1->getPosition();
	if ((int)keyCode == 127 || (int)keyCode == 27)//keys D or -> pressed
	{
		isWalking = true;
		isRight = true;
		if (!isJumping)//(grounded)
		{
			ActionInterval* move = MoveBy::create(0.15, Point(50, 0));
			sprite1->runAction(RepeatForever::create(Sequence::create(move, move, NULL)));
			sprite1->runAction(RepeatForever::create(animate));
		}
		else {
			moveRight = true;
		}
	}
	if ((int)keyCode == 124 || (int)keyCode == 26)//keys A or <- pressed
	{
		isWalking = true;
		isRight = false;
		if (!isJumping)//(grounded)
		{
			ActionInterval* move = MoveBy::create(0.15, Point(-50, 0));
			sprite1->runAction(RepeatForever::create(Sequence::create(move, move, NULL)));
			sprite1->runAction(RepeatForever::create(animate1));
		}
		else {
			moveLeft = true;
		}
	}
	if ((int)keyCode == 133)//key J pressed
	{
		isPunching = true;
		Vector<SpriteFrame*> punch;
		punch.reserve(10);
		punch.pushBack(SpriteFrame::create("Adv.png", Rect(27, 360, HeroWidth, HeroHeight)));
		punch.pushBack(SpriteFrame::create("Adv.png", Rect(177, 360, HeroWidth + 20, HeroHeight)));
		punch.pushBack(SpriteFrame::create("Adv.png", Rect(331, 348, HeroWidth + 20, HeroHeight)));
		punch.pushBack(SpriteFrame::create("Adv.png", Rect(485, 343, HeroWidth + 20, HeroHeight)));
		punch.pushBack(SpriteFrame::create("Adv.png", Rect(635, 347, HeroWidth + 20, HeroHeight)));
		punch.pushBack(SpriteFrame::create("Adv.png", Rect(791, 355, HeroWidth + 20, HeroHeight)));
		punch.pushBack(SpriteFrame::create("Adv.png", Rect(947, 356, HeroWidth + 20, HeroHeight)));
		punch.pushBack(SpriteFrame::create("Adv.png", Rect(1100, 356, HeroWidth, HeroHeight)));
		punch.pushBack(SpriteFrame::create("Adv.png", Rect(1256, 360, HeroWidth, HeroHeight)));
		punch.pushBack(SpriteFrame::create("Adv.png", Rect(1410, 356, HeroWidth, HeroHeight)));
		Animation* punchanimation = Animation::createWithSpriteFrames(punch, 0.15f);
		Animate* punchanimate = Animate::create(punchanimation);
		sprite1->runAction(punchanimate);
		isPunching = false;
	}
	if ((int)keyCode == 59)//key Space was pressed
	{
		isJumping = true;
		if (isRight && isWalking)
		{
			Vector<SpriteFrame*> animRightJump;
			animRightJump.reserve(6);
			animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(27, 820, HeroWidth, HeroHeight)));
			animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(173, 820, HeroWidth, HeroHeight)));
			animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(332, 810, HeroWidth, HeroHeight)));
			animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(489, 798, HeroWidth, HeroHeight)));
			animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(635, 800, HeroWidth, HeroHeight)));
			animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(787, 820, HeroWidth, HeroHeight)));
			Animation* Jumpanimation = Animation::createWithSpriteFrames(animRightJump, 1.0f);
			Animate* Jumpanimate = Animate::create(Jumpanimation);
			Point pos1 = sprite1->getPosition();
			ActionInterval* jump = JumpTo::create(1, Point(pos.x + 30, pos.y), 50, 1);
			sprite1->runAction(jump);
			sprite1->runAction(Jumpanimate);
		}
	}
	
}

void HelloWorld::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (!isJumping)
	{
		sprite1->stopAllActions();//solve it
	}
	isWalking = false;
	if (isJumping)
	{
		goDown = true;
		isJumping = false;
	}
	if (isRight) {
		sprite1->setTexture("Adv.png");
		sprite1->setTextureRect(Rect(20, 50, HeroWidth, HeroHeight));
	}
	else {
		sprite1->setTexture("Adv.png");
		sprite1->setTextureRect(Rect(47, 1593, HeroWidth, HeroHeight));
	}
	jumpForce = 10;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
