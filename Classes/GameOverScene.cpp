#include"GameOverScene.h"

Scene * GameOverScene::createScene()
{
	auto scene = GameOverScene::create();
	return scene;
}

bool GameOverScene::init()
{
	// add background
	auto screenSize = Director::getInstance()->getVisibleSize();

	auto background = ResourceManager::getInstance()->GetSpriteById(ID_BACKGROUND);
	background->removeFromParent();

	background->setPosition(Vec2(screenSize.width / 2, screenSize.height / 2));
	background->setScale(screenSize.width / background->getContentSize().width,
		screenSize.height / background->getContentSize().height);
	this->addChild(background, -10);

	// add label GAME OVER

	auto labelGameOver = ResourceManager::getInstance()->GetLabelById(ID_LABELMF);
	labelGameOver->removeFromParent();

	if (labelGameOver == nullptr)
	{
		printf("error ID_LABELMF");
	}
	else
	{
		labelGameOver->setString("GAME OVER");
		labelGameOver->setBMFontSize(40);
		labelGameOver->setPosition(Vec2(screenSize.width /2 , screenSize.height * 2 /3));
		this->addChild(labelGameOver, 0);
	}
	
	// add label YOUR SCRORE

	auto labelYourScore = ResourceManager::getInstance()->GetLabelById(ID_LABEL_ARIAL);
	labelYourScore->removeFromParent();
	if (labelYourScore == nullptr)
	{
		printf("error ID_LABEL_ARIAL");
	}
	else
	{
		labelYourScore->setString("YOUR SCORE:" + to_string(ResourceManager::getInstance()->countPoint));
		labelYourScore->setBMFontSize(24);
		labelYourScore->setPosition(Vec2(screenSize.width / 2,
			screenSize.height * 2 / 3 - labelYourScore->getContentSize().height));
		this->addChild(labelYourScore, 0);
	}

	// add button replay

	auto buttonReplay = ResourceManager::getInstance()->GetButtonById(ID_BUTTON_REPLAY);
	buttonReplay->removeFromParent();

	if (buttonReplay == nullptr)
	{
		printf("error ID_LABEL_ARIAL");
	}
	else
	{
		buttonReplay->setPosition(Vec2(screenSize.width / 4, screenSize.height / 4));
		buttonReplay->setScale((screenSize.width / 5) / buttonReplay->getContentSize().width);
		buttonReplay->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type)
		{
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				break;

			case cocos2d::ui::Widget::TouchEventType::ENDED:
				Director::getInstance()->replaceScene(GamePlay::createScene());
				break;

			default:
				break;
			}
		});
		this->addChild(buttonReplay, 1);
	}
	// add button home
	auto buttonHome = ResourceManager::getInstance()->GetButtonById(ID_BUTTON_HOME);
	buttonHome->removeFromParent();

	if (buttonHome == nullptr)
	{
		printf("error ID_LABEL_ARIAL");
	}
	else
	{
		buttonHome->setPosition(Vec2(screenSize.width * 3 / 4, screenSize.height / 4));
		buttonHome->setScale(screenSize.width / 5 / buttonHome->getContentSize().width);
		buttonHome->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type)
		{
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				break;

			case cocos2d::ui::Widget::TouchEventType::ENDED:
				Director::getInstance()->replaceScene(MainMenuClass::createScene());
				break;

			default:
				break;
			}
		});
		this->addChild(buttonHome, 1);
	}
	return true;
}

