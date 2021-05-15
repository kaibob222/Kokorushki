#include "JsonAdapter.h"
#include <iostream>
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include <fstream>
#include "external/json/document.h"
#include "external/json/istreamwrapper.h"
#include "external/json/writer.h"
#include "external/json/stringbuffer.h"

USING_NS_CC;
using namespace rapidjson;
using namespace std;

void JsonAdapter::JsonInit()
{
	ifstream ifs("TheWay.json");
	IStreamWrapper isw(ifs);
	//string str = "{\"scene\" : \"HelloWorldScene\"}";
	//ifstream file("TheWay.json");
	Document d;
	d.ParseStream(isw);
	//d.Parse<0>(str.c_str());
	if (d.HasParseError()) {
		CCLOG("GetParseError %s\n", d.GetParseError());
	}
	else if (d.IsObject() && d.HasMember("scene")) {
		CCLOG("%s\n", d["scene"].GetString());
	}
}
