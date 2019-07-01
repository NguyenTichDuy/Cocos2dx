#include"Rock.h"
#include"GamePlayScene.h"
#include"ResourceManager.h"
#include<list>


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
		float xx = m_sprite->getPositionY() - deltaTime*200;
		m_sprite->setPositionY(xx);
	}
}

void Rock::Init()
{
	screenSize = Director::getInstance()->getVisibleSize();

	auto sprite = ResourceManager::getInstance()->GetSpriteById(ID_AESTROID_DARK);

	m_sprite = ResourceManager::getInstance()->DuplicateSprite(sprite);

	float width = rand() % (int)(screenSize.width);
	float height = rand() %(int)(screenSize.height) + screenSize.height;

	m_sprite->setPosition(Vec2(width, height));
	m_sprite->setVisible(false);
}
