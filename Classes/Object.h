#pragma once
#include"cocos2d.h"

USING_NS_CC;

class Objectt
{
public:
	virtual void Update() = 0;
	virtual void Init() = 0;
	Objectt();
	~Objectt();
protected:
	Sprite *m_sprite;
};
Objectt::Objectt()
{

}
Objectt::~Objectt()
{
}

