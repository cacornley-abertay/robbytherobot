#pragma once
#include <iostream>
#include <SFML/graphics.hpp>
#include <SFML/System/string.hpp>
#include <fstream>
class GraphicsManager;
class Room;

class Room
{
public:

	// Constants
	static const int WHITE = 0;
	static const int BLACK = 1;
	static const int BLUE = 2;
	static const int YELLOW = 3;
	static const int GREEN = 4;

	//Variables
	//CellSize
	int size;	

	//Calls data from file
	std::ifstream mapFileZero{ "maps/map0.txt" };
	std::ifstream mapFileOne	{ "maps/map1.txt" };
	std::ifstream mapFileTwo	{ "maps/map2.txt" };
	std::ifstream mapFileThree	{ "maps/map3.txt" };
	std::ifstream mapFileFour	{ "maps/map4.txt" };
	std::ifstream mapFileFive{ "maps/map5.txt" };
	std::ifstream mapFileSix{ "maps/map6.txt" };
	std::ifstream mapFileSeven{ "maps/map7.txt" };
	std::ifstream mapFileEight{ "maps/map8.txt" };
	std::ifstream mapFileNine{ "maps/map9.txt" };
	
	//Offset of the squares 
	const float offset = 20;
	//initializes the 2d array for each block
	int grid[20][20]; 

	//SFML
	//Texture Array
	sf::Texture imageFloorCell[5];
	//Shape area for map
	sf::RectangleShape map[20][20];
	//Whie square
	sf::RectangleShape white;
	//Black square
	sf::RectangleShape black;
	//Blue square
	sf::RectangleShape blue;
	//Yellow square
	sf::RectangleShape yellow;
	//Green square
	sf::RectangleShape green;

	//Reference to other classes
	Room* room;


	//Function
	Room();
	Room(int);
	~Room();

	//Sets room blank(Not Used)
	void setBlank(int x, int y);
	//Sets room walls(Not Used)
	void setWall(int x, int y);
	//Sets room obstacles(Not Used)
	void setObstacle(int x, int y);
	//Sets path (Not used)
	void setPath(int x, int y);
	//Sets target/ goal(Not Used)
	void setTarget(int x, int y);
	//Sets square(Not Used)
	void setSquare(int x, int y, sf::String color);
	//sets square(Not Used)
	void setSquare(int x, int y, int color);

	//Gets room size
	int room_size();
	
	//Gets grid
	int getGrid(int grid); 

	//sets grid
	void setGrid(int grid[20][20]);
	//checks cell state
	int cell_state(int x, int y);
	//checks if obstacle
	bool isObstacle(int x, int y);
	//sets room to map file data
	void init(int identifier);
	//converts room to sfml version to be drawable
	sf::RectangleShape* generateMap(sf::RectangleShape map[20][20], int grid[20][20]);

};