#pragma once
#include<string>
std::string GetResourceDir() {
#ifdef NDEBUG //for release build
	return "assets/";
#else
	return "D:/MyDocs/GameDev/C++Projs/SFML-GameProjects/BeginningC++GameProgramming3rdEd/MyWork/Timber/game/assets/";
#endif
}
