#pragma once
#include "tinyXML\tinyxml2.h"
#include <vector>
#include "Entity.h"

class Maze
{
private:
	const int TILE_WIDTH = 16;
	const int TILE_HEIGHT = 16;
	const int MAX_WIDTH = 128;
	const int MAX_HEIGHT = 128;
	const int MAX_TILES = MAX_WIDTH * MAX_HEIGHT;

	int m_width;
	int m_height;

	int* m_arriMazeData;

	std::vector<Entity*> m_listEntities;

public:
	Maze();
	~Maze();

	void LoddMazeFromFile(std::string in_filename);
	void CreateTileEntity(int in_iType, int in_iGridX, int in_iGridY);
	void ClearMaze();
};