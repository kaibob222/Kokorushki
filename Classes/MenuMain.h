#ifndef __MENUMAIN_SCENE_H__
#define __MENUMAIN_SCENE_H__

#include "cocos2d.h"

class MenuMain : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuMain);

	cocos2d::Sprite *sprite1;

	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);


	///////рср ъ охьссссссс
	void Play(Ref *pSender);
	void Highscores(Ref *pSender);
	void Settings(Ref *pSender);
	void ImageButton(Ref *pSender);


};

#endif // __HELLOWORLD_SCENE_H__
