#include"GamePlayScene.h"
#include"Bullet.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

Scene * GamePlay::createScene()
{
	auto scene = Scene::createWithPhysics();

	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	auto layer = GamePlay::create();
	scene->addChild(layer);
	return scene;
}

bool GamePlay::init()
{
	screenSize = Director::getInstance()->getVisibleSize();
	ResourceManager::getInstance()->countPoint = 0;
	// add background sound
	audioBackground = SimpleAudioEngine::getInstance();

	audioBackground->preloadBackgroundMusic("musicBackground.mp3");
	audioBackground->playBackgroundMusic("musicBackground.mp3", true);
	audioBackground->setBackgroundMusicVolume(0.1);
	// add physicsbackground
	auto backgroundWall = Sprite::create();
	backgroundWall->setPosition(screenSize.width / 2, screenSize.height / 2);
	
	auto physicBackground = PhysicsBody::createEdgeBox(screenSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

	physicBackground->setCategoryBitmask(0x01);
	physicBackground->setCollisionBitmask(0x02);
	physicBackground->getShape(0)->setDensity(1.0f);
	physicBackground->getShape(0)->setFriction(0.0f);
	physicBackground->getShape(0)->setRestitution(1.0f);
	//physicBackground->setContactTestBitmask(0x000001);

	backgroundWall->setPhysicsBody(physicBackground);
	this->addChild(backgroundWall);
	physicBackground->setTag(0);
	// add background
	auto background = ResourceManager::getInstance()->GetSpriteById(ID_BACKGROUND);

	m_background[0] = ResourceManager::getInstance()->DuplicateSprite(background);
	m_background[1] = ResourceManager::getInstance()->DuplicateSprite(background);
	m_background[2] = ResourceManager::getInstance()->DuplicateSprite(background);
	// add physic for background

	//--------------background-------------
	m_background[0]->setAnchorPoint(Vec2(0, 0));
	m_background[0]->setPosition(Vec2(0, screenSize.height));
	m_background[0]->setScale(screenSize.width / m_background[0]->getContentSize().width,
	screenSize.height / m_background[0]->getContentSize().height);
	this->addChild(m_background[0], -10);
	//-------------background1-------------
	m_background[1]->setAnchorPoint(Vec2(0, 0));
	m_background[1]->setPosition(Vec2(0, 0));
	m_background[1]->setScale(screenSize.width / m_background[1]->getContentSize().width,
		screenSize.height / m_background[1]->getContentSize().height);
	this->addChild(m_background[1], -10);
	//-------------background2-------------
	m_background[2]->setAnchorPoint(Vec2(0, 0));
	m_background[2]->setPosition(Vec2(0, -screenSize.height));
	m_background[2]->setScale(screenSize.width / m_background[2]->getContentSize().width,
		screenSize.height / m_background[2]->getContentSize().height);
	this->addChild(m_background[2], -10);
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

	//run background
	m_background[0]->setPositionY(m_background[0]->getPositionY() - deltaTime * 300);
	m_background[1]->setPositionY(m_background[1]->getPositionY() - deltaTime * 300);
	m_background[2]->setPositionY(m_background[2]->getPositionY() - deltaTime * 300);

	if (m_background[0]->getPositionY() <= -screenSize.height * 2)
	{
		m_background[0]->setPositionY(m_background[1]->getPositionY() 
			+ screenSize.height);
	}
	if (m_background[1]->getPositionY() <= -screenSize.height * 2)
	{
		m_background[1]->setPositionY(m_background[2]->getPositionY()
			+ screenSize.height);
	}
	if (m_background[2]->getPositionY() <= -screenSize.height * 2)
	{
		m_background[2]->setPositionY(m_background[0]->getPositionY()
			+ screenSize.height);
	}
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

