#pragma once
#include <iostream>
#include <SFML/graphics.hpp>
#include "Robot.h"

class GraphicsManager
{
	int render_delay = 1000;
public:
	//Constants
	const int CELLSIZE = 40;	//Size of each tile as well as used to offset each tile

	//Varaibles
	 int timeDown = 0; //int value used to count downs stop limate the speed robby can move
	 int currentMap = 1; //First map that gets changed once robby reaches a green tile

	 //Pointers to robot and room classes
	 Room* room;		
	 Robot* robot;	 

	//SFML Window
	sf::RenderWindow frame;

	//functions 
	GraphicsManager(Room* room, Robot* robot);
	~GraphicsManager();

	//This function draws all items and handles keyboard inputs
	void paintComponent(Room* room, Robot* robot);
	void paintComponent();
	void draw();
	void setDrawDelay(unsigned newDelay);
};