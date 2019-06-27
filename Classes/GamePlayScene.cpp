#include"GamePlayScene.h"
#include"ResourceManager.h"
#include<Windows.h>
#include"Bullet.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

Scene * GamePlay::createScene()
{
	return GamePlay::create();
}

bool GamePlay::init()
{
	screenSize = Director::getInstance()->getVisibleSize();
	// add background
	auto background = ResourceManager::getInstance()->GetSpriteById(ID_BACKGROUND);
	background->removeFromParent();
	if (background == nullptr)
	{
		printf("error ID_BACKGROUND");
	}
	else
	{
		background->setPosition(Vec2(screenSize.width / 2, screenSize.height / 2));
		background->setScale(screenSize.width / background->getContentSize().width,
			screenSize.height / background->getContentSize().height);
		this->addChild(background, -10);
	}
	// add Space Shooter

	m_spaceShooter = new SpaceShooter(this);

	// add rock 
	Rock *rock;
	for (int i = 0; i < SUM_ROCK; i++)
	{
		rock = new Rock(this);
		m_rocks.push_back(rock);
	}


	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(GamePlay::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GamePlay::onTouchMoved, this);

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, m_spaceShooter->getSprite());

	// count point 
	static int countPoint = 0;

	//
	this->scheduleUpdate();

	return true;
}

void GamePlay::update(float deltaTime)
{

	this->GenerateRock();
	
	for (auto r : m_rocks)
	{
		r->Update(deltaTime);
	}
	m_spaceShooter->Update(deltaTime);

	m_spaceShooter->Collision(m_rocks);


}

void GamePlay::GenerateRock()
{
	for (int i = 0; i < SUM_ROCK; i++)
	{
		if (!m_rocks.at(i)->getSprite()->isVisible())
		{
			m_rocks.at(i)->getSprite()->setVisible(true);
			int x = rand() % (int)(screenSize.width + 1);
			int y = rand() % (int)(screenSize.height) + screenSize.height;
			m_rocks.at(i)->getSprite()->setPosition(x, y);
		}
	}
}
bool GamePlay::onTouchBegan(Touch * touch, Event * unused_event)
{
	return true;
}
void GamePlay::onTouchMoved(Touch * touch, Event * unused_event)
{
	Vec2 touchLocation = touch->getLocation();

	m_spaceShooter->getSprite()->setPosition(touchLocation);
}

