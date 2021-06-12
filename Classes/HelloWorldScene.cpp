#include "HelloWorldScene.h"
#include "AudioEngine.h"
#include "MenuMain.h"
#include "ui/CocosGUI.h"
#include "Scene2.h"
#include "GameOver.h"
#include "Anime.h"
#include "Hero.h"
#include "Enemy.h"

USING_NS_CC;

extern int q;
extern int xp;
int musS1;

//physics look a down 
Scene* HelloWorld::createScene()
{
	auto scene1 = HelloWorld::createWithPhysics();
	//scene1->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	scene1->getPhysicsWorld()->setGravity(Vec2(0, -500));

	auto layer = HelloWorld::create();
	layer->SetPhysicsWorld(scene1->getPhysicsWorld());
	scene1->addChild(layer);
	scene1->removeChild(scene1->getDefaultCamera());
	return scene1;
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
	
	

	//auto map = TMXTiledMap::create("qwer3.tmx");
	//auto objectsGroups = map->getObjectGroups("");
	//auto layer = map->getLayer("layer1");
	//this->addChild(map);
	//this->addChild(layer);

	//music
	musS1 = AudioEngine::play2d("bg2.mp3", true, 1.0);

	///phy
	/*auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + 103));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);*/
	/*auto earth = PhysicsBody::createBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT);
	auto earthNode = Node::create();
	earthNode->setPhysicsBody(earth);*/

	///
	auto map = TMXTiledMap::create("map/primer.tmx");
	HelloWorld::loadMap(map);

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
		//this->addChild(background, 0);
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
		this->addChild(label);
	}

	if (q == 0) {
		sprite1 = Sprite::create("Adv.png", Rect(1, 33, 137, 131));
		sprite1->setPosition(Point(50, 170));
		q = 0;
	}
	if (q == 1) {
		sprite1 = Sprite::create("Adv.png", Rect(18, 1264, 137, 131));
		sprite1->setPosition(Point(880, 150));
		q = 0;
	}

	sprite2 = Sprite::create("enemy/Skelet2.png", Rect(20, 0, 170, 251));
	sprite2->setPosition(Point(700, 170)); //205 defolt

	// physics
	//auto spriteBody = PhysicsBody::createBox(sprite1->getContentSize() / 1.5, PhysicsMaterial(0, 1, 0));
	//sprite1->setPhysicsBody(spriteBody);
	//auto spriteBody = PhysicsBody::createBox(sprite1->getContentSize() / 1.5, PhysicsMaterial(1, 1, 0));

	//enemy physicsbody
	Enemy::enemyPhysics(sprite2);
	//hero physocsbody
	Hero::heroPhysics(sprite1);
	auto spritePos = sprite1->getPosition();
	sprite1->setCameraMask(getCameraMask());
	

	this->addChild(sprite2);


	this->addChild(sprite1);



	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);// if you are using cocos2d-x 3.0alpha.1 and later!// if you are using cocos2d-x 3.0alpha.1 and later!

	//auto menu_Item_1 = MenuItemFont::create("Exit", CC_CALLBACK_1(HelloWorld::Exit, this));
	//auto menu_Item_0 = MenuItemFont::create("Pause", CC_CALLBACK_1(HelloWorld::Pause, this));
	auto menu_Item_2 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
	auto menu_Item_3 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
	auto menu_Item_4 = MenuItemImage::create("redheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));

	//auto *menu = Menu::create(menu_Item_1, NULL);
	//auto *menu0 = Menu::create(menu_Item_0, NULL);
	auto *menu2 = Menu::create(menu_Item_2, NULL);
	auto *menu3 = Menu::create(menu_Item_3, NULL);
	auto *menu4 = Menu::create(menu_Item_4, NULL);
	//menu->alignItemsVertically();
	//menu->setPosition(Point(visibleSize.width - 20, visibleSize.height - 20));
	//menu->setPosition(Point(850, 570));
	//menu->setAnchorPoint(Vec2(1, 1));
	//menu0->setPosition(Point(750, 570));
	menu2->setPosition(Point(20, 570));
	menu3->setPosition(Point(60, 570));
	menu4->setPosition(Point(100, 570));
	//menu->getCameraMask();
	//this->addChild(menu);
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
	//this->setScale(1);
	//contact
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	/*cocos2d::TMXTiledMap *map = TMXTiledMap::create("map/primer.tmx");
	map->getLayerNum();
	
	HelloWorld::loadMap(map);*/
	return true;
}

bool isPaused = false;
int q111 = 0;
int enemyXp = 3;
int rrr = 1;
bool isSkeletonHurted = false;

void HelloWorld::Heart(cocos2d::Ref *pSpender)
{
	CCLOG("Image Button");
}

