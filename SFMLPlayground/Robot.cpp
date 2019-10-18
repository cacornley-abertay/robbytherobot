#include "Robot.h"
#include <iostream>
using namespace std;

Robot::Robot()
{
	//Sets each element with image for Robby
	imageJBell[0].loadFromFile("media/jBell0.png");
	imageJBell[1].loadFromFile("media/jBell1.png");
	imageJBell[2].loadFromFile("media/jBell2.png");
	imageJBell[3].loadFromFile("media/jBell3.png");

	//Sets room pointer
	this->room = room;

	//Sets default direction as north
	direction = Robot::NORTH;

	//Counts steps
	steps = 0;
	up = true;

	//Sets default x,y position
	x = 0;
	y = 0;

	//Sets size of Robby
	robotObj.setSize(sf::Vector2f(80.f, 80.f));

	this->robotObj.setTexture(&imageJBell[0]);
}


Robot::~Robot()
{
}


void Robot::move()
{
	//Checks current direction and moves 
	switch (get_dir()) {
	case Robot::NORTH:	--y;
		break;
	case Robot::EAST:	++x;
		break;
	case Robot::SOUTH:	++y;
		break;
	case Robot::WEST:	--x;
		break;
	}
}

//Checks colour ahead of robby
bool Robot::ahead_is_colour(Room* room, sf::String color)
{
	std::string colorAhead = {};
	int xTest = 0;
	int yTest = 0;
	// colour coding assumed: white, 0; black, 1; blue, 2; yellow, 3; green, 4;
	std::string colors[]  { "white", "black", "blue", "yellow", "green" };

	if (direction == Robot::NORTH) {
		xTest = x;
		yTest = y - 1;
	}
	else if (direction == Robot::SOUTH) {
		xTest = x;
		yTest = y + 1;
	}
	else if (direction == Robot::EAST) {
		xTest = x + 1;
		yTest = y;
	}
	else {
		xTest = x - 1;
		yTest = y;
	}

	colorAhead = colors[room->cell_state(xTest, yTest)];
	return (color == colorAhead);
}
bool Robot::ahead_is_colour(Room* room, const int color)
{
	int xTest = 0;
	int yTest = 0;

	if (direction == Robot::NORTH) {
		xTest = x;
		yTest = y - 1;
	}
	else if (direction == Robot::SOUTH) {
		xTest = x;
		yTest = y + 1;
	}
	else if (direction == Robot::EAST) {
		xTest = x + 1;
		yTest = y;
	}
	else {
		xTest = x - 1;
		yTest = y;
	}

	if (room->cell_state(xTest, yTest) == color) {
		return true;
	}
	return false;
}

//Checks colour infront of Robby
bool Robot::obstacle_ahead(Room* room)
{
	int xTest = 0;
	int yTest = 0;

	if (direction == Robot::NORTH) {
		xTest = x;
		yTest = y - 1;
	}
	else if (direction == Robot::SOUTH) {
		xTest = x;
		yTest = y + 1;
	}
	else if (direction == Robot::EAST) {
		xTest = x + 1;
		yTest = y;
	}
	else {
		xTest = x - 1;
		yTest = y;
	}
	return (room->isObstacle(xTest, yTest));
}

//Rotates robby to the right 
void Robot::right()
{
	++direction;
	robotObj.setTexture(&imageJBell[1]);
	if (direction == 4) {
		direction = Robot::NORTH;
	}
	if (direction == Robot::NORTH) {
		up = true;
	}
	else if (direction == Robot::SOUTH) {
		up = false;
	}
}
//Rotates robbby to the left
void Robot::left()
{
	--direction;
	robotObj.setTexture(&imageJBell[3]);

	if (direction < 0) {
		direction = Robot::WEST;
	}
	if (direction == Robot::NORTH) {
		up = true;
	}
	else if (direction == Robot::SOUTH) {
		up = false;
	}
}
//Makes robby face up
void Robot::face_up()
{
	this->up = true;
}

//makes rooby face down
void Robot::face_down()
{
	this->up = false;
}

//Gets x value
int Robot::get_xpos()
{
	return x;
}
//gets Y value
int Robot::get_ypos()
{
	return y;
}
//sets x value
void Robot::setX(int x)
{
	this->x = x;
}
//sets y value
void Robot::setY(int y)
{
	this->y = y;
}
//Gets robbys current direction
int Robot::get_dir()
{
	return direction;
}

//Sets robbys current direction
void Robot::setDirection(int direction)
{
	if (direction >= 0 || direction <= 4) 
	{
		this->direction = direction;
	}
}