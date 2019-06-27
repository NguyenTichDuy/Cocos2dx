#include "SpaceShooter.h"
#include"ResourceManager.h"
#include "Bullet.h"

SpaceShooter::SpaceShooter(Scene *scene)
{
	this->Init();

	// add bullet

	MyObject *object;
	for (int i = 0; i < SUM_BULLET; i++)
	{
		object = new Bullet(scene);
		this->m_bullets.push_back(object);
	}

	scene->addChild(m_sprite, 0);
}

SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{
	screenSize = Director::getInstance()->getVisibleSize();

	// set space shooter
	m_sprite = ResourceManager::getInstance()->GetSpriteById(ID_SPACE_SHIP);
	m_sprite->removeFromParent();

	m_sprite->setPosition(Vec2(screenSize.width / 2, screenSize.height / 2));
	m_sprite->setScale(0.5);

}

void SpaceShooter::Update(float deltaTime)
{
	Shoot();

	for (auto i : m_bullets)
	{
		i->Update(deltaTime);
	}
}

void SpaceShooter::Shoot()
{
	for (auto bullet : m_bullets)
	{
		if (!bullet->getSprite()->isVisible())
		{
			bullet->getSprite()->setPosition(m_sprite->getPosition());
			bullet->getSprite()->setVisible(true);
			break;
		}
	}
}

void SpaceShooter::Collision(std::vector<Rock*> _m_rocks)
{
	for (auto rock : _m_rocks)
	{
		//if (rock->getSprite()->getBoundingBox()->intersectsRect(m_sprite->getBoundingBox()))
		{

		}
	}
}
