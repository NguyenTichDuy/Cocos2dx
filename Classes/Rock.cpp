#include"Rock.h"
#include"GamePlayScene.h"
#include"ResourceManager.h"
#include<list>
#include<Windows.h>


Rock::Rock(Scene *scene)
{
	this->Init();
	scene->addChild(m_sprite, 0);
}

Rock::~Rock()
{

}

void Rock::Update(float deltaTime)
{
	if (m_sprite->getPositionY() <= 0)
	{
		m_sprite->setVisible(false);
	}
	else if (this->m_sprite->isVisible())
	{
		float xx = m_sprite->getPositionY() - deltaTime;
		m_sprite->setPositionY(xx);
	}
}

void Rock::Init()
{
	screenSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = ResourceManager::getInstance()->GetSpriteById(ID_AESTROID_DARK);

	m_sprite = DuplicateSprite(sprite);

	Sleep(100);
	float width = rand() % (int)(screenSize.width - origin.x + 1) + origin.x;
	float height = rand() %(int)(screenSize.height) + screenSize.height;

	m_sprite->setPosition(Vec2(width, height));
	m_sprite->setVisible(false);
}
