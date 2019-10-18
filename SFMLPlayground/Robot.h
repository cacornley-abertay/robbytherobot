#pragma once
#include <iostream>
#include <SFML/graphics.hpp>
#include "Room.h"


class Robot
{
public:
	// Constants
	static const int NORTH = 0;
	static const int EAST = 1;
	static const int SOUTH = 2; 
	static const int WEST = 3;

	//Variables
	int steps = 0;
	bool up = false;
	int direction = NORTH;
	int x = 0;
	int y = 0;

	//Pointers to robot class
	Room* room;

	//Initalizes texture array
	sf::Texture imageJBell[4];

	//Initalizes robot object
	sf::RectangleShape robotObj;

	

	//Function
	Robot();
	~Robot();

	//Moves robby
	void move();
	//Checks the colour ahead of robby
	bool ahead_is_colour(Room* room, sf::String color);
	bool ahead_is_colour(Room* room, int color);
	//Checks if obstavle is ahead of robby
	bool obstacle_ahead(Room* room);
	//Rotates Robby to the right
	void right();
	//Rotates Robby to left
	void left();
	//Makes Robbby face up
	void face_up();
	//Makes Robby face down
	void face_down();
	//Gets x position
	int get_xpos();
	//Gets y position
	int get_ypos();
	//Sets x 
	void setX(int x);
	//sets y
	void setY(int y);
	//Gets current direction
	int get_dir();
	//Sets current direction
	void setDirection(int direction);
};

