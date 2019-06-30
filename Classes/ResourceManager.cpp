#include"ResourceManager.h"

ResourceManager *ResourceManager::s_instance = nullptr;

int ResourceManager::countPoint = 0;

ResourceManager::ResourceManager()
{
}
ResourceManager::~ResourceManager()
{

}

ResourceManager* ResourceManager::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new ResourceManager();
	}

	return s_instance;
}

void ResourceManager::Init(const std::string _m_dataFolderPath)
{
	m_dataFolderPath = _m_dataFolderPath;

	string fileName = m_dataFolderPath + "Data.bin";

	this->Load(fileName);

}

void ResourceManager::Load(string fileName)
{

	std::ifstream fileInput;
	fileInput.open(fileName);
	string stringIgnore;
	int length;
	short id;
	string filePath;
	string filePathPress;
	if (fileInput.fail())
	{
		printf("Fail to open this file!");
	}
	else
	{
		// read sprite
		fileInput >> stringIgnore;
		fileInput >> length;

		for (int i = 0; i < length; i++)
		{
			fileInput >> stringIgnore;
			fileInput >> id;
			fileInput >> stringIgnore;
			fileInput >> filePath;

			filePath.replace(0, 3, m_dataFolderPath);
			auto sprite = Sprite::create(filePath);

			CC_SAFE_RETAIN(sprite);

			m_sprites.insert(pair<short, Sprite*>(id, sprite));
		}
		//read button
		fileInput >> stringIgnore;
		fileInput >> length;
		for (int i = 0; i < length; i++)
		{
			fileInput >> stringIgnore;
			fileInput >> id;
			fileInput >> stringIgnore;
			fileInput >> filePath;
			fileInput >> stringIgnore;
			fileInput >> filePathPress;
			

			filePath.replace(0, 3, m_dataFolderPath);
			filePathPress.replace(0, 3, m_dataFolderPath);
			auto button = ui::Button::create(filePath, filePathPress);
			CC_SAFE_RETAIN(button);
			m_buttons.insert(pair<short, Button*>(id, button));
		}
		// read font

		fileInput >> stringIgnore;
		fileInput >> length;
		for (int i = 0; i < length; i++)
		{
			fileInput >> stringIgnore;
			fileInput >> id;
			fileInput >> stringIgnore;
			fileInput >> filePath;

			filePath.replace(0, 3, m_dataFolderPath);

			TTFConfig label;

			label.fontFilePath = filePath;
			label.fontSize = SIZE_FONTS;

			auto myLabel = Label::createWithTTF(label, "LabelTTF from TTFConfig");
			CC_SAFE_RETAIN(myLabel);

			m_labels.insert(pair<short, Label*>(id, myLabel));
		}
		fileInput.close();
	}
}

Sprite* ResourceManager::GetSpriteById(short id)
{
	map<short, Sprite*>::iterator iter = m_sprites.find(id);
	iter->second->retain();
	return iter->second;
}

Button* ResourceManager::GetButtonById(short id)
{
	map<short, Button*>::iterator iter = m_buttons.find(id);

	return iter->second;
}

Label* ResourceManager::GetLabelById(short id)
{
	map<short, Label*>::iterator iter = m_labels.find(id);
	return iter->second;
}
Sprite * ResourceManager::DuplicateSprite(Sprite *sprite)
{
	Sprite *pRet = Sprite::createWithTexture(sprite->getTexture());

	if (sprite->getChildrenCount() > 0)
	{
		for (int child = 0; child < sprite->getChildrenCount(); child++)
		{
			Sprite *spriteChild = (Sprite *)sprite->getChildren().at(child);
			Sprite *clone = DuplicateSprite((Sprite *)spriteChild);
			clone->boundingBox() = spriteChild->boundingBox();
			clone->setContentSize(spriteChild->getContentSize());
			clone->setPosition(spriteChild->getPosition());
			clone->setAnchorPoint(spriteChild->getAnchorPoint());
			clone->setName(spriteChild->getName());
			pRet->addChild(clone, spriteChild->getZOrder(), spriteChild->getTag());
		}
	}
	return pRet;
}


