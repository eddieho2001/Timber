Timberman: v0.0.1
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
	