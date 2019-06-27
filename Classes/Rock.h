#pragma once
#include"cocos2d.h"
#include"MyObject.h"

#define NUM_ROCK 20
USING_NS_CC;

class Rock :public MyObject
{
public:
	Rock(Scene* scene);
	~Rock();

	void Update(float deltaTime) override;

	void Init() override;

private:
	Size screenSize;
	Vec2 origin;
};

