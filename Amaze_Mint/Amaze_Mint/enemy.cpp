//#include "stdafx.h"
#include "enemy.h"
#include "TextureHolder.h"
#include "Engine.h"
//https://www.sfml-dev.org/tutorials/1.6/graphics-shape.php
//https://en.sfml-dev.org/forums/index.php?topic=7427.0
//https://en.sfml-dev.org/forums/index.php?topic=18042.0
enemy::enemy()
{
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/player.png"));
	m_Sprite.setOrigin(25, 25);
	timer = 0;
	for (int i = 0; i < 4; i++)
	{
		hitting[i] = false;
	}

}

bool enemy::handleInput1(int x , int y, int state)
{

	m_JustJumped = false;


		
		//e_Engine.goToX = e_Thomas.getPos().x;
		//e_Engine.goToY = e_Thomas.getPos().y;

		if (x > this->getPos().x)
		{
			m_RightPressed = true;

		}
		else
		{
			m_RightPressed = false;
		}

		if (x <= this->getPos().x)
		{
			m_LeftPressed = true;
		}
		else
		{
			m_LeftPressed = false;
		}

		if (y > this->getPos().y)
		{
			m_UpPressed = true;
		}
		else
		{
			m_UpPressed = false;
		}

		if (y <= this->getPos().y)
		{
			m_DownPressed = true;
		}
		else
		{
			m_DownPressed = false;
		}

		if (timer < 35000)
		{

			timer++;

		}
		else
		{
			timer = 0;

			if ((rand() % 2) == 0)
			{
				if (m_UpPressed)
				{
					//if (m_LeftPressed)
					//{
					//	//spin(m_Sprite.getRotation(), 225);
					//	m_Sprite.setRotation(225);
					//}
					//else if (m_RightPressed)
					//{
					//	//spin(m_Sprite.getRotation(), 135);
					//	m_Sprite.setRotation(135);
					//}
					//else
					{
						//spin(m_Sprite.getRotation(), 360);
						directionLooking = UP;
						m_Sprite.setRotation(180);
					}
				}
				else if (m_DownPressed)
				{
					//if (m_LeftPressed && !m_RightPressed)
					//{
					//	//spin(m_Sprite.getRotation(), 315);
					//	m_Sprite.setRotation(315);
					//}
					//else if (m_RightPressed && !m_LeftPressed)
					//{
					//	//spin(m_Sprite.getRotation(), 45);
					//	m_Sprite.setRotation(45);
					//}
					//else
					{
						//spin(m_Sprite.getRotation(), 180);
						directionLooking = DOWN;
						m_Sprite.setRotation(360);
					}
				}
			}
			else
			{
				if (m_LeftPressed)
				{
					//spin(m_Sprite.getRotation(), 270);
					directionLooking = LEFT;
					m_Sprite.setRotation(270);
				}
				else if (m_RightPressed)
				{
					//spin(m_Sprite.getRotation(), 90);
					directionLooking = RIGHT;
					m_Sprite.setRotation(90);
				}
			}
			

		}
		



	return m_JustJumped;
}


void enemy::spin(int from, int to)
{
	if (from > to)
	{
		for (float i = from; i > to; i--)
		{
			m_Sprite.setRotation(i);
		}
	}
	else
	{
		for (float i = to; i > from; i--)
		{
			m_Sprite.setRotation(i);
		}
	}
}


void enemy::spawn(Vector2f startPosition, float gravity)
{
	// Place the player at the starting point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	// Initialize the gravity
	m_Gravity = gravity;

	// Move the sprite in to position
	m_Sprite.setPosition(m_Position);

}

void enemy::update(float elapsedTime)
{

	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}

	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}

	if (m_UpPressed)
	{
		m_Position.y += m_Speed * elapsedTime;
	}

	if (m_DownPressed)
	{
		m_Position.y -= m_Speed * elapsedTime;
	}
	// Handle Jumping
	if (m_IsJumping)
	{
		// Update how long the jump has been going
		m_TimeThisJump += elapsedTime;

		// Is the jump going upwards
		if (m_TimeThisJump < m_JumpDuration)
		{
			// Move up at twice gravity
			m_Position.y -= m_Gravity * 2 * elapsedTime;
		}
		else
		{
			m_IsJumping = false;
			m_IsFalling = true;
		}

	}

	// Apply gravity
	if (m_IsFalling)
	{
		m_Position.y += m_Gravity * elapsedTime;
	}

	// Update the rect for all body parts
	FloatRect r = getPosition();


	// Feet
	m_Feet.left = 1;
	m_Feet.top = 1;
	m_Feet.width = 1;
	m_Feet.height = 1;

	// Head
	m_Head.left = 1;
	m_Head.top = 1;
	m_Head.width = 1;
	m_Head.height = 1;

	//// Right
	m_Right.left = 1;
	m_Right.top = 1;
	m_Right.width = 1;
	m_Right.height = 1;

	//// Left
	m_Left.left = 1;
	m_Left.top = 1;
	m_Left.width = 1;
	m_Left.height = 1;

	// Move the sprite into position
	m_Sprite.setPosition(m_Position);

}

FloatRect enemy::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f enemy::getCenter()
{
	return Vector2f(
		m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2
	);
}
Vector2f enemy::getPos()
{
	return Vector2f(
		m_Position.x,
		m_Position.y
	);
}

FloatRect enemy::getFeet()
{
	return m_Feet;
}

FloatRect enemy::getHead()
{
	return m_Head;
}

FloatRect enemy::getLeft()
{
	return m_Left;
}

FloatRect enemy::getRight()
{
	return m_Right;
}

Sprite enemy::getSprite()
{
	return m_Sprite;
}



void enemy::stopFalling(float position)
{
	m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
}

void enemy::stopUp(float position)
{
	m_Position.y = position + (getPosition().height / 4);
	m_Sprite.setPosition(m_Position);
}

void enemy::stopRight(float position)
{

	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void enemy::stopLeft(float position)
{
	m_Position.x = position + m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void enemy::stopJump()
{
	// Stop a jump early 
	m_IsJumping = false;
	m_IsFalling = true;
}



