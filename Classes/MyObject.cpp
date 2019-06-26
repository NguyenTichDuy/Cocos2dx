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
Sprite * MyObject::DuplicateSprite(Sprite *sprite)
{
	Sprite *pRet = Sprite::createWithTexture(sprite->getTexture());

	if (sprite->getChildrenCount() > 0)
	{
		for (int child = 0; child < sprite->getChildrenCount(); child++)
		{
			Sprite *spriteChild = (Sprite *)sprite->getChildren().at(child);
			Sprite *clone = DuplicateSprite((Sprite *)spriteChild);
			clone->boundingBox() = spriteChild->boundingBox();
			clone->setContentSize(spriteChild->getContentSize());
			clone->setPosition(spriteChild->getPosition());
			clone->setAnchorPoint(spriteChild->getAnchorPoint());
			clone->setName(spriteChild->getName());
			pRet->addChild(clone, spriteChild->getZOrder(), spriteChild->getTag());
		}
	}
	return pRet;
}