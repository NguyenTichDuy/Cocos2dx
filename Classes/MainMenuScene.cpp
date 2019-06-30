#include"MainMenuScene.h"
#include"GamePlayScene.h"

MainMenuClass::MainMenuClass()
{
}

MainMenuClass::~MainMenuClass()
{
	//CC_SAFE_RELEASE_NULL(background);
}

cocos2d::Scene * MainMenuClass::createScene()
{
	auto Scene = Scene::create();

	auto layer = MainMenuClass::create();

	Scene->addChild(layer);

	return Scene;
}

bool MainMenuClass::init()
{
	screenSize = Director::getInstance()->getVisibleSize();
	// add background audio

	audioBackground = SimpleAudioEngine::getInstance();

	audioBackground->playBackgroundMusic("Unity.mp3", true);
	audioBackground->setBackgroundMusicVolume(0.05f);
	// add background
	background = ResourceManager::getInstance()->GetSpriteById(ID_BACKGROUND);
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

	// add sprite logo
	logoSprite = ResourceManager::getInstance()->GetSpriteById(ID_LOGO);
	logoSprite->removeFromParent();
	if (logoSprite == nullptr)
	{
		printf("error ID_LOGO");
	}
	else
	{
		logoSprite->setPosition(Vec2(screenSize.width / 2, screenSize.height * 2 / 3));
		logoSprite->setScale(screenSize.width / logoSprite->getContentSize().width,
			screenSize.height / 4 / logoSprite->getContentSize().height);
		this->addChild(logoSprite, 0);
	}

	// add Button

	button = ResourceManager::getInstance()->GetButtonById(ID_PLAY);
	button->removeFromParent();
	if (button == nullptr)
	{
		printf("error ID_PLAY");
	}
	else
	{
		button->setPosition(Vec2(screenSize.width / 2, screenSize.height / 3));
		button->setScale(0.5);
		button->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type)
		{
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				this->playCallback(sender);
				break;
			default:
				break;
			}
		});
		this->addChild(button, 0);
	}
	return true;
}

void MainMenuClass::playCallback(Ref *sender)
{
	auto gotoNext = CallFunc::create([]()
	{
		Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5, GamePlay::createScene()));

	});
	this->audioBackground->stopBackgroundMusic();
	auto sequence = Sequence::create(gotoNext, nullptr);
	this->runAction(sequence);
}
