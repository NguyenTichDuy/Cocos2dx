#pragma once
#include"cocos2d.h"
#include"ResourceManager.h"
#include"GamePlayScene.h"
#include"MainMenuScene.h"

USING_NS_CC;

class GameOverScene :public cocos2d::Scene
{
public:

	static Scene *createScene();

	virtual bool init() override;

	CREATE_FUNC(GameOverScene);


private:

};

