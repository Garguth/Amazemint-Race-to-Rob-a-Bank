//#include "stdafx.h"
#include "Engine.h"


void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// Handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			// Handle the player starting the game
			if (!Joystick::isConnected(0))
			{
				if (Keyboard::isKeyPressed(Keyboard::Return))
				{
					m_Playing = true;
				}
			}
			// Switch between Thomas and Bob
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}

			// Switch between full and split-screen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen;
			}
			if (!Joystick::isConnected(0))
			{
				if (Keyboard::isKeyPressed(Keyboard::H))
				{
					mamaCocoIsAlive = true;
				}
			}
			

		}

		if (m_Thomas.m_InteractPressed && m_Playing)
		{
			m_Thomas.m_InteractPressed = false;
			m_Thomas.m_disableMovement = false;
		}

		if (m_Bob.m_InteractPressed && m_Playing)
		{
			m_Bob.m_InteractPressed = false;
			m_Bob.m_disableMovement = false;
		}

		if (Joystick::isConnected(0) || Joystick::isConnected(1))
		{
			if (event.type == Event::JoystickMoved)
			{
				unsigned int njoy = event.joystickMove.joystickId; // Joy Number
				sf::Joystick::Axis eje = event.joystickMove.axis;  // Axis moved

				float pos = event.joystickMove.position; // New position

				if (njoy == 0)
				{
					if (eje > 5 && eje < 8) //dpad
					{
						cout << njoy << "\t" << eje << "\t" << pos << "  \t player 1" << endl;
					}


					if (eje == 2)//trigger
					{
						if (pos > 1)
							cout << njoy << "\t" << eje << "\t" << pos << "  \tleft, player 1" << endl;

						if (pos < -1)
							cout << njoy << "\t" << eje << "\t" << pos << "  \tright, player 1" << endl;
					}
				}
				if (njoy == 1)
				{
					if (eje > 5 && eje < 8) //dpad
					{
						cout << njoy << "\t" << eje << "\t" << pos << "  \t player 2" << endl;
					}


					if (eje == 2)//trigger
					{
						if (pos > 1)
							cout << njoy << "\t" << eje << "\t" << pos << "  \tleft, player 2" << endl;

						if (pos < -1)
							cout << njoy << "\t" << eje << "\t" << pos << "  \tright, player 2" << endl;
					}
				}
				if (m_Thomas.m_disableMovement == false)
				{
					if ((njoy == 0) && (eje == 6) && (pos < -50))
					{
						m_Thomas.m_LeftPressed = true;
					}
					else if ((njoy == 0) && (eje == 6) && (pos > -50))
					{
						m_Thomas.m_LeftPressed = false;
					}

					if ((njoy == 0) && (eje == 6) && (pos > 50))
					{
						m_Thomas.m_RightPressed = true;
					}
					else if ((njoy == 0) && (eje == 6) && (pos < 50))
					{
						m_Thomas.m_RightPressed = false;
					}
					if ((njoy == 0) && (eje == 7) && (pos < -50))
					{
						m_Thomas.m_UpPressed = true;
					}
					else if ((njoy == 0) && (eje == 7) && (pos > -50))
					{
						m_Thomas.m_UpPressed = false;
					}
					if ((njoy == 0) && (eje == 7) && (pos > 50))
					{
						m_Thomas.m_DownPressed = true;
					}
					else if ((njoy == 0) && (eje == 7) && (pos < 50))
					{
						m_Thomas.m_DownPressed = false;
					}
				}
				if (m_Bob.m_disableMovement == false)
				{
					if ((njoy == 1) && (eje == 6) && (pos < -50))
					{
						m_Bob.m_LeftPressed = true;
					}
					else if ((njoy == 1) && (eje == 6) && (pos > -50))
					{
						m_Bob.m_LeftPressed = false;
					}
					if ((njoy == 1) && (eje == 6) && (pos > 50))
					{
						m_Bob.m_RightPressed = true;
					}
					else if ((njoy == 1) && (eje == 6) && (pos < 50))
					{
						m_Bob.m_RightPressed = false;
					}
					if ((njoy == 1) && (eje == 7) && (pos < -50))
					{
						m_Bob.m_UpPressed = true;
					}
					else if ((njoy == 1) && (eje == 7) && (pos > -50))
					{
						m_Bob.m_UpPressed = false;
					}
					if ((njoy == 1) && (eje == 7) && (pos > 50))
					{
						m_Bob.m_DownPressed = true;
					}
					else if ((njoy == 1) && (eje == 7) && (pos < 50))
					{
						m_Bob.m_DownPressed = false;
					}
				}
			}


			if (event.type == Event::JoystickButtonPressed)
			{

				if (Joystick::isButtonPressed(0, BUTTON_A))
				{
					cout << " YOU PRESSED A, player1" << endl;
				}
				if (Joystick::isButtonPressed(0, BUTTON_B))
				{
					cout << " YOU PRESSED B, player1" << endl;
				}
				if (Joystick::isButtonPressed(0, BUTTON_X))
				{
					cout << " YOU PRESSED X, player1" << endl;
				}
				if (Joystick::isButtonPressed(0, BUTTON_Y))
				{
					cout << " YOU PRESSED Y, player1" << endl;
				}
				if (Joystick::isButtonPressed(0, BUTTON_BACK))
				{
					cout << " YOU PRESSED back, player1" << endl;
				}
				if (Joystick::isButtonPressed(0, BUTTON_START))
				{
					cout << " YOU PRESSED start, player1" << endl;
				}
				if (Joystick::isButtonPressed(0, BUTTON_LEFTB))
				{
					cout << " YOU PRESSED left bumper, player1" << endl;
				}
				if (Joystick::isButtonPressed(0, BUTTON_RIGHTB))
				{
					cout << " YOU PRESSED right bumper, player1" << endl;
				}
				if (Joystick::isButtonPressed(0, BUTTON_LEFT_STICK_DOWN))
				{
					cout << " YOU PRESSED left stick down, player1" << endl;
				}
				if (Joystick::isButtonPressed(0, BUTTON_RIGHT_STICK_DOWN))
				{
					cout << " YOU PRESSED right stick down, player1" << endl;
				}

				if (Joystick::isButtonPressed(1, BUTTON_A))
				{
					cout << " YOU PRESSED A, player2" << endl;
				}
				if (Joystick::isButtonPressed(1, BUTTON_B))
				{
					cout << " YOU PRESSED B, player2" << endl;
				}
				if (Joystick::isButtonPressed(1, BUTTON_X))
				{
					cout << " YOU PRESSED X, player2" << endl;
				}
				if (Joystick::isButtonPressed(1, BUTTON_Y))
				{
					cout << " YOU PRESSED Y, player2" << endl;
				}
				if (Joystick::isButtonPressed(1, BUTTON_BACK))
				{
					cout << " YOU PRESSED back, player2" << endl;
				}
				if (Joystick::isButtonPressed(1, BUTTON_START))
				{
					cout << " YOU PRESSED start, player2" << endl;
				}
				if (Joystick::isButtonPressed(1, BUTTON_LEFTB))
				{
					cout << " YOU PRESSED left bumper, player2" << endl;
				}
				if (Joystick::isButtonPressed(1, BUTTON_RIGHTB))
				{
					cout << " YOU PRESSED right bumper, player2" << endl;
				}
				if (Joystick::isButtonPressed(1, BUTTON_LEFT_STICK_DOWN))
				{
					cout << " YOU PRESSED left stick down, player2" << endl;
				}
				if (Joystick::isButtonPressed(1, BUTTON_RIGHT_STICK_DOWN))
				{
					cout << " YOU PRESSED right stick down, player2" << endl;
				}

				if ((Joystick::isButtonPressed(0, BUTTON_START) || Joystick::isButtonPressed(1, BUTTON_START)) && m_Playing)
				{
					paused = !paused;
					if (paused)
					{
						pauseScreen();
						cout << "paused" << endl;
					}
					else
					{
						cout << "unpaused" << endl;
					}

				}
				
				if (Joystick::isButtonPressed(0, BUTTON_A) && m_Playing)
				{
					m_Thomas.m_InteractPressed = true;
					m_Thomas.m_disableMovement = true;
				}

				if (Joystick::isButtonPressed(1, BUTTON_A) && m_Playing)
				{
					m_Bob.m_InteractPressed = true;
					m_Bob.m_disableMovement = true;
				}
			
				if (((Joystick::isButtonPressed(0, BUTTON_START) || Joystick::isButtonPressed(1, BUTTON_START)) ||
					(Joystick::isButtonPressed(0, BUTTON_A) || Joystick::isButtonPressed(1, BUTTON_A))) && mamaCocoIsAlive)
				{
					m_Playing = true;
				}

				if ((Joystick::isButtonPressed(0, BUTTON_START) || Joystick::isButtonPressed(1, BUTTON_START)) ||
					(Joystick::isButtonPressed(0, BUTTON_A) || Joystick::isButtonPressed(1, BUTTON_A)))
				{
					mamaCocoIsAlive = true;
				}

				if ((m_Thomas.m_PlayerisDone && m_Bob.m_PlayerisDone) &&
					(Joystick::isButtonPressed(0, BUTTON_A) || Joystick::isButtonPressed(1, BUTTON_A)))
				{
					m_Window.close();
				}


			}
		}

	}	

	// Handle input specific to Thomas
	if (m_Thomas.handleInput())
	{
		// Play a jump sound
	}

	// Handle input specific to Bob
	if (m_Bob.handleInput())
	{
		// Play a jump sound
	}

}