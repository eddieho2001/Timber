#pragma once
#include<SFML/Graphics.hpp>
#include "framework/Core.h"

//The class take the main function and divide them into three main parts
namespace timber{
	class Application {
	public:
		//In order to allow game application provide setting we need to change the constructor
		//Application();
		Application(unsigned int winWidth, unsigned int winHeight, const std::string& title, sf::Uint32 style);
		void run();//Handle the game loop
	private:
		//There are three necessary parts in game loop :  
		void processEvents(); //1. Handle events
		void update(sf::Time& deltaTime);        //2. Update game state 
		void render();        //3. draw the changed on screen  
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	private:
		sf::RenderWindow mWindow;
		//sf::CircleShape mPlayer;
		sf::Sprite mPlayer;
		shared<sf::Texture> mTexture;
		static const float PlayerSpeed;
		//static const sf::Time TimePerFrame;
		bool mIsMovingUp;
		bool mIsMovingDown;
		bool mIsMovingLeft;
		bool mIsMovingRight;
		//The number of cycle as per second we will looking for
		float mTargetFrameRate;
		sf::Clock mTickClock;
		sf::Texture mBackground;
		

	};
}