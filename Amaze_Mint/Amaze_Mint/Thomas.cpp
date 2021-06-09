//#include "stdafx.h"
#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	// Associate a texture with the sprite
	rectSourceSprite = IntRect(50, 0, 50, 50);
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/thomas_sprite_sheet.png"), rectSourceSprite);
	
	m_Sprite.setOrigin(25, 25);
	money = 0;
	m_JumpDuration = .45;
	health = 3;
	m_hasMasterKey = false;
	m_hasScrewDriver = false;
	m_disableMovement = false;
	m_PlayerisDone = false;
	m_IsInteracting = false;
	timer = 0;
	TotalMoney = 0;
}
// A virtual function
bool Thomas::handleInput()
{
	m_JustJumped = false;

	njoy = event.joystickMove.joystickId; // Joy Number
	eje = event.joystickMove.axis;  // Axis moved

	event.joystickMove.position; // New position

	//if (Keyboard::isKeyPressed(Keyboard::W))
	//{

	//	// Start a jump if not already jumping
	//	// but only if standing on a block (not falling)
	//	if (!m_IsJumping && !m_IsFalling)
	//	{
	//		m_IsJumping = true;
	//		m_TimeThisJump = 0;
	//		m_JustJumped = true;
	//	}
	//}
	//else
	//{
	//	m_IsJumping = false;
	//	m_IsFalling = true;

	//}
	if (!Joystick::isConnected(0))
	{
		if (Keyboard::isKeyPressed(Keyboard::Z))
		{
			m_InteractPressed = true;
			m_disableMovement = true;
		}

	}
	if (m_disableMovement == false)
	{
		if (Keyboard::isKeyPressed(Keyboard::K))
		{
			m_PlayerisDone = true;
		}
		if (!Joystick::isConnected(0))
		{
			if (Keyboard::isKeyPressed(Keyboard::A)&&disable_left == false)
			{
				m_LeftPressed = true;
			}
			else
			{
				m_LeftPressed = false;
			}

			if (Keyboard::isKeyPressed(Keyboard::D) && disable_right == false)
			{
				m_RightPressed = true;
			}
			else
			{
				m_RightPressed = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::S) && disable_down == false)
			{
				m_UpPressed = true;
			}
			else
			{
				m_UpPressed = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::W) && disable_up == false)
			{
				m_DownPressed = true;
			}
			else
			{
				m_DownPressed = false;
			}
		}
	}
	else
	{

		//m_LeftPressed = false;
		//m_RightPressed = false;
		//m_UpPressed = false;
		//m_DownPressed = false;
	}
	if (m_UpPressed)
	{
		if (m_LeftPressed)
		{
			//spin(m_Sprite.getRotation(), 225);
//			m_Sprite.setRotation(225);
		}
		else if (m_RightPressed)
		{
			//spin(m_Sprite.getRotation(), 135);
//			m_Sprite.setRotation(135);
		}
//		else
		{
			//spin(m_Sprite.getRotation(), 360);
			m_Sprite.setRotation(180);
		}
	}
	else if (m_DownPressed)
	{
		if (m_LeftPressed)
		{
			//spin(m_Sprite.getRotation(), 315);
//			m_Sprite.setRotation(315);
		}
		else if (m_RightPressed)
		{
			//spin(m_Sprite.getRotation(), 45);
//			m_Sprite.setRotation(45);
		}
//		else
		{
			//spin(m_Sprite.getRotation(), 180);
			m_Sprite.setRotation(360);
		}
	}
	else if (m_LeftPressed)
	{
		//spin(m_Sprite.getRotation(), 270);
		m_Sprite.setRotation(270);
	}
	else if (m_RightPressed)
	{
		//spin(m_Sprite.getRotation(), 90);
		m_Sprite.setRotation(90);
	}

	return m_JustJumped;
}