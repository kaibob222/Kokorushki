#include "Scene2.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"
#include "GameOver.h"

USING_NS_CC;

int q;
int xp = 3;

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

	//sprite1 = Sprite::create("player/Programmer7.png");
	//sprite1->setPosition(Point(20, 150));
	//sprite1 = Sprite::create("Adv.png", Rect(20, 50, 110, 145));
	//sprite1->setPosition(Point(50, 110));
	sprite1 = Sprite::create("Adv.png", Rect(1, 33, 137, 131));
	sprite1->setPosition(Point(50, 150));
	sprite2 = Sprite::create("enemy/enemy2.png");
	sprite2->setPosition(Point(600, 185));

	/*auto spriteBody = PhysicsBody::createCircle(sprite1->getContentSize().width, PhysicsMaterial(0, 1, 0));
	sprite1->setPhysicsBody(spriteBody);*/

	this->addChild(sprite1);
	this->addChild(sprite2);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Scene2::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Scene2::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);// if you are using cocos2d-x 3.0alpha.1 and later!// if you are using cocos2d-x 3.0alpha.1 and later!

	auto menu_Item_1 = MenuItemFont::create("Exit", CC_CALLBACK_1(Scene2::Exit, this));
	auto menu_Item_2 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
	auto menu_Item_3 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
	auto menu_Item_4 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
	
	auto *menu = Menu::create(menu_Item_1, NULL);
	menu->alignItemsVertically();
	auto *menu2 = Menu::create(menu_Item_2, NULL);
	auto *menu3 = Menu::create(menu_Item_3, NULL);
	auto *menu4 = Menu::create(menu_Item_4, NULL);
	menu->setPosition(Point(850, 570));
	menu2->setPosition(Point(20, 570));
	menu3->setPosition(Point(60, 570));
	menu4->setPosition(Point(100, 570));
	this->addChild(menu);
	this->addChild(menu2);
	this->addChild(menu3);
	this->addChild(menu4);

	this->scheduleUpdate();

	if (xp == 2) {
		auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
		auto *menu4 = Menu::create(menu_Item_4, NULL);
		menu4->setPosition(Point(100, 570));
		this->addChild(menu4);
	}
	if (xp == 1) {
		auto menu_Item_3 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
		auto *menu3 = Menu::create(menu_Item_3, NULL);
		menu3->setPosition(Point(60, 570));
		this->addChild(menu3);
		auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
		auto *menu4 = Menu::create(menu_Item_4, NULL);
		menu4->setPosition(Point(100, 570));
		this->addChild(menu4);
	}

	return true;
}

void Scene2::Heart(cocos2d::Ref *pSpender)
{
	CCLOG("Image Button");
}

bool isJumping1 = false;
bool isRight1 = false;
float jumpForce1 = 10;
int maxJump1 = 40;
bool isWalking1 = false;
//bool grounded = true;
bool isPunching1 = false;
bool moveRight1 = false;
bool moveLeft1 = false;
bool goDown1 = false;
float HeroWidth1 = 137;
float HeroHeight1 = 131;

void Scene2::update(float dt) {
	Point pos = sprite1->getPosition();
	Point pos1 = sprite2->getPosition();

	if (pos < Point(50, 150)) {
		q = 1;
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	}

	/*if (isJumping && !isWalking)
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
	animRightWalk.reserve(8);
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(1, 180, HeroWidth1, HeroHeight1)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(150, 180, HeroWidth1, HeroHeight1)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(305, 180, HeroWidth1, HeroHeight1)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(460, 180, HeroWidth1, HeroHeight1)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(613, 180, HeroWidth1, HeroHeight1)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(768, 180, HeroWidth1, HeroHeight1)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(920, 180, HeroWidth1, HeroHeight1)));
	animRightWalk.pushBack(SpriteFrame::create("Adv.png", Rect(1077, 180, HeroWidth1, HeroHeight1)));
	Animation* animation = Animation::createWithSpriteFrames(animRightWalk, 0.05f);
	Animate* animate = Animate::create(animation);
	Vector<SpriteFrame*> animLeftWalk;
	animLeftWalk.reserve(8);
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(19, 1412, HeroWidth1, HeroHeight1)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(172, 1412, HeroWidth1, HeroHeight1)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(324, 1412, HeroWidth1, HeroHeight1)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(478, 1412, HeroWidth1, HeroHeight1)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(634, 1412, HeroWidth1, HeroHeight1)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(787, 1412, HeroWidth1, HeroHeight1)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(941, 1412, HeroWidth1, HeroHeight1)));
	animLeftWalk.pushBack(SpriteFrame::create("Adv.png", Rect(1095, 1412, HeroWidth1, HeroHeight1)));
	Animation* animation1 = Animation::createWithSpriteFrames(animLeftWalk, 0.05f);
	Animate* animate1 = Animate::create(animation1);
	Point pos = sprite1->getPosition();
	if ((int)keyCode == 164)
	{
		xp--;
		if (xp == 2) {
			auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
			auto *menu4 = Menu::create(menu_Item_4, NULL);
			menu4->setPosition(Point(100, 570));
			this->addChild(menu4);
		}
		if (xp == 1) {
			auto menu_Item_3 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
			auto *menu3 = Menu::create(menu_Item_3, NULL);
			menu3->setPosition(Point(60, 570));
			this->addChild(menu3);
		}
		if (xp == 0) {
			auto menu_Item_2 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(Scene2::Heart, this));
			auto *menu2 = Menu::create(menu_Item_2, NULL);
			menu2->setPosition(Point(20, 570));
			this->addChild(menu2);
			xp = 3;
			auto scene = GameOver::createScene();
			Director::getInstance()->replaceScene(scene);
		}
	}

	if ((int)keyCode == 127 || (int)keyCode == 27)//keys D or -> pressed
	{
		if (isPunching1)
		{
			Vector<SpriteFrame*> nopunch;
			nopunch.reserve(3);
			nopunch.pushBack(SpriteFrame::create("Adv.png", Rect(1077, 344, HeroWidth1, HeroHeight1)));
			nopunch.pushBack(SpriteFrame::create("Adv.png", Rect(1228, 344, HeroWidth1, HeroHeight1)));
			nopunch.pushBack(SpriteFrame::create("Adv.png", Rect(1384, 344, HeroWidth1, HeroHeight1)));
			Animation* nopunchanimation = Animation::createWithSpriteFrames(nopunch, 0.15f);
			Animate* nopunchanimate = Animate::create(nopunchanimation);
			sprite1->runAction(nopunchanimate);
			isPunching1 = false;
		}
		isWalking1 = true;
		isRight1 = true;
		if (!isJumping1)//(grounded)
		{
			ActionInterval* move = MoveBy::create(0.15, Point(50, 0));
			auto repeatForever = cocos2d::RepeatForever::create(Sequence::create(move, move, NULL));
			repeatForever->setTag(1);
			sprite1->runAction(repeatForever);
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
		if (isPunching1)
		{
			Vector<SpriteFrame*> noLeftpunch;
			noLeftpunch.reserve(3);
			noLeftpunch.pushBack(SpriteFrame::create("Adv.png", Rect(1087, 1727, HeroWidth1, HeroHeight1)));
			noLeftpunch.pushBack(SpriteFrame::create("Adv.png", Rect(1244, 1727, HeroWidth1, HeroHeight1)));
			noLeftpunch.pushBack(SpriteFrame::create("Adv.png", Rect(1398, 1727, HeroWidth1, HeroHeight1)));
			Animation* noLeftpunchanimation = Animation::createWithSpriteFrames(noLeftpunch, 0.15f);
			Animate* noLeftpunchanimate = Animate::create(noLeftpunchanimation);
			sprite1->runAction(noLeftpunchanimate);
			isPunching1 = false;
		}
		isWalking1 = true;
		isRight1 = false;
		if (!isJumping1)//(grounded)
		{
			ActionInterval* move1 = MoveBy::create(0.15, Point(-50, 0));
			auto repeatForever1 = cocos2d::RepeatForever::create(Sequence::create(move1, move1, NULL));
			repeatForever1->setTag(3);
			sprite1->runAction(repeatForever1);
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
		if (!isPunching1)
		{
			if (isRight1)
			{
				Vector<SpriteFrame*> punch;
				punch.reserve(7);//137.131
				punch.pushBack(SpriteFrame::create("Adv.png", Rect(3, 344, HeroWidth1, HeroHeight1)));
				punch.pushBack(SpriteFrame::create("Adv.png", Rect(165, 344, HeroWidth1, HeroHeight1)));
				punch.pushBack(SpriteFrame::create("Adv.png", Rect(327, 344, HeroWidth1, HeroHeight1)));
				punch.pushBack(SpriteFrame::create("Adv.png", Rect(475, 344, HeroWidth1, HeroHeight1)));
				punch.pushBack(SpriteFrame::create("Adv.png", Rect(631, 344, HeroWidth1, HeroHeight1)));
				punch.pushBack(SpriteFrame::create("Adv.png", Rect(785, 344, HeroWidth1, HeroHeight1)));
				punch.pushBack(SpriteFrame::create("Adv.png", Rect(935, 344, HeroWidth1, HeroHeight1)));
				Animation* punchanimation = Animation::createWithSpriteFrames(punch, 0.15f);
				Animate* punchanimate = Animate::create(punchanimation);
				sprite1->runAction(punchanimate);
				isPunching1 = true;
			}
			else
			{
				Vector<SpriteFrame*> punchLeft;
				punchLeft.reserve(7);
				punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(18, 1571, HeroWidth1, HeroHeight1)));
				punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(159, 1571, HeroWidth1, HeroHeight1)));
				punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(309, 1571, HeroWidth1, HeroHeight1)));
				punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(467, 1571, HeroWidth1, HeroHeight1)));
				punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(620, 1571, HeroWidth1, HeroHeight1)));
				punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(772, 1571, HeroWidth1, HeroHeight1)));
				punchLeft.pushBack(SpriteFrame::create("Adv.png", Rect(929, 1571, HeroWidth1, HeroHeight1)));
				Animation* punchLeftanimation = Animation::createWithSpriteFrames(punchLeft, 0.15f);
				Animate* punchLeftanimate = Animate::create(punchLeftanimation);
				sprite1->runAction(punchLeftanimate);
				isPunching1 = true;
			}
		}
		else
		{
			if (isRight1)
			{
				Vector<SpriteFrame*> punchi;
				punchi.reserve(13);
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(18, 501, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(158, 501, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(305, 501, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(455, 501, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(610, 501, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(766, 501, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(0, 653, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(150, 653, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(332, 653, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(486, 653, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(640, 653, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(794, 653, HeroWidth1, HeroHeight1)));
				punchi.pushBack(SpriteFrame::create("Adv.png", Rect(934, 653, HeroWidth1, HeroHeight1)));
				Animation* punchianimation = Animation::createWithSpriteFrames(punchi, 0.15f);
				Animate* punchianimate = Animate::create(punchianimation);
				sprite1->runAction(punchianimate);
			}
			else
			{
				Vector<SpriteFrame*> punchiLeft;
				punchiLeft.reserve(13);
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(0, 1727, HeroWidth1, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(152, 1727, HeroWidth1 - 10, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(316, 1727, HeroWidth1 - 10, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(470, 1727, HeroWidth1 - 10, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(623, 1727, HeroWidth1 - 10, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(774, 1727, HeroWidth1 - 10, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(18, 1882, HeroWidth1, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(169, 1882, HeroWidth1, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(297, 1882, HeroWidth1, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(450, 1882, HeroWidth1, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(604, 1882, HeroWidth1, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(750, 1882, HeroWidth1, HeroHeight1)));
				punchiLeft.pushBack(SpriteFrame::create("Adv.png", Rect(922, 1882, HeroWidth1, HeroHeight1)));
				Animation* punchiLeftanimation = Animation::createWithSpriteFrames(punchiLeft, 0.15f);
				Animate* punchiLeftanimate = Animate::create(punchiLeftanimation);
				sprite1->runAction(punchiLeftanimate);
			}
		}
	}
	if ((int)keyCode == 59)//key Space was pressed
	{
		Point posi = sprite1->getPosition();
		if (posi.y == 150)
		{
			if (isWalking1)
			{
				if (isRight1)
				{
					isJumping1 = true;
					Vector<SpriteFrame*> animRightJump;
					animRightJump.reserve(7);
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(3, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(152, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(304, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(594, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(613, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(765, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(1, 33, HeroWidth1, HeroHeight1)));
					Animation* Jumpanimation = Animation::createWithSpriteFrames(animRightJump, 0.15f);
					Animate* Jumpanimate = Animate::create(Jumpanimation);
					ActionInterval* jump = JumpBy::create(0.5, Point(60, 0), 60, 1);
					sprite1->runAction(jump);
					sprite1->runAction(Jumpanimate);
					//isJumping = false;
				}
				else
				{
					isJumping1 = true;
					Vector<SpriteFrame*> animLeftJump;
					animLeftJump.reserve(4);
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(18, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(173, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(325, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(474, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(632, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(786, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(18, 1264, HeroWidth1, HeroHeight1)));
					Animation* JumpLeftanimation = Animation::createWithSpriteFrames(animLeftJump, 0.15f);
					Animate* JumpLeftanimate = Animate::create(JumpLeftanimation);
					ActionInterval* jump1 = JumpBy::create(0.5, Point(-60, 0), 60, 1);
					sprite1->runAction(jump1);
					sprite1->runAction(JumpLeftanimate);
					//isJumping = false;
				}
			}
			else
			{
				if (isRight1)
				{
					isJumping1 = true;
					Vector<SpriteFrame*> animRightJump;
					animRightJump.reserve(7);
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(3, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(152, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(304, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(594, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(613, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(765, 801, HeroWidth1, HeroHeight1)));
					animRightJump.pushBack(SpriteFrame::create("Adv.png", Rect(1, 33, HeroWidth1, HeroHeight1)));
					Animation* Jumpanimation = Animation::createWithSpriteFrames(animRightJump, 0.15f);
					Animate* Jumpanimate = Animate::create(Jumpanimation);
					ActionInterval* jump = JumpBy::create(0.5, Point(0, 0), 60, 1);
					sprite1->runAction(jump);
					sprite1->runAction(Jumpanimate);
					//isJumping = false;
				}
				else
				{
					isJumping1 = true;
					Vector<SpriteFrame*> animLeftJump;
					animLeftJump.reserve(4);
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(18, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(173, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(325, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(474, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(632, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(786, 2031, HeroWidth1, HeroHeight1)));
					animLeftJump.pushBack(SpriteFrame::create("Adv.png", Rect(18, 1264, HeroWidth1, HeroHeight1)));
					Animation* JumpLeftanimation = Animation::createWithSpriteFrames(animLeftJump, 0.15f);
					Animate* JumpLeftanimate = Animate::create(JumpLeftanimation);
					ActionInterval* jump1 = JumpBy::create(0.5, Point(0, 0), 60, 1);
					sprite1->runAction(jump1);
					sprite1->runAction(JumpLeftanimate);
					//isJumping = false;
				}
			}
		}
		isJumping1 = false;
	}

}

void Scene2::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	sprite1->stopActionByTag(1);
	sprite1->stopActionByTag(2);
	sprite1->stopActionByTag(3);
	sprite1->stopActionByTag(4);
	/*if (isJumping)
	{
		goDown = true;
		isJumping = false;
	}*/
	if (isRight1) {
		sprite1->setTexture("Adv.png");
		sprite1->setTextureRect(Rect(1, 33, HeroWidth1, HeroHeight1));
	}
	else {
		sprite1->setTexture("Adv.png");
		sprite1->setTextureRect(Rect(18, 1264, HeroWidth1, HeroHeight1));
	}
	jumpForce1 = 10;
	//isJumping = false;
}


void Scene2::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
