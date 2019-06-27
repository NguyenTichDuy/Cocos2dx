#pragma once
#include"cocos2d.h"
#include"ResourceManager.h"

USING_NS_CC;


class LoadingScene :public cocos2d::Scene
{
public:
	static Scene * createScene();

	virtual bool init();

	void update(float deltaTime);

	CREATE_FUNC(LoadingScene);

	~LoadingScene();
private:
	Sprite *progessBar;
	Sprite *loadingBar;
	Sprite *background;
};

