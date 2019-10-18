#include "Room.h"

Room::Room(int x)
{
	//Sets size
	size = 20;

	//Assigns images to texture array
	imageFloorCell[0].loadFromFile("media/0.gif");
	imageFloorCell[1].loadFromFile("media/1.gif");
	imageFloorCell[2].loadFromFile("media/2.gif");
	imageFloorCell[3].loadFromFile("media/3.gif");
	imageFloorCell[4].loadFromFile("media/4.gif");



	//Sets size of the squares to 25 by 25
	white.setSize(sf::Vector2f(40.f, 40.f));
	black.setSize(sf::Vector2f(40.f, 40.f));
	blue.setSize(sf::Vector2f(40.f, 40.f));
	yellow.setSize(sf::Vector2f(40.f, 40.f));
	green.setSize(sf::Vector2f(40.f, 40.f));

	//Assigns Textures
	white.setTexture(&(imageFloorCell[0]));
	black.setTexture(&(imageFloorCell[1]));
	blue.setTexture(&(imageFloorCell[2]));
	yellow.setTexture(&(imageFloorCell[3]));
	green.setTexture(&(imageFloorCell[4]));

	init(x);
	generateMap(map, grid);

}

Room::Room()
{
	//Sets size
	size = 20;

	//Assigns images to texture array
	imageFloorCell[0].loadFromFile("media/0.gif");
	imageFloorCell[1].loadFromFile("media/1.gif");
	imageFloorCell[2].loadFromFile("media/2.gif");
	imageFloorCell[3].loadFromFile("media/3.gif");
	imageFloorCell[4].loadFromFile("media/4.gif");



	//Sets size of the squares to 25 by 25
	white.setSize(sf::Vector2f(20.f, 20.f));
	black.setSize(sf::Vector2f(20.f, 20.f));
	blue.setSize(sf::Vector2f(20.f, 20.f));
	yellow.setSize(sf::Vector2f(20.f, 20.f));
	green.setSize(sf::Vector2f(20.f, 20.f));

	//Assigns Textures
	white.setTexture(&(imageFloorCell[0]));
	black.setTexture(&(imageFloorCell[1]));
	blue.setTexture(&(imageFloorCell[2]));
	yellow.setTexture(&(imageFloorCell[3]));
	green.setTexture(&(imageFloorCell[4]));

	init(1);//function call to load room 1
	generateMap(map, grid);

}


Room::~Room()
{
}

//sets x,y blank
void Room::setBlank(int x, int y)
{
	grid[x][y] = WHITE;
}

//sets x,y to wall
void Room::setWall(int x, int y)
{
	grid[x][y] = BLACK;
}

//sets x,y to obstacle
void Room::setObstacle(int x, int y)
{
	grid[x][y] = BLUE;
}

//sets x,y to path
void Room::setPath(int x, int y)
{
	grid[x][y] = YELLOW;
}

//sets x,y to target
void Room::setTarget(int x,int y)
{
	grid[x][y] = GREEN;
}

//sets square (Not Used)
void Room::setSquare(int x, int y, sf::String color)
{
	if (color == "white") { grid[x][y] = WHITE; }
	else if (color == "black") { grid[x][y] = BLACK; }
	else if (color == "blue") { grid[x][y] = BLUE; }
	else if (color == "yellow") { grid[x][y] = YELLOW; }
	else if (color == "green") { grid[x][y] = GREEN; }
}

//sets square (Not Used)
void Room::setSquare(int x, int y, int color)
{
	switch (color) {
	case 0:		grid[x][y] = WHITE;
		break;
	case 1:		grid[x][y] = BLACK;
		break;
	case 2:		grid[x][y] = BLUE;
		break;
	case 3:		grid[x][y] = YELLOW;
		break;
	case 4:		grid[x][y] = GREEN;
		break;
	default:	break;
	}
}

//gets room size
 int Room::room_size()
{
	return size;
}

 //gets grid
 int Room::getGrid(int grid)
 {
	 return grid;
 }

 //sets grid
 void Room::setGrid(int grid[20][20])
{

	//assign individual elements

	 for (int i = 0; i < 20; i++) {
		 for (int j = 0; j < 20; j++) {
			 this->grid[i][j] = grid[i][j];
		 }
	 }
	


	size = sizeof(grid) / sizeof(int);
}

 //checks cell state
int Room::cell_state(int x, int y)
{
	if (x < 0 || x > room_size() || y < 0 || y > room_size()) {
		return -1;
	}
	return grid[x][y];
}

