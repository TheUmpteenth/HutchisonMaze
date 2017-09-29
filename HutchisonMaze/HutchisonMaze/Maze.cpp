#include "Maze.h"
#include "tinyXML/tinyxml2.h"
#include "EntityManager.h"
#include "WallEntity.h"
#include "TransformComponent.h"
#include <iostream>


Maze::Maze() { LoddMazeFromFile("assets/maze.xml"); }
Maze::~Maze() {}

void Maze::LoddMazeFromFile(std::string in_filename) 
{
	//Load the file and get the root node
	tinyxml2::XMLDocument doc;
	doc.LoadFile(in_filename.c_str());

	tinyxml2::XMLElement* elem = doc.FirstChildElement("Maze");
	//set the height and width, within bounds
	elem->QueryIntAttribute("width", &m_width);
	elem->QueryIntAttribute("height", &m_height);

	if (m_width > MAX_WIDTH)
	{
		std::cout << "Maze width out of bounds: " << m_width << " MAX: " << MAX_WIDTH << std::endl;
	}
	if (m_height > MAX_HEIGHT)
	{
		std::cout << "Maze height out of bounds: " << m_height << " MAX: " << MAX_HEIGHT << std::endl;
	}

	//setup the data array
	int iMapSize = m_width*m_height;
	m_arriMazeData = new int[iMapSize];

	//read in the data and create the entites
	int i = 0;
	for (tinyxml2::XMLElement* e = elem->FirstChildElement("Tile"); e != NULL, i < iMapSize; e = e->NextSiblingElement("Tile"), ++i)
	{
		e->QueryIntAttribute("type", &m_arriMazeData[i]);
		CreateTileEntity(m_arriMazeData[i], i % m_height, i / m_height);
	}
}

void Maze::CreateTileEntity(int in_iType, int in_iGridX, int in_iGridY)
{
	WallEntity* wall;
	TransformComponent* wallTransform;
	switch (in_iType)
	{
	case 1:
		wall = EntityManager::GetInstance()->CreateEntity<WallEntity>();
		wallTransform = wall->GetComponent<TransformComponent>();
		wallTransform->m_vPosition.x = in_iGridX * TILE_WIDTH;
		wallTransform->m_vPosition.y = in_iGridY * TILE_HEIGHT;
		m_listEntities.push_back(wall);
		break;
	default:
		break;
	}
}

void Maze::ClearMaze() 
{
	if (m_arriMazeData != NULL)
	{
		delete[] m_arriMazeData;
		m_arriMazeData = NULL;
	}

	m_listEntities.clear();
}