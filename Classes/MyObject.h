#pragma once
#include"cocos2d.h"

USING_NS_CC;

class MyObject
{
public:
	virtual void Update(float deltaTime) = 0;
	virtual void Init() = 0;
	MyObject();
	virtual ~MyObject();

	Sprite *getSprite();
	void setSprite(Sprite *sprite);

	Sprite * DuplicateSprite(Sprite *sprite);

protected:
	Sprite *m_sprite;
};


