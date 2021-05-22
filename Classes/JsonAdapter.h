#pragma once

#ifndef __JSONADAPTER_H__
#define __JSONADAPTER_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"

class JsonAdapter : public cocos2d::Scene
{
public: 
	/*static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(JsonAdapter);*/
	static void JsonInit(int sceneId);
	static void loadScenee(int IdOfScene);
};

#endif
