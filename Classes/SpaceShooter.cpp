#include "SpaceShooter.h"
#include"ResourceManager.h"
#include "Bullet.h"
#include"GameOverScene.h"
#include"GamePlayScene.h"

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

	Sprite *sprite = ResourceManager::getInstance()->GetSpriteById(ID_SPACE_SHIP);

	m_sprite = DuplicateSprite(sprite);
	m_sprite->removeFromParent();

	m_sprite->setPosition(Vec2(screenSize.width / 2, screenSize.height / 3));
	m_sprite->setScale(0.5);
}

void SpaceShooter::Update(float deltaTime)
{
	static float count = 0;
	count += 0.1;
	if (count >= 1)
	{
		Shoot();
		count = 0;
	}

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
		if (this->m_sprite->getBoundingBox().intersectsRect(rock->getSprite()->getBoundingBox()))
		{
			auto boomAudio = SimpleAudioEngine::getInstance();
			boomAudio->playEffect("boom.wav", false, 1, 1, 1);
			boomAudio->setEffectsVolume(1.0f);
			Director::getInstance()->replaceScene(GameOverScene::createScene());
		}
		for (auto  i : m_bullets)
		{
			if (i->getSprite()->getBoundingBox().intersectsRect(rock->getSprite()->getBoundingBox()))
			{
				i->getSprite()->setVisible(false);
				rock->getSprite()->setVisible(false);
				ResourceManager::getInstance()->countPoint++;
			}
		}
	}
}
