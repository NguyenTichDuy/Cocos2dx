#pragma once
#include"cocos2d.h"
#include"Rock.h"
#include<vector>
#include"SpaceShooter.h"
#include"ResourceManager.h"


#define SUM_ROCK 10
USING_NS_CC;

class GamePlay :public cocos2d::Scene
{
private:

	Size screenSize;
	SpaceShooter *m_spaceShooter;
	std::vector <Rock*> m_rocks;
	Sprite *m_background[3];

public:
	GamePlay();
	~GamePlay();

	static Scene *createScene();

	virtual bool init() override;

	SimpleAudioEngine *audioBackground;

	void update(float deltaTime) override;
	void GenerateRock();

	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);

	CREATE_FUNC(GamePlay);


};

