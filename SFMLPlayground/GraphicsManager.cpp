#include "GraphicsManager.h"
#include <chrono>
#include <thread>

GraphicsManager::GraphicsManager(Room *room, Robot *robot)
{
	this->room = room;
	this->robot = robot;
	int squaredim = CELLSIZE * room->size;

		//sets robbys x,y position to bottom left corner
		robot->x = 1;
		robot->y = 18;
		//Sets window size as well sets up event systems for resizing and closing
		frame.create(sf::VideoMode(800, 800), "Robby The Robot", sf::Style::None);
		float width = (float)sf::VideoMode::getDesktopMode().width * 0.5f;
		float height = (float)frame.getSize().x * 0.5f;
		frame.setPosition(sf::Vector2i((int)width-(int)height, 0));
}

GraphicsManager::~GraphicsManager()
{

}

void GraphicsManager::draw()
{
	//Sets Robbys current positon
	robot->robotObj.setPosition((float)(CELLSIZE * (robot->x - 0.5)), (float)(CELLSIZE * (robot->y) - 20));

	robot->robotObj.setTexture(&(robot->imageJBell[1]));
	robot->robotObj.setTexture(&robot->imageJBell[robot->direction]);

	paintComponent();
	//std::chrono::seconds dura(1);
	std::chrono::milliseconds dura(render_delay);
	std::this_thread::sleep_for(dura);
}

//Draws Robot and room as well as handles keyboard input
void GraphicsManager::paintComponent(Room* room, Robot* robot)
{
	//Sets window size as well sets up event systems for resizing and closing
	frame.create(sf::VideoMode(500, 500), "Robby The Robot", sf::Style::Resize | sf::Style::Close);

	//2D array to set the position of each tile of the map
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//std::cout << "We set the element " << i << "," << j << " \n";		This is for testing purposes
			room->map[i][j].setPosition((float)(i * CELLSIZE), (float)(j * CELLSIZE));
		}
	}



	//Sets timer
	timeDown = 125;

	//robot->robotObj.setTexture(&(robot->imageJBell[0]));
	//Runs 2D array to print out of the 
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//std::cout << "room is drawn \n";	This is for testing purposes
			frame.draw(room->map[i][j]);
		}
	}

	//Draws robot at current position
	frame.draw(robot->robotObj);
	//Calls window to display
	frame.display();
	//Clears display
	frame.clear();

	robot->robotObj.setPosition((float)(CELLSIZE * (robot->x - 0.5)), (float)(CELLSIZE * (robot->y) - 10));

	robot->robotObj.setTexture(&robot->imageJBell[robot->direction]);

	//Sets Event System
	sf::Event evnt;
	while (frame.pollEvent(evnt))
	{
		//checks if window gets closed
		switch (evnt.type)
		{
		case sf::Event::Closed:
			frame.close();
			break;
		}
	}

	//robot->robotObj.setTexture(&(robot->imageJBell[0]));
	//Runs 2D array to print out of the 
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//std::cout << "room is drawn \n";	This is for testing purposes
			frame.draw(room->map[i][j]);
		}
	}

	//Draws robot at current position
	frame.draw(robot->robotObj);
	//Calls window to display
	frame.display();
	//Clears display
	frame.clear();

	//Checks if the colour ahead is greeb
	if (robot->ahead_is_colour(room, "green") == true)
	{
		//std::cout << "You Win \n";	This is for testing purposes
		//Sets current map to next map
		currentMap++;;
		//Closes window
		frame.close();
	}

	//Reduces time count by 1
	timeDown--;



}

void GraphicsManager::paintComponent()
{

	//2D array to set the position of each tile of the map
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//std::cout << "We set the element " << i << "," << j << " \n";		This is for testing purposes
			room->map[i][j].setPosition((float)(i * CELLSIZE), (float)(j * CELLSIZE));
			frame.draw(room->map[i][j]);
		}
	}

	//Draws robot at current position
	frame.draw(robot->robotObj);

	//Calls window to display
	frame.display();

}


void GraphicsManager::setDrawDelay(unsigned newDelay)
{
	render_delay = newDelay;
}
