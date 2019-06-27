#include "LoadingScene.h"
#include"MainMenuScene.h"

Scene * LoadingScene::createScene()
{
	auto scene = LoadingScene::create();
	return scene;
}

bool LoadingScene::init()
{
	// add screenSize 

	auto screenSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();


	//add background
	
	background = ResourceManager::getInstance()->GetSpriteById(ID_BACKGROUND);
	background->removeFromParent();

	if (background == nullptr)
	{
		printf("error ID_BACKGROUND");
	}
	else
	{
		background->setPosition(Vec2(screenSize.width/ 2, screenSize.height / 2));
		background->setScale(screenSize.width / background->getContentSize().width,
			screenSize.height / background->getContentSize().height);
		this->addChild(background, -10);
	}

	// add loadingBar
	
	loadingBar = ResourceManager::getInstance()->GetSpriteById(ID_LOADINGBAR);
	loadingBar->removeFromParent();
	if (loadingBar == nullptr)
	{
		printf("error ID_LOADINGBAR");
	}
	else
	{
		loadingBar->setPosition(Vec2(screenSize.width / 2, screenSize.height / 3));
		this->addChild(loadingBar, 0);
	}

	// add progess bar

	progessBar = ResourceManager::getInstance()->GetSpriteById(ID_PROGRESS);
	progessBar->removeFromParent();

	if (progessBar == nullptr)
	{
		printf("error ID_PROGRESS");
	}
	else
	{
		progessBar->setAnchorPoint(Vec2(0, 0.5));
		progessBar->setPosition(Vec2(screenSize.width / 2 - progessBar->getContentSize().width /2, screenSize.height / 3));
		progessBar->setScaleX(0);
		this->addChild(progessBar);
	}
	// add label loading..
	auto labelLoading = ResourceManager::getInstance()->GetLabelById(ID_LABELMF);

	if (labelLoading == nullptr)
	{
		printf("error ID_LABELMF");
	}
	else
	{
		labelLoading->setString("Loading...");
		labelLoading->setPosition(Vec2(screenSize.width / 2, 
			screenSize.height / 3 + loadingBar->getContentSize().height));
		this->addChild(labelLoading, 0 );
	}

	// add update

	this->update(3);
	this->scheduleUpdate();



	return true;
}

void LoadingScene::update(float deltaTime)
{
	float percent =  progessBar->getScaleX();
	percent = percent + 0.01;
	progessBar->setScaleX(percent);
	if (percent >= 1.0f)
	{
		this->unscheduleUpdate();

		auto gotoNext = CallFunc::create([]()
		{
			Director::getInstance()->replaceScene(TransitionFade::create(0.5, MainMenuClass::createScene(), Color3B(123, 123, 123)));
		});

		auto sequence = Sequence::create(DelayTime::create(1), gotoNext, nullptr);
		this->runAction(sequence);
	}
}

LoadingScene::~LoadingScene()
{

}