bool HelloWorld::onContactBegin(PhysicsContact& contact)
{
	auto *nodeA = contact.getShapeA()->getBody();
	auto *nodeB = contact.getShapeB()->getBody();

	if ((1 == nodeA->getCollisionBitmask() && 2 == nodeB->getCollisionBitmask()) || (2 == nodeA->getCollisionBitmask() && 1 == nodeB->getCollisionBitmask()))
	{
		CCLOG("COLLISION HAS OCCURED ");
		xp--;
		//sprite1->_physicsBody->applyImpulse(Vec2(-100, 0));
		if (xp == 2) {
			auto menu_Item_4 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
			auto *menu4 = Menu::create(menu_Item_4, NULL);
			menu4->setPosition(Point(100, 570));
			//menu4->setAnchorPoint(Vec2(0, 1));
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
			Hero::heroDeath(sprite1);
			isPaused = true;
			auto menu_Item_2 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
			auto *menu2 = Menu::create(menu_Item_2, NULL);
			menu2->setPosition(Point(20, 570));
			this->addChild(menu2);
			xp = 3;
		}
	}
	if ((1 == nodeA->getCollisionBitmask() && 3 == nodeB->getCollisionBitmask()) || (3 == nodeA->getCollisionBitmask() && 1 == nodeB->getCollisionBitmask()))
	{
		HelloWorld::t = true;

	}
	return true;
}

void HelloWorld::update(float dt) {

	if (sprite1->getPositionY() < 0)
		isPaused = true;
	auto camera = this->getDefaultCamera();

	//auto visible1 = Director::getInstance()->getWinSize();
	auto visible1 = camera->getContentSize();

	auto menu_Item_1 = MenuItemFont::create("Exit", CC_CALLBACK_1(HelloWorld::Exit, this));
	auto *menu = Menu::create(menu_Item_1, NULL);
	menu->setPosition(Point(visible1.width - 20, visible1.height - 20));
	this->addChild(menu);

	if (isSkeletonHurted)
	{
		rrr++;
		if (rrr == 10)
		{
			/*auto tintFrom = TintBy::create(255.0f, 255.0f, 255.0f, 0.9f);//white
			sprite2->runAction(tintFrom);*/
			sprite2->setColor(cocos2d::Color3B(255, 255, 255));
			rrr = 0;
			isSkeletonHurted = false;
		}
	}

	Point pos = sprite1->getPosition();
	if (sprite1->getPositionX() < 450) {
		camera->setPosition(450, 328);
		menu->setPosition(Point(850, 570));
	}
	
	
	if (sprite1->getPositionX() >= 450) {
		if (sprite1->getPositionX() < 2755)
		{
			camera->setPosition(pos.x, pos.y + 160);
			/*menu->setVisible(false);
			menu->setPosition(Point(pos.x+400, pos.y+400));*/
		}
		else
		{
			camera->setPositionY(pos.y + 160);
		}
		
	}
	/*if (pos > Point(880, 150)) {
		auto scene = Scene2::createScene();
		AudioEngine::stop(musS1);
		Director::getInstance()->replaceScene(scene);
	}*/

	if (isPaused)
	{
		q111++;
		if (q111 == 100)
		{
			auto scene = GameOver::createScene();
			Director::getInstance()->replaceScene(scene);
			q111 = 0;
			isPaused = false;
		}
	}

}

void HelloWorld::Exit(cocos2d::Ref *pSpender)
{
	CCLOG("Exit");
	auto scene = MenuMain::createScene();
	AudioEngine::pauseAll();
	Director::getInstance()->replaceScene(scene);
}

/*void HelloWorld::Pause(cocos2d::Ref *pSpender)
{
	CCLOG("Pause");
	//auto pausedSet = this->getScheduler()->pauseAllTargets();
	Director::getInstance()->pause();
}*/


bool death = true;
void HelloWorld::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	CCLOG("Key with keycode %d pressed", keyCode);
	Point pos = sprite1->getPosition();
	if ((int)keyCode == 164)//j pressed
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
			Hero::heroDeath(sprite1);
			isPaused = true;
			auto menu_Item_2 = MenuItemImage::create("blackheart.png", "", CC_CALLBACK_1(HelloWorld::Heart, this));
			auto *menu2 = Menu::create(menu_Item_2, NULL);
			menu2->setPosition(Point(20, 570));
			this->addChild(menu2);
			xp = 3;
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
		if (a) {
			a = false;
			for (int i = 1; i <= 8; i++)
			{
				sprite1->stopActionByTag(i);
			}
		
		Hero::heroPunch(sprite1);

		Hero b;
		
		
		if (abs(sprite2->getPositionX() - sprite1->getPositionX()) < 120 && death) {
			if (enemyXp == 0)
			{
				//this->removeChild(sprite2);
				sprite2->setVisible(false);
				sprite2->removeComponent(sprite2->getPhysicsBody());
				death = false;
			}
			else
			{
				enemyXp--;
				sprite2->setColor(cocos2d::Color3B(255, 0, 0));
				isSkeletonHurted = true;
				/*if (enemyXp> 0) {
					auto tintTo = TintTo::create(11.0f, 156.0f, 49.0f, 0.0f);
					sprite2->runAction(tintTo);
				}*/
			}
		}
		a = true;
	}
}

	if ((int)keyCode == 59)//key Space was pressed
	{
		if (t) {
			int jump;
			jump = AudioEngine::play2d("jump1.mp3", false);
			Hero::heroJump(sprite1);
			t = false;
		}
	}
	if ((int)keyCode == 164)//key Enter was pressed
	{
		Hero::heroHurt(sprite1);
	}
	/*if ((int)keyCode == 139)//key P was pressed
	{
		Hero::heroDeath(sprite1);
	}*/
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