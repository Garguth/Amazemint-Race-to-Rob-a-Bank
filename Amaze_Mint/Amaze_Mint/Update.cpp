//#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_Bob.health <= 0)
	{
		m_Bob.m_disableMovement = true;
		m_Bob.m_PlayerisDone = true;
	    m_Bob.m_Speed = 0;
	}
	if (m_Thomas.health <= 0)
	{
		m_Thomas.m_disableMovement = true;
		m_Thomas.m_PlayerisDone = true;
		m_Thomas.m_Speed = 0;
	}

	if (m_Thomas.m_IsInteracting == true)
	{
		if (m_Thomas.timer < 300)
		{
			m_Thomas.m_disableMovement = true;
			m_Thomas.timer++; 
			m_Thomas.m_Sprite = Sprite(TextureHolder::GetTexture(
				"graphics/thomas_bag.png"));
			m_Thomas.m_Sprite.setOrigin(25, 25);
		}
		else
		{
			m_Thomas.timer = 0;
			m_Thomas.m_disableMovement = false;
			m_Thomas.m_IsInteracting = false;
			m_Thomas.money += m_Thomas.moneyget;
			m_Thomas.m_Sprite = Sprite(TextureHolder::GetTexture(
				"graphics/thomas_sprite_sheet.png"),m_Thomas.rectSourceSprite);
			m_Thomas.m_Sprite.setOrigin(25, 25);
		}
	}
	if (m_Bob.m_IsInteracting == true)
	{
		if (m_Bob.timer < 300)
		{
			m_Bob.m_disableMovement = true;
			m_Bob.timer++;
			m_Bob.m_Sprite = Sprite(TextureHolder::GetTexture(
				"graphics/bob_bag.png"));
			m_Bob.m_Sprite.setOrigin(25, 25);
		}
		else
		{
			m_Bob.m_disableMovement = false;
			m_Bob.m_IsInteracting = false;
			m_Bob.timer = 0;
			m_Bob.money += m_Bob.moneyget;
			m_Bob.m_Sprite = Sprite(TextureHolder::GetTexture(
				"graphics/bob_sprite_sheet.png"), m_Bob.rectSourceSprite);
			m_Bob.m_Sprite.setOrigin(25, 25);
		}
	}
	if (currentlevel == 1)
	{
			m_Enemy[0].m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/dog.png"));
			m_Enemy[0].m_Sprite.setOrigin(25, 25);
	}
	else
	{
		m_Enemy[0].m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/player.png"));
		m_Enemy[0].m_Sprite.setOrigin(25, 25);
	}
	if (item2.timer < 1500)
	{
		item2.timer++;
	}
	else
	{
		item2.timer = 0;
		SpawnItem1(item2, 10, 23);
	}
	if (item3.timer < 1000)
	{
	
		item3.timer++;
	}
	else
	{
		item3.timer = 0;
		SpawnItem1(item3, 10, 23);
	}
	if (item4.timer < 2000)
	{
		item4.timer++;
	}
	else
	{
		item4.timer = 0;
		SpawnItem1(item4, 8, 2);
	}
	if (item5.timer < 1500)
	{

		item5.timer++;
	}
	else
	{
		item5.timer = 0;
		SpawnItem1(item5, 8, 2);
	}
	if (m_NewLevelRequired)
	{
		// These calls to spawn will be moved to a new
		// LoadLevel function soon
		// Spawn Thomas and Bob
		//m_Thomas.spawn(Vector2f(0,0), GRAVITY);
		//m_Bob.spawn(Vector2f(100, 0), GRAVITY);

		// Make sure spawn is called only once
		//m_TimeRemaining = 10;
		//m_NewLevelRequired = false;

		// Load a level
		loadLevel(currentlevel);
		
		centerPoint();
	}

	if (m_Playing)
	{
		// Update Thomas
		m_Thomas.update(dtAsSeconds);

		// Update Bob
		m_Bob.update(dtAsSeconds);

		for (int i = 0; i < 4; i++)
		{
			m_Enemy[i].update(dtAsSeconds);
		}


	//	item1.update(dtAsSeconds);
		// Detect collisions and see if characters have reached the goal tile
		// The second part of the if condition is only executed
		// when thomas is touching the home tile
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			// New level required
			m_NewLevelRequired = true;

			// Play the reach goal sound

		}
		else
		{
			// Run bobs collision detection
			detectCollisions(m_Bob);
		}

		// Let bob and thomas jump on each others heads
	/*	if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}*/
		// Item detection

		//else if (m_Thomas.getFeet().intersects(item1.getHead()))
		//{
		//	m_Thomas.money++;
		//	item1.spawn(Vector2f((rand() % 100) + 100, (rand() % 100) + 100), 0);
		//	//detectCollisions(item1);
		//}
		//else if (m_Thomas.getLeft().intersects(item1.getRight()))
		//{
		//	m_Thomas.money++;
		//	item1.spawn(Vector2f((rand() % 100) + 100, (rand() % 100) + 100), 0);
		//	//detectCollisions(item1);
		//}
		//else if (m_Thomas.getLeft().intersects(item1.getRight()))
		//{
		//	m_Thomas.money++;
		//	item1.spawn(Vector2f((rand() % 100) + 100, (rand() % 100) + 100), 0);
		//	//detectCollisions(item1);
		//}
		// Count down the time the player has left
		

		// Have Thomas and Bob run out of time?


	}// End if playing
		
	// Set the appropriate view around the appropriate character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		// Centre full screen around appropriate character
		if (m_Character1)
		{
			//m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			//m_MainView.setCenter(m_Bob.getCenter());
		}
	}
}