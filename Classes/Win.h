#pragma once
#ifndef __WIN_H__
#define __WIN_H__

#include "cocos2d.h"

class Win : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Win);

	cocos2d::Sprite *sprite1;

	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);


	///////рср ъ охьссссссс
	void Menu(Ref *pSender);


};

#endif // __GAMEOVER_SCENE_H__
