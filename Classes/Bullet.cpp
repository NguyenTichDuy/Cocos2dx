#include "Bullet.h"


Bullet::Bullet(Scene * scene)
{
	this->Init();
	scene->addChild(m_sprite, 0);
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime)
{
	if (m_sprite->getPositionY() >= screenSize.height)
	{
		m_sprite->setVisible(false);
	}
	else if (m_sprite->isVisible())
	{
		int y = m_sprite->getPositionY() + deltaTime * 500;
		m_sprite->setPositionY(y);
	}
}

void Bullet::Init()
{
	screenSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	Sprite *sprite = ResourceManager::getInstance()->GetSpriteById(ID_BULLET);
	
	m_sprite = DuplicateSprite(sprite);

	m_sprite->setVisible(false);
}
