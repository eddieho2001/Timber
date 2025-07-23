#include <iostream>
#include "framework/AssetManager.h"
#include "game_framework/GameApplication.h"
#include "config.h"


timber::Application* GetApplication(){
	return new timber::GameApplication();
}

/*
* Here we define the game window size(represent the resolution of the player’s screen), name and its window style in Ctor
*/
timber::GameApplication::GameApplication():
	Application{1920, 1080, "Timber!!!", sf::Style::Fullscreen }
{
	AssetManager::GetInstance().SetAssetRootDir(GetResourceDir());
	std::cout << "GetResourceDir : " << GetResourceDir();
}
