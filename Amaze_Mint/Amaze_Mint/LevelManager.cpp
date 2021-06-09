//#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>
#include "LevelManager.h"

using namespace sf;
using namespace std;

int** LevelManager::nextLevel(VertexArray& rVaLevel, int level)
{
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;

	// Get the next level
	m_CurrentLevel = level;

	// Load the appropriate level from a text file
	string levelToLoad;
	switch (m_CurrentLevel)
	{
	
	case 1:
		levelToLoad = "levels/level1.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 100;
		m_BaseTimeLimit = 30.0f;
		break;

	case 2:
		levelToLoad = "levels/level2.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 100;
		m_BaseTimeLimit = 100.0f;
		break;

	case 3:
		levelToLoad = "levels/level3.txt";
		m_StartPosition.x = 1250;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;

	case 4:
		levelToLoad = "levels/level4.txt";
		m_StartPosition.x = 50;
		m_StartPosition.y = 200;
		m_BaseTimeLimit = 50.0f;
		break;


	}


	ifstream inputFile(levelToLoad);
	string s;

	// Count the number of rows in the file
	while (getline(inputFile, s))
	{
		++m_LevelSize.y;
	}

	// Store the length of the rows

	m_LevelSize.x = s.length();

	// Go back to the start of the file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	// Prepare the 2d array to hold the int values from the file
	int** arrayLevel = new int*[m_LevelSize.y];
	for (int i = 0; i < m_LevelSize.y; ++i)
	{
		// Add a new array into each array element
		arrayLevel[i] = new int[m_LevelSize.x];
	}

	// Loop through the file and store all the values in the 2d array
	string row;
	int y = 0;
	while (inputFile >> row)
	{
		for (int x = 0; x < row.length(); x++) {

			const char val = row[x];

			arrayLevel[y][x] = atoi(&val);

			if (val == 'J')
			{
				arrayLevel[y][x] = 9;
			}
			if (val == 'K')
			{
				arrayLevel[y][x] = 10;
			}
			if (val == 'L')
			{
				arrayLevel[y][x] = 11;
			}
			if (val == 'M')
			{
				arrayLevel[y][x] = 12;
			}
			if (val == 'A')
			{
				arrayLevel[y][x] = 13;

			}
			if (val == 'F')
			{
				arrayLevel[y][x] = 14;
			}
			if (val == 'T')
			{
				arrayLevel[y][x] = 15;
			}
			if (val == 'E')
			{
				arrayLevel[y][x] = 16;
			}
			if (val == 'G')
			{
				arrayLevel[y][x] = 17;
			}
			if (val == '!')
			{
				arrayLevel[y][x] = 18;
			}
			if (val == '"')
			{
				arrayLevel[y][x] = 19;
			}
			if (val == '%')
			{
				arrayLevel[y][x] = 20;
			}
			if (val == '$')
			{
				arrayLevel[y][x] = 21;
			}
			if (val == 'B')
			{
				arrayLevel[y][x] = 22;
			}
			if (val == 'C')
			{
				arrayLevel[y][x] = 23;
			}
			if (val == 'P')
			{
				arrayLevel[y][x] = 24;
			}
			if (val == 'X')
			{
				arrayLevel[y][x] = 25;
			}
			if (val == 'U')
			{
				arrayLevel[y][x] = 26;
			}
			if (val == 'O')
			{
				arrayLevel[y][x] = 27;
			}
			if (val == '*')
			{
				arrayLevel[y][x] = 28;
			}
			if (val == '-')
			{
				arrayLevel[y][x] = 29;
			}
			if (val == '+')
			{
				arrayLevel[y][x] = 30;
			}
			if (val == '^')
			{
				arrayLevel[y][x] = 31;
			}
			if (val == 'Y')
			{
				arrayLevel[y][x] = 32;
			}
			if (val == 'l')
			{
				arrayLevel[y][x] = 33;
			}
			if (val == 'R')
			{
				arrayLevel[y][x] = 34;
			}
		}

		y++;
	}


	/*arrayLevel[4][19] = arrayLevel[1][1];
	arrayLevel[4][20] = arrayLevel[1][1];

	arrayLevel[4][22] = arrayLevel[1][1];
	arrayLevel[4][23] = arrayLevel[1][1];*/

	// close the file
	inputFile.close();

	// What type of primitive are we using?
	rVaLevel.setPrimitiveType(Quads);

	// Set the size of the vertex array
	rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);

	// Start at the beginning of the vertex array
	int currentVertex = 0;

	for (int x = 0; x < m_LevelSize.x; x++)
	{
		for (int y = 0; y < m_LevelSize.y; y++)
		{
			// Position each vertex in the current quad
			rVaLevel[currentVertex + 0].position = 
				Vector2f(x * TILE_SIZE, y * TILE_SIZE);

			rVaLevel[currentVertex + 1].position = 
				Vector2f((x * TILE_SIZE) + TILE_SIZE, y * TILE_SIZE);

			rVaLevel[currentVertex + 2].position = 
				Vector2f((x * TILE_SIZE) + TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);

			rVaLevel[currentVertex + 3].position = 
				Vector2f((x * TILE_SIZE), (y * TILE_SIZE) + TILE_SIZE);

			// Which tile from the sprite sheet should we use
			int verticalOffset = arrayLevel[y][x] * TILE_SIZE;

			rVaLevel[currentVertex + 0].texCoords = 
				Vector2f(0, 0 + verticalOffset);

			rVaLevel[currentVertex + 1].texCoords = 
				Vector2f(TILE_SIZE, 0 + verticalOffset);

			rVaLevel[currentVertex + 2].texCoords = 
				Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);

			rVaLevel[currentVertex + 3].texCoords = 
				Vector2f(0, TILE_SIZE + verticalOffset);

			// Position ready for the next four vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}

	return arrayLevel;
}

Vector2i LevelManager::getLevelSize()
{
	return m_LevelSize;
}

int LevelManager::getCurrentLevel()
{
	return m_CurrentLevel;
}

//float LevelManager::getTimeLimit()
//{
//	return m_BaseTimeLimit * m_TimeModifier;
//
//}
Vector2f LevelManager::getStartPosition()
{
	return m_StartPosition;
}
