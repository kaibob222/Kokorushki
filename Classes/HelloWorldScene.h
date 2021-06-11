#pragma once

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

	cocos2d::Sprite *sprite1;
	cocos2d::Sprite *sprite2;

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

//	cocos2d::Sprite *sprite1;

	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	void update(float dt);
	void Play(Ref *pSender);
	void Highscores(Ref *pSender);
	void Settings(Ref *pSender);
	void ImageButton(Ref *pSender);
	void Exit(Ref *pSender);

	bool onContactBegin(cocos2d::PhysicsContact &contact);

	void Heart(Ref *pSender);
	void Pause(Ref *pSender);
	
private:
	cocos2d::PhysicsWorld *sceneWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld *world) {
		sceneWorld = world;
	};
	void loadMap(cocos2d::TMXTiledMap *mp) {
		///
		this->addChild(mp, 1, 99); // with a tag of '99'
		static auto earth = mp->getObjectGroup("earth");
		auto& obj = earth->getObjects();
		for (auto & i : obj) {
			auto dict = i.asValueMap();
			auto x = dict["x"].asFloat();
			auto y = dict["y"].asFloat();
			auto width = dict["width"].asFloat();
			auto height = dict["height"].asFloat();


			auto earthBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(width, height), cocos2d::PhysicsMaterial(0, 0, 0));
			auto  earthNode = Node::create();
			earthNode->setPosition(cocos2d::Point(x+500, y + 60));
			earthNode->setPhysicsBody(earthBody);
			earthBody->setDynamic(false);
			this->addChild(earthNode);
			//earthNode->addComponent(earthBody);
		}
	}
};

#endif // __HELLOWORLD_SCENE_H__
