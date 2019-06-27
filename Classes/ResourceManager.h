#pragma once
#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include<map>
#include<string>
#include<fstream>
#include<iostream>


#define ID_LOADINGBAR 5
#define ID_BACKGROUND 0
#define ID_PROGRESS 6
#define ID_LABELMF 0
#define ID_LOGO 1
#define ID_BACKGROUND 0
#define ID_PLAY 0
#define ID_AESTROID_DARK 3
#define ID_SPACE_SHIP 4
#define ID_BULLET 2
#define ID_LABEL_ARIAL 1
#define ID_BUTTON_REPLAY 1
#define ID_BUTTON_HOME 2

#define SUM_BULLET 30
#define SIZE_FONTS 24

USING_NS_CC;

using namespace cocos2d::ui;
using namespace std;

class ResourceManager
{
public:

	static ResourceManager *getInstance();

	void Init(const string m_dataFolderPath);
	void Load(string fileName);

	Sprite* GetSpriteById(short id);
	Button* GetButtonById(short id);
	Label* GetLabelById(short id);

	static int countPoint;

	~ResourceManager();
private:
	ResourceManager();
	
	static ResourceManager *s_instance;


	string m_dataFolderPath;
	map<short, Sprite*> m_sprites;
	map<short, Button*> m_buttons;
	map<short, Label*> m_labels;
};

