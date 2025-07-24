Current Reading:
1 ) 01-01-Beginning C++ Game Programming-LearnC++FromScratchByBuildingFunGames 3rd Ed.pdf
2 ) MasteringC++GameDevelopment-CreateProfessionalAndRealistic3DGamesUsingC++17
3 ) C++ Memory Management(7 28/434)
4 ) Deciphering Object-Oriented Programming With C++
5 ) C++ Primer 5thEd - For fully understand Modern C++ standard
  
Purpose : Timber is related simple game which is the first eample game from Beginning C++ Game Programming-LearnC++FromScratchByBuildingFunGames 3rd Ed, 
		  I try to follow the game flow using a more useful framework that learning from Udemy course to studying C++.
		  I called this framework as mini-unreal-engine-gameplay-framework such core framework start from: 
			1. core data structure
			2. modern C++ memory utilities classes such as shared_ptr, unique_ptr & weak_ptr 
			3. implement Actor and World classes.
			4. AssetManager class for manage resources
Timberman:
Version Facts(Changed/Added/Modified/Deleted)
- v0.0.3 - Change Application object's ctor for which pass parameters for configure screen window
         - Using alias-declaration(using statement) declare C++ standard library utilities in Core.h, 
		 - config.h for runtime determine the asset root path & AssetManager in framework
		 - Change how Application object load texture from assets folder by AssetManager
         - Add build time generate context in config.h.in with game/CMakeList.txt		 

- v0.0.4 - Add Actor class for the game that represent nay moveable or non-moveable object in the game.
           Add World class that manage lifetime and activities of that actors.
		   	
Game Mechanics:
	- Time is always running out.
	- You can get more time by chopping the tree.
	- Chopping the tree causes the branches to fall.
	- The player must avoid the falling branches.
	- Repeat until time runs out or the player is squished by a branch.

Objects in game:
	- Score (Score Bar|Sprite)
	- Player(Player|Sprite)
	- Timer(Shrinking time bar|Sprite)
    - Lethal branches(Branches that make player damage|Sprite)
    - Chopped Log(target objects that player chop on|Sprite|player will gain points that will increase the timer value so that avoid running out of time)
    - Background
    - Objects for decoration(floating clouds, Bees)	
	
Assets:
	- Font(http://www.1001freefonts.com/komika_poster.font, download the Komika Poster font)
	- Sound effects(win|dead|chop|running out of time|start game)
	- Graphics/Textures(player|dead player|bees|background|branches|chopped log|score bar|time bar|floating clodd)

Screen and Internal Coordinates:
	screen coordinates:
		- consider monitor have 1920 x 1080 resolutions(1,920 pixels horizontally and 1,080 pixels vertically)
		- The pixels are numbered, starting from the top left of the screen.
		- x coordinates(from left to right is 0 - 1919), y coordinates(from top to bottom is 0 - 1079)
   (x=0, y=0)
			|---------------------|
		    |                     |
	        |                     |
			|                     |
			|                     |
			|                     |
			|                     |
			|---------------------|(x=1919, y=1079)
		
		- so that a specific and exact screen location can therefore be identified by an x and y coordinate.

Internal/Local coordinates
    when we create our game by drawing the game objects such as the background, characters, bullets, and text to
	specific locations on the screen.
	These locations are identified by the coordinates of the pixels. Take a look at the following hypothetical 
	example of how we might draw at the approximately central coordinates of the screen.
	In the case of a 1,920 x 1080 screen, this would be at the 1920/2=960, 1080/2=540 position
	
	In addition to the screen coordinates, our game objects will each have their own similar coordinate system as well. 
	Like the screen coordinate system, their internal or local coordinates start at 0,0 in the top-left corner.	 
    For the above example, we can see that (0, 0) of the game character image is drawn at (960, 540) of the screen.
	A visual 2D game object, such as a character is called Sprite. A sprite is typically made from an image file. 
	All sprites have what is known as an origin.
	If we draw a sprite to a specific location on the screen, it is the origin that will be located at this specific location.
	The 0,0 coordinates of the sprite are its origin.

Relation between sf::Texture & sf::Sprite
	In order to display graphics on screen it need two objects sf::Texture & sf::Sprite work together
	sf::Texture store image/graphics context in GPU as [data]
	SF::Sprite manipulate graphics object(data)        [operation]
	Why SFML design that way?
		- The reason is because of the way that graphics cards and OpenGL work
		- The second, the process of sf::Texture load graphics context to GPU memory is very slow.
		  Its slow enough that you can’t do it every frame of the game loop. So, it is useful to disassociate the texture 
		  object from any code that we will manipulate during the game loop.
    Therefore, Any objects that are made from the Texture class will sit happily on the GPU, just waiting for an associated
	Sprite object to tell it where to show itself. At the same time we can also reuse the same Texture object with multiple 
	different Sprite objects, which makes efficient use of GPU memory.

Actor concept in Unreal Engine:
 - From Copilot : In Unreal Engine, an Actor is the fundamental building block of gameplay. 
			      It's any object that can be placed or spawned in a level—think of it as the equivalent of a GameObject in Unity.
				  
				  An Actor is a class that that represents anything that can exist in the game world.
				  Examples include lights, cameras, characters, pickups, doors, and even invisible triggers.
				  Actors can be moved, rotated, scaled, and interacted with during gameplay.
				  Actor Lifecycle:
				  - Spawned: Created during gameplay using SpawnActor()
				  - Ticked: Updated every frame via the Tick() function.
	              - Destroyed: Removed from the world using Destroy().
                  
				  Actors also support replication, which is essential for multiplayer games—keeping objects in sync across clients.

AActor and UWorld classes in Unreal Engine:
 - From Copilot : World(The Game Environment)
					- Represents the entire game world or level.
					- Manages Actors, physics, rendering, and game flow.
					- Contains systems like navigation, AI, and timers.
					- You can access it using GetWorld() from most gameplay classes.

				  AActor(The Game Object)
					- Base class for anything placed or spawned in the world.
					- Includes characters, props, lights, cameras, triggers, etc.
					- Lives inside a UWorld instance.
					- Can be spawned dynamically using UWorld::SpawnActor().

				  How They Work Together
				  Relationship   | Description  
				  - Containment  | - UWorld holds and manages all AActor instances. 
				  - Spawning     | - You use UWorld::SpawnActor() to create new AActors at runtime. 
				  - Lifecycle 	 | - Actors are ticked, updated, and destroyed by the UWorld. 
				  - Access 		 | - Actors can call GetWorld() to interact with their environment. 

Refenencing:Unreal Engine Gameplay Framework
https://www.tomlooman.com/unreal-engine-gameplay-framework/

Language Tools for Programming:
	- Using namespace
	- a set of smart pointer for management resources objects
	- template for reducing common code section
	- Inheritance and polymorphism
	  Example: 
				class Enemy{
				public:
					void RunAIScripts();
					void Update(float deltaTime);
				private:
					int mHealth;
					int mDamage;
				};
				
				class Boss : public Enemy{
				public:
					void Update(float deltaTime);
					....
				}
				
		This type of structure is commonly referred to as a parent and child hierarchy(Inheritance) where the Boss class is a child of the Enemy class.
		This means that Boss will now have all the required structure from Enemy class. And it should point out that we only inherted the
		functions and variables that are declared public section. That is because using inheritance, the public methods and variable of the class
		are expored to everyone using the class. The protected section methods and variables are only available to the class itself and any classes derived. 
		The private methods and variables are only available to that class, no one else has access, even derived class.

polymorphism and virtual functions:
			
Design Patterns for programming game:
	- Template Method : Define behavior skeleton for Actor class and Its child classes for which we can differential each different type of sub class behavior.
	                    it involve how to design update game objects
    - Singleton       : Define centralized management resources. 	
    - State pattern   : Handle set of game state
	
	

	