//checks if obstacle 
bool Room::isObstacle(int x, int y)
{
	if (grid[x][y] == BLUE || grid[x][y] == BLACK) {
		return true;
	}
	return false;
}

//runs init
void Room::init(int identifier)
{
	//runs 2D array
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) {
			//Sets outside squares to black
			if (i == 0 || (i == size - 1) || j == 0 || (j == size - 1))
			{
				grid[i][j] = BLACK;
				//std::cout << "grid element " << i << "," << j << " is set black \n";
			}
			//sets inside squres to white
			else
			{
				//std::cout << "grid element " << i << "," << j << " is set white \n";
				grid[i][j] = WHITE;
;
			}
		}
	}

	switch (identifier) 
	{
	case 0:
		std::cout << "Case 0 \n";
		//Runs 2D array
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				//std::cout << "We have assigned from file \n";	Testing purposes
				//sets file data to the grid
				mapFileZero >> grid[j][i];
			}
		}
		break;
	case 1:
		std::cout << "Case 1 \n";
		//Runs 2D array
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				//std::cout << "We have assigned from file \n";	Testing purposes
				//sets file data to the grid
				mapFileOne >> grid[j][i];
			}
		}
		break;

	case 2:
		std::cout << "Case 2 \n";
		//Runs 2D array
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				//std::cout << "We have assigned from file \n";	Testing purposes
				//sets file data to the grid
				mapFileTwo >> grid[j][i];
			}
		}
		break;

	case 3:
		std::cout << "Case 3 \n";
		//Runs 2D array
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				//std::cout << "We have assigned from file \n";	Testing purposes
				//sets file data to the grid
				mapFileThree >> grid[j][i];
			}
		}
		break;

	case 4:
		std::cout << "Case 4 \n";
		//Runs 2D array
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				//std::cout << "We have assigned from file \n";	Testing purposes
				//sets file data to the grid
				mapFileFour >> grid[j][i];
			}
		}
		break;
	case 5:
		std::cout << "Case 5 \n";
		//Runs 2D array
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				//std::cout << "We have assigned from file \n";	Testing purposes
				//sets file data to the grid
				mapFileFive >> grid[j][i];
			}
		}
		break;
	case 6:
		std::cout << "Case 6 \n";
		//Runs 2D array
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				//std::cout << "We have assigned from file \n";	Testing purposes
				//sets file data to the grid
				mapFileSix >> grid[j][i];
			}
		}
		break;
	case 7:
		std::cout << "Case 7 \n";
		//Runs 2D array
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				//std::cout << "We have assigned from file \n";	Testing purposes
				//sets file data to the grid
				mapFileSeven >> grid[j][i];
			}
		}
		break;
	case 8:
		std::cout << "Case 8 \n";
		//Runs 2D array
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				//std::cout << "We have assigned from file \n";	Testing purposes
				//sets file data to the grid
				mapFileEight >> grid[j][i];
			}
		}
		break;
	case 9:
		std::cout << "Case 9 \n";
		//Runs 2D array
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {
				//std::cout << "We have assigned from file \n";	Testing purposes
				//sets file data to the grid
				mapFileNine >> grid[j][i];
			}
		}
		break;
	}
}

//This sifts through each elemenet within the preset 20x20 array and checks the value so that i can assign 
//textured objects to a mirror rectangle shape array
sf::RectangleShape * Room::generateMap(sf::RectangleShape map[20][20], int grid[20][20])
{
	//std::cout << "Generate map \n";

	//Runs 2D array
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{

			//If grid element is equal to zero we add a white object to our sfml shape array
			if (grid[i][j] == 0) 
			{
				//std::cout << "Map element " << i << "," << j << " is set white \n";
				map[i][j] = white;
			}

			//If grid element is equal to one we add a black object to our sfml shape array
			else if (grid[i][j] == 1)
			{
				//std::cout << "Map element " << i << "," << j << " is set black \n";
				map[i][j] = black;
			}

			//If grid element is equal to two we add a blue object to our sfml shape array
			else if (grid[i][j] == 2)
			{
				//std::cout << "Map element " << i << "," << j << " is set blue \n";
				map[i][j] = blue;
			}

			//If grid element is equal to three we add a yellow object to our sfml shape array
			else if (grid[i][j] == 3)
			{
				//std::cout << "Map element " << i << "," << j << " is set yellow \n";
				map[i][j] = yellow;
			}

			//If grid element is equal to four we add a green object to our sfml shape array
			else if (grid[i][j] == 4)
			{
				//std::cout << "Map element " << i << "," << j << " is set green \n";
				map[i][j] = green;
			}
		}
	}

	return *map;
}
