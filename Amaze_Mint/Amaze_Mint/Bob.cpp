//#include "stdafx.h"
#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	// Associate a texture with the sprite
	rectSourceSprite = IntRect(50, 0, 50, 50);
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/bob_sprite_sheet.png"), rectSourceSprite);

//	m_HitBox = Sprite(TextureHolder::GetTexture(/////////////////////////////////////// Maybe for rotation // ***DIEGO***
//		"graphics/bob.png"));

	m_Sprite.setOrigin(25, 25);
//	m_HitBox.setOrigin(25, 25);/////////////////////////////////////// Maybe for rotation // ***DIEGO***

//	m_HitBox.setRotation(135);/////////////////////////////////////// Maybe for rotation // ***DIEGO***

	m_JumpDuration = .25;
	money = 0;
	health = 3;
	m_hasMasterKey = false;
	m_hasScrewDriver = false;
	m_PlayerisDone = false;
	m_disableMovement = false;
	m_IsInteracting = false;
	timer = 0;
	TotalMoney = 0;
}

bool Bob::handleInput()
{
	m_JustJumped = false;

	//if (Keyboard::isKeyPressed(Keyboard::Up))
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
		if (Keyboard::isKeyPressed(Keyboard::P))
		{
				m_InteractPressed = true;
				m_disableMovement = true;
		}


	}
	if (m_disableMovement == false)
	{
		if (Keyboard::isKeyPressed(Keyboard::L))
		{
			m_PlayerisDone = true;
		}
		if (!Joystick::isConnected(1))
		{
			if (Keyboard::isKeyPressed(Keyboard::Left) && disable_left == false)
			{
				m_LeftPressed = true;

			}
			else
			{
				m_LeftPressed = false;
			}


			if (Keyboard::isKeyPressed(Keyboard::Right) && disable_right == false)
			{

				m_RightPressed = true;

			}
			else
			{
				m_RightPressed = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down) && disable_up == false)
			{
				m_UpPressed = true;
			}
			else
			{
				m_UpPressed = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Up) && disable_down == false)
			{
				m_DownPressed = true;
			}
			else
			{
				m_DownPressed = false;
			}
		}
		if (m_UpPressed)
		{
			if (m_LeftPressed)
			{
				//spin(m_Sprite.getRotation(), 225);
//				m_Sprite.setRotation(225);
			}
			else if (m_RightPressed)
			{
				//spin(m_Sprite.getRotation(), 135);
//				m_Sprite.setRotation(135);
			}
//			else
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
//				m_Sprite.setRotation(315);
			}
			else if (m_RightPressed)
			{
				//spin(m_Sprite.getRotation(), 45);
//				m_Sprite.setRotation(45);
			}
//			else
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
	}
	else
	{

		/*m_LeftPressed = false;
		m_RightPressed = false;
		m_UpPressed = false;

		m_DownPressed = false;*/

	}
	return m_JustJumped;
}