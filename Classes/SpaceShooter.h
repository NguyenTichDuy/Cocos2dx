#pragma once

#include"cocos2d.h"
#include"MyObject.h"
#include<list>
#include"Rock.h"
#include"LoadingScene.h"

class SpaceShooter :public MyObject
{
private:
	std::list<MyObject *> m_bullets;
	Size screenSize;

public:
	SpaceShooter(Scene* scene);
	~SpaceShooter();

	void Init();
	void Update(float deltaTime) override;
	void Shoot();
	void Collision(std::vector<Rock*> _m_rocks);

};

