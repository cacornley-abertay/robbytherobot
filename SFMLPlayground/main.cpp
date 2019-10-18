// Standard Libraries
#include <iostream>

// Our Header 
#include "GraphicsManager.h"	

//Ponter reference to classes
Room* room;
Robot* robby;
GraphicsManager *picture;

int main()
{
	room = new Room(5);								// Create a room for the robot to navigate
	robby = new Robot();							// Create Robby
	picture = new GraphicsManager(room, robby);		// Create a GraphicsManager to draw everything

	// Speed of the render delay in milliseconds
	picture->setDrawDelay(1000);

	/*
		START OF OUR CODE
	*/

	while (!robby->ahead_is_colour(room, "green"))
	{
		if (robby->ahead_is_colour(room, "yellow"))
		{
			robby->move();
			picture->draw();
		}
		else
		{
			robby->right();
			picture->draw();
		}
	}

	/*
		END OF OUR CODE
	*/

	std::cout << "End of Instructions"; //End of Instructions for Robby
	system ("Pause");
}