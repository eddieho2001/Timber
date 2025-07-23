Timberman:
Version Facts(Changed/Added/Modified/Deleted)
- v0.0.3 - Change Application object's ctor for which pass parameters for configure screen window
         - Add using declaration in Core.h, config.h for runtime determine the asset root path & AssetManager in framework
		 - Change how Application object load texture from assets folder by AssetManager
         - Add build time generate context in config.h.in with game/CMakeList.txt		 

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
	
