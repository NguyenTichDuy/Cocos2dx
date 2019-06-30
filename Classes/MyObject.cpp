#include"MyObject.h"

MyObject::MyObject()
{
}

MyObject::~MyObject()
{
}

Sprite * MyObject::getSprite()
{
	return this->m_sprite;
}

void  MyObject::setSprite(Sprite *sprite)
{
	if (sprite == nullptr)
	{
		printf("error sprite");
	}
	else
	{
		this->m_sprite = sprite;
	}
}

