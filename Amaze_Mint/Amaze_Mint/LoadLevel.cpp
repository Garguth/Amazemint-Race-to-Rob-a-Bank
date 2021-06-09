//#include "stdafx.h"
#include "Engine.h"

void Engine::loadLevel(int currentLevel)
{
	m_Playing = false;

	if (currentLevel == 2)
	{
		amount = 4;
	}
	else if(currentLevel == 1)
	{
		amount = 1;
	}

	// Delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];

	}
	delete[] m_ArrayLevel;

	// Load the next 2d array with the map for the level
	// And repopulate the vertex array as well
	m_ArrayLevel = m_LM.nextLevel(m_VALevel, currentLevel);

	// How long is this new time limit
	//m_TimeRemaining = m_LM.getTimeLimit();

	// Spawn Thomas and Bob
	m_Thomas.spawn(m_LM.getStartPosition(), 0);
	m_Bob.spawn(m_LM.getStartPosition(), 0);
	if (currentLevel == 2)
	{
		pathListX[0].clear();
		pathListY[0].clear();
		enState[0] = PATROL;
		delete[] Mark[0];
		Mark[0] = NULL;
		m_Enemy[0].spawn(Vector2f(1650, 400), 0);
		m_Enemy[1].spawn(Vector2f(450, 900), 0);
		m_Enemy[2].spawn(Vector2f(2250, 750), 0);
		m_Enemy[3].spawn(Vector2f(1400, 1250), 0);
	}
	else if (currentLevel == 1)
	{
		m_Enemy[0].spawn(Vector2f(1200, 1150), 0);
				
	}
	//item1.spawn((Vector2f(1000, 1000)), 0);
	for (int i = 0; i < 4; i++)
	{
		moneyBills[i].spawn((Vector2f(100000, 100000)), 0);
	}
	item2.spawn((Vector2f(10000, 100000)), 0);

		item3.spawn((Vector2f(100000, 100000)), 0);
		item4.spawn((Vector2f(100000, 100000)), 0);
		item5.spawn((Vector2f(100000, 100000)), 0);
	//	SpawnItem1(item1,2,2);
		SpawnItem1(item2, 3, 23);
		SpawnItem1(item3, 2, 23);
		SpawnItem1(item4, 3, 2);
		SpawnItem1(item5, 2, 2);
	// Make sure this code isn't run again
	m_NewLevelRequired = false;
}