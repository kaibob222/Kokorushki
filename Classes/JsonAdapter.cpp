#include "JsonAdapter.h"
#include <iostream>
#include "HelloWorldScene.h"
#include "Scene2.h"
#include "ui/CocosGUI.h"
#include <fstream>
#include "external/json/document.h"
#include "external/json/istreamwrapper.h"
#include "external/json/writer.h"
#include "external/json/stringbuffer.h"

USING_NS_CC;
using namespace rapidjson;
using namespace std;

/*Scene* JsonAdapter::createScene()
{
	return JsonAdapter::create();
}

bool JsonAdapter::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Director::getInstance()->getOpenGLView()->setFrameSize(900, 600);
	Director::getInstance()->getOpenGLView()->setDesignResolutionSize(900, 600, ResolutionPolicy::EXACT_FIT);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("load.jpg");
	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(background, 0);
	//}
	JsonInit();
	return true;
}*/


void JsonAdapter::JsonInit(int sceneId)
{
	ifstream ifs("TheWay.json");
	IStreamWrapper isw(ifs);
	//string str = "{\"scene\" : \"HelloWorldScene\"}";
	//ifstream file("TheWay.json");
	Document d;
	d.ParseStream(isw);
	//int p=d.MemberCount();
	//d.Parse<0>(str.c_str());
	if (d.HasParseError()) {
		CCLOG("GetParseError %s\n", d.GetParseError());
	}
	else if (d.IsObject() && d.HasMember("levels")) {
		for (const auto& level : d["levels"].GetArray()) {
			if (level["id"].GetInt() == sceneId)
			{
				CCLOG("%s", level["scene"].GetString());
				loadScenee(sceneId);
			}
			//CCLOG("{level=%d, scene=%s}", level["id"].GetInt(), level["scene"].GetString());
		}
		//const rapidjson::Value& a = d["levels"];
		/*if (d["id"].GetInt() == 1)
		{
			CCLOG("%s\n", d["scene"].GetString());
		}
		else
		{
			CCLOG("id!=1");
		}*/
	}
	else
	{
		CCLOG("There's no id");
	}

	//CCLOG("%d", p);
}

void JsonAdapter::loadScenee(int IdOfScene)
{
	if (IdOfScene == 1)
	{
		CCLOG("1");
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	}
	else if (IdOfScene == 2)
	{
		CCLOG("2");
		auto scene2 = Scene2::createScene();
		Director::getInstance()->replaceScene(scene2);
	}
	else
	{
		CCLOG("Scene error");
	}
}
