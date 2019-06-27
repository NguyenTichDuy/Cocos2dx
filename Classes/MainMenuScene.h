#pragma once
#include"cocos2d.h"
#include"ResourceManager.h"


class MainMenuClass :public cocos2d::Scene
{
public:
	MainMenuClass();
	~MainMenuClass();

	static Scene* createScene();

	virtual bool init();

	void playCallback(Ref *sender);


	CREATE_FUNC(MainMenuClass);

private:
	Size screenSize;
	Sprite* background;
	Sprite* logoSprite;
	Button *button;
};


