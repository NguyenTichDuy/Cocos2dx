#pragma once
#include"MyObject.h"
#include"cocos2d.h"
#include"ResourceManager.h"

class Bullet :public MyObject
{
public:
	Bullet(Scene* scene);
	~Bullet();

	void Update(float deltaTime);

	void Init() override;

private:
	Size screenSize;
	Vec2 origin;
};

