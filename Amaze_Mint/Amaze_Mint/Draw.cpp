//#include "stdafx.h"
#include "Engine.h"

SortingPoint p0;

SortingPoint SortpointsT[60];
SortingPoint SortpointsB[60];//Initialization for angle sorting
float angle = 0;
bool SortBYANGLEE(const SortingPoint& lhs, const SortingPoint& rhs) //functor determining the lowest angle
{
	return lhs.angleP > rhs.angleP;
}

void Engine::draw()
{
	InitializeWalls();
	for (int x = 1; x < rayOBJ.NUMsegments; x++)
	{
		rayOBJ.Points[x].x = rayOBJ.Lines[x].ax;
		rayOBJ.Points[x].y = rayOBJ.Lines[x].ay;
	}


	float width = VideoMode::getDesktopMode().width / 2;
	float height = VideoMode::getDesktopMode().height / 2;


	VertexArray lineT(Lines, 2);
	VertexArray lineB(Lines, 2);

	//rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.segmentFinal, m_Bob.getCenter().x, m_Bob.getCenter().y);


	
	// Rub out the last frame
	m_Window.clear(Color::Black);
	
	if (!m_SplitScreen)
	{
		// Switch to background view
		m_Window.setView(m_BGMainView);
		// Draw the background
		m_Window.draw(m_BackgroundSprite);
		// Switch to m_MainView
		m_Window.setView(m_MainView);

		// Draw the Level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw thomas
		if (m_Thomas.m_PlayerisDone == false)
		{
			if (spriteClock.getElapsedTime().asMicroseconds() > 3700 && m_Thomas.m_IsInteracting == false)
			{
				if (m_Thomas.rectSourceSprite.left == 300)
				{
					m_Thomas.rectSourceSprite.left = 0;
				}
				else
				{
					m_Thomas.rectSourceSprite.left += 50;
				}
				m_Thomas.m_Sprite.setTextureRect(m_Thomas.rectSourceSprite);
			}
			m_Window.draw(m_Thomas.getSprite());
		}

		
		m_Window.draw(item1.getSprite());
		m_Window.draw(item2.getSprite());
		m_Window.draw(item3.getSprite());
		m_Window.draw(item4.getSprite());
		m_Window.draw(item5.getSprite());
		for (int i = 0; i < 4; i++)
		{
			m_Window.draw(moneyBills[i].getSprite());
		}
		if (m_Bob.m_PlayerisDone == false)
		{
			if (spriteClock.getElapsedTime().asMicroseconds() > 3700 && m_Bob.m_IsInteracting == false)
			{
				if (m_Bob.rectSourceSprite.left == 300)
				{
					m_Bob.rectSourceSprite.left = 0;
				}
				else
				{
					m_Bob.rectSourceSprite.left += 50;
				}
				m_Bob.m_Sprite.setTextureRect(m_Bob.rectSourceSprite);
			}
			m_Window.draw(m_Bob.getSprite());
		}

//		VertexArray lineenemy(Lines, 2);
//		VertexArray lineenemy2(Lines, 2);
		for (int i = 0; i < 4; i++)
		{
			m_Window.draw(m_Enemy[i].getSprite());
			if (Mark[i] != NULL)
			{
				Mark[i]->setPosition(m_Enemy[i].getPos().x - 20, m_Enemy[i].getPos().y - 100);
				m_Window.draw(*Mark[i]);
			}
			
			{
				float TCx = m_Enemy[i].getPos().x + 25;
				float TCy = m_Enemy[i].getPos().y + 25;

				rayOBJ.rayMake.ax = TCx;
				rayOBJ.rayMake.ay = TCy;

				if ((m_Enemy[i].directionLooking == DOWN && m_Thomas.getPos().y < m_Enemy[i].getPos().y) ||
					(m_Enemy[i].directionLooking == UP && m_Thomas.getPos().y > m_Enemy[i].getPos().y) ||
					(m_Enemy[i].directionLooking == LEFT && m_Thomas.getPos().x < m_Enemy[i].getPos().x) ||
					(m_Enemy[i].directionLooking == RIGHT && m_Thomas.getPos().x > m_Enemy[i].getPos().x))
				{
					rayOBJ.rayMake.bx = m_Thomas.getCenter().x; //Assigns rays endpoint to segment corner
					rayOBJ.rayMake.by = m_Thomas.getCenter().y;


					rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.Lines, TCx, TCy);

//					lineenemy[1].position = Vector2f(rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay); //generate a line from Bob to every segment corner with intersections#

//					lineenemy[0].position = Vector2f(rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by);


					if ((rayOBJ.rayFinal.bx == rayOBJ.rayMake.bx && rayOBJ.rayFinal.by == rayOBJ.rayMake.by) && !m_Thomas.m_PlayerisDone)
					{
						m_Enemy[i].hitting[0] = true;
					}
					else
					{
						m_Enemy[i].hitting[0] = false;
					}


//					lineenemy[1].color = sf::Color::Green;
//					lineenemy[0].color = sf::Color::Green;

//					m_Window.draw(lineenemy);//thomas
				}
				{
					float TCx = m_Enemy[i].getPos().x - 25;
					float TCy = m_Enemy[i].getPos().y - 25;

					rayOBJ.rayMake.ax = TCx;
					rayOBJ.rayMake.ay = TCy;

					if ((m_Enemy[i].directionLooking == DOWN && m_Thomas.getPos().y < m_Enemy[i].getPos().y) ||
						(m_Enemy[i].directionLooking == UP && m_Thomas.getPos().y > m_Enemy[i].getPos().y) ||
						(m_Enemy[i].directionLooking == LEFT && m_Thomas.getPos().x < m_Enemy[i].getPos().x) ||
						(m_Enemy[i].directionLooking == RIGHT && m_Thomas.getPos().x > m_Enemy[i].getPos().x))
					{
						rayOBJ.rayMake.bx = m_Thomas.getCenter().x - 50; //Assigns rays endpoint to segment corner
						rayOBJ.rayMake.by = m_Thomas.getCenter().y - 50;


						rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.Lines, TCx, TCy);

//						lineenemy[1].position = Vector2f(rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay); //generate a line from Bob to every segment corner with intersections#

//						lineenemy[0].position = Vector2f(rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by);

						if ((rayOBJ.rayFinal.bx == rayOBJ.rayMake.bx && rayOBJ.rayFinal.by == rayOBJ.rayMake.by) && !m_Thomas.m_PlayerisDone)
						{
							m_Enemy[i].hitting[1] = true;
						}
						else
						{
							m_Enemy[i].hitting[1] = false;
						}


//						lineenemy[1].color = sf::Color::Green;
//						lineenemy[0].color = sf::Color::Green;

//						m_Window.draw(lineenemy);//thomas
					}
				}
				{
					float TCx = m_Enemy[i].getPos().x - 25;
					float TCy = m_Enemy[i].getPos().y + 25;

					rayOBJ.rayMake.ax = TCx;
					rayOBJ.rayMake.ay = TCy;

					if ((m_Enemy[i].directionLooking == DOWN && m_Thomas.getPos().y < m_Enemy[i].getPos().y) ||
						(m_Enemy[i].directionLooking == UP && m_Thomas.getPos().y > m_Enemy[i].getPos().y) ||
						(m_Enemy[i].directionLooking == LEFT && m_Thomas.getPos().x < m_Enemy[i].getPos().x) ||
						(m_Enemy[i].directionLooking == RIGHT && m_Thomas.getPos().x > m_Enemy[i].getPos().x))
					{
						rayOBJ.rayMake.bx = m_Thomas.getCenter().x - 50; //Assigns rays endpoint to segment corner
						rayOBJ.rayMake.by = m_Thomas.getCenter().y;


						rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.Lines, TCx, TCy);

//						lineenemy[1].position = Vector2f(rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay); //generate a line from Bob to every segment corner with intersections#

//						lineenemy[0].position = Vector2f(rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by);

						if ((rayOBJ.rayFinal.bx == rayOBJ.rayMake.bx && rayOBJ.rayFinal.by == rayOBJ.rayMake.by) && !m_Thomas.m_PlayerisDone)
						{
							m_Enemy[i].hitting[2] = true;
						}
						else
						{
							m_Enemy[i].hitting[2] = false;
						}


//						lineenemy[1].color = sf::Color::Green;
//						lineenemy[0].color = sf::Color::Green;

//						m_Window.draw(lineenemy);//thomas
					}

					{
						float TCx = m_Enemy[i].getPos().x + 25;
						float TCy = m_Enemy[i].getPos().y - 25;

						rayOBJ.rayMake.ax = TCx;
						rayOBJ.rayMake.ay = TCy;

						if ((m_Enemy[i].directionLooking == DOWN && m_Thomas.getPos().y < m_Enemy[i].getPos().y) ||
							(m_Enemy[i].directionLooking == UP && m_Thomas.getPos().y > m_Enemy[i].getPos().y) ||
							(m_Enemy[i].directionLooking == LEFT && m_Thomas.getPos().x < m_Enemy[i].getPos().x) ||
							(m_Enemy[i].directionLooking == RIGHT && m_Thomas.getPos().x > m_Enemy[i].getPos().x))
						{
							rayOBJ.rayMake.bx = m_Thomas.getCenter().x; //Assigns rays endpoint to segment corner
							rayOBJ.rayMake.by = m_Thomas.getCenter().y - 50;


							rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.Lines, TCx, TCy);

//							lineenemy[1].position = Vector2f(rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay); //generate a line from Bob to every segment corner with intersections#

//							lineenemy[0].position = Vector2f(rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by);

							if ((rayOBJ.rayFinal.bx == rayOBJ.rayMake.bx && rayOBJ.rayFinal.by == rayOBJ.rayMake.by) && !m_Thomas.m_PlayerisDone)
							{
								m_Enemy[i].hitting[3] = true;
							}
							else
							{
								m_Enemy[i].hitting[3] = false;
							}


//							lineenemy[1].color = sf::Color::Green;
//							lineenemy[0].color = sf::Color::Green;

//							m_Window.draw(lineenemy);//thomas
						}
					}
				}
				if (m_Enemy[i].hitting[0] && m_Enemy[i].hitting[1] && m_Enemy[i].hitting[2] && m_Enemy[i].hitting[3])
				{
					
					delete[] Mark[i];
					Mark[i] = NULL;
					Mark[i] = new Sprite;
					Mark[i]->setTexture(m_ExclamationTexture);
					time_detected_enemy = true;
					if (enState[i] != CHASE)
					{
						pathListX[i].clear();
						pathListY[i].clear();
					}


					hit[i] = false;
					enState[i] = CHASE;
					/*here*/						//goToX[i] = m_Thomas.getPos().x;
					goToX[i] = m_Thomas.getCenter().x - 25;
					/*here*/						//goToY[i] = m_Thomas.getPos().y;
					goToY[i] = m_Thomas.getCenter().y - 25;


					
				}
			}
			for (int p = 0; p < 4; p++)
			{
				m_Enemy[i].hitting[p] = false;
			}
			{
			float TCx = m_Enemy[i].getPos().x + 25;
			float TCy = m_Enemy[i].getPos().y + 25;

			rayOBJ.rayMake.ax = TCx;
			rayOBJ.rayMake.ay = TCy;

			if ((m_Enemy[i].directionLooking == DOWN && m_Bob.getPos().y < m_Enemy[i].getPos().y) ||
				(m_Enemy[i].directionLooking == UP && m_Bob.getPos().y > m_Enemy[i].getPos().y) ||
				(m_Enemy[i].directionLooking == LEFT && m_Bob.getPos().x < m_Enemy[i].getPos().x) ||
				(m_Enemy[i].directionLooking == RIGHT && m_Bob.getPos().x > m_Enemy[i].getPos().x))
			{
				rayOBJ.rayMake.bx = m_Bob.getCenter().x; //Assigns rays endpoint to segment corner
				rayOBJ.rayMake.by = m_Bob.getCenter().y;


				rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.Lines, TCx, TCy);

//				lineenemy[1].position = Vector2f(rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay); //generate a line from Bob to every segment corner with intersections#

//				lineenemy[0].position = Vector2f(rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by);


				if ((rayOBJ.rayFinal.bx == rayOBJ.rayMake.bx && rayOBJ.rayFinal.by == rayOBJ.rayMake.by) && !m_Bob.m_PlayerisDone)
				{
					m_Enemy[i].hitting[0] = true;
				}
				else
				{
					m_Enemy[i].hitting[0] = false;
				}


//				lineenemy[1].color = sf::Color::Red;
//				lineenemy[0].color = sf::Color::Red;

//				m_Window.draw(lineenemy);//thomas
			}
			{
				float TCx = m_Enemy[i].getPos().x - 25;
				float TCy = m_Enemy[i].getPos().y - 25;

				rayOBJ.rayMake.ax = TCx;
				rayOBJ.rayMake.ay = TCy;

				if ((m_Enemy[i].directionLooking == DOWN && m_Bob.getPos().y < m_Enemy[i].getPos().y) ||
					(m_Enemy[i].directionLooking == UP && m_Bob.getPos().y > m_Enemy[i].getPos().y) ||
					(m_Enemy[i].directionLooking == LEFT && m_Bob.getPos().x < m_Enemy[i].getPos().x) ||
					(m_Enemy[i].directionLooking == RIGHT && m_Bob.getPos().x > m_Enemy[i].getPos().x))
				{
					rayOBJ.rayMake.bx = m_Bob.getCenter().x - 50; //Assigns rays endpoint to segment corner
					rayOBJ.rayMake.by = m_Bob.getCenter().y - 50;


					rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.Lines, TCx, TCy);

//					lineenemy[1].position = Vector2f(rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay); //generate a line from Bob to every segment corner with intersections#

//					lineenemy[0].position = Vector2f(rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by);

					if ((rayOBJ.rayFinal.bx == rayOBJ.rayMake.bx && rayOBJ.rayFinal.by == rayOBJ.rayMake.by) && !m_Bob.m_PlayerisDone)
					{
						m_Enemy[i].hitting[1] = true;
					}
					else
					{
						m_Enemy[i].hitting[1] = false;

					}

//					lineenemy[1].color = sf::Color::Red;
//					lineenemy[0].color = sf::Color::Red;

//					m_Window.draw(lineenemy);//thomas
				}
			}
			{
				float TCx = m_Enemy[i].getPos().x - 25;
				float TCy = m_Enemy[i].getPos().y + 25;

				rayOBJ.rayMake.ax = TCx;
				rayOBJ.rayMake.ay = TCy;

				if ((m_Enemy[i].directionLooking == DOWN && m_Bob.getPos().y < m_Enemy[i].getPos().y) ||
					(m_Enemy[i].directionLooking == UP && m_Bob.getPos().y > m_Enemy[i].getPos().y) ||
					(m_Enemy[i].directionLooking == LEFT && m_Bob.getPos().x < m_Enemy[i].getPos().x) ||
					(m_Enemy[i].directionLooking == RIGHT && m_Bob.getPos().x > m_Enemy[i].getPos().x))
				{
					rayOBJ.rayMake.bx = m_Bob.getCenter().x - 50; //Assigns rays endpoint to segment corner
					rayOBJ.rayMake.by = m_Bob.getCenter().y;


					rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.Lines, TCx, TCy);

//					lineenemy[1].position = Vector2f(rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay); //generate a line from Bob to every segment corner with intersections#

//					lineenemy[0].position = Vector2f(rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by);

					if ((rayOBJ.rayFinal.bx == rayOBJ.rayMake.bx && rayOBJ.rayFinal.by == rayOBJ.rayMake.by) && !m_Bob.m_PlayerisDone)
					{
						m_Enemy[i].hitting[2] = true;
					}
					else
					{
						m_Enemy[i].hitting[2] = false;
					}


//					lineenemy[1].color = sf::Color::Red;
//					lineenemy[0].color = sf::Color::Red;

//					m_Window.draw(lineenemy);//thomas
				}
				{
					float TCx = m_Enemy[i].getPos().x + 25;
					float TCy = m_Enemy[i].getPos().y - 25;

					rayOBJ.rayMake.ax = TCx;
					rayOBJ.rayMake.ay = TCy;

					if ((m_Enemy[i].directionLooking == DOWN && m_Bob.getPos().y < m_Enemy[i].getPos().y) ||
						(m_Enemy[i].directionLooking == UP && m_Bob.getPos().y > m_Enemy[i].getPos().y) ||
						(m_Enemy[i].directionLooking == LEFT && m_Bob.getPos().x < m_Enemy[i].getPos().x) ||
						(m_Enemy[i].directionLooking == RIGHT && m_Bob.getPos().x > m_Enemy[i].getPos().x))
					{
						rayOBJ.rayMake.bx = m_Bob.getCenter().x; //Assigns rays endpoint to segment corner
						rayOBJ.rayMake.by = m_Bob.getCenter().y - 50;


						rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.Lines, TCx, TCy);

//						lineenemy[1].position = Vector2f(rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay); //generate a line from Bob to every segment corner with intersections#

//						lineenemy[0].position = Vector2f(rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by);

						if ((rayOBJ.rayFinal.bx == rayOBJ.rayMake.bx && rayOBJ.rayFinal.by == rayOBJ.rayMake.by) && !m_Bob.m_PlayerisDone)
						{
							m_Enemy[i].hitting[3] = true;
						}
						else
						{
							m_Enemy[i].hitting[3] = false;
						}


					}
				}
			}
			if (m_Enemy[i].hitting[0] && m_Enemy[i].hitting[1] && m_Enemy[i].hitting[2] && m_Enemy[i].hitting[3])
			{

				delete[] Mark[i];
				Mark[i] = NULL;
				Mark[i] = new Sprite;
				Mark[i]->setTexture(m_ExclamationTexture);
				time_detected_enemy = true;
				if (enState[i] != CHASE)
				{
					pathListX[i].clear();
					pathListY[i].clear();
				}


				hit[i] = false;
				enState[i] = CHASE;
				/*here*/						//goToX[i] = m_Thomas.getPos().x;
				goToX[i] = m_Bob.getCenter().x - 25;
				/*here*/						//goToY[i] = m_Thomas.getPos().y;
				goToY[i] = m_Bob.getCenter().y - 25;



			}
			}
			for (int p = 0; p < 4; p++)
			{
				m_Enemy[i].hitting[p] = false;
			}
			
		}
		Rays ray;
		ConvexShape  Blackness(ray.NUMsegments);
		ConvexShape Blackness2(ray.NUMsegments);
		Blackness.setTexture(&m_blackBGTexture);
		Blackness2.setTexture(&m_blackBGTexture);


		float BCx = m_Bob.getCenter().x - 25;
		float BCy = m_Bob.getCenter().y - 25;
		float TCx = m_Thomas.getCenter().x - 25;
		float TCy = m_Thomas.getCenter().y - 25;



		for (int segmentNumber = 0; segmentNumber < rayOBJ.NUMsegments; segmentNumber++)
		{

			rayOBJ.rayMake.ax = BCx;
			rayOBJ.rayMake.ay = BCy;
			rayOBJ.rayMake.bx = rayOBJ.Lines[segmentNumber].ax; //Assigns rays endpoint to segment corner
			rayOBJ.rayMake.by = rayOBJ.Lines[segmentNumber].ay;


			rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.Lines, BCx, BCy);


			angle = atan2(rayOBJ.rayFinal.by - rayOBJ.rayFinal.ay, rayOBJ.rayFinal.bx - rayOBJ.rayFinal.ax);


			SortpointsB[segmentNumber].x = rayOBJ.rayFinal.bx;
			SortpointsB[segmentNumber].y = rayOBJ.rayFinal.by;
			SortpointsB[segmentNumber].angleP = angle;



			rayOBJ.rayMake.ax = TCx;
			rayOBJ.rayMake.ay = TCy;
			rayOBJ.rayMake.bx = rayOBJ.Lines[segmentNumber].ax; //Assigns rays endpoint to segment corner
			rayOBJ.rayMake.by = rayOBJ.Lines[segmentNumber].ay;


			rayOBJ.updateRays(rayOBJ.rayMake, rayOBJ.Lines, TCx, TCy);

			//lineT[0].position = Vector2f(rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay); //generate a line from Bob to every segment corner with intersections#

			//lineT[1].position = Vector2f(rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by);

			//m_Window.draw(\);


			angle = atan2(rayOBJ.rayFinal.by - rayOBJ.rayFinal.ay, rayOBJ.rayFinal.bx - rayOBJ.rayFinal.ax);


			SortpointsT[segmentNumber].x = rayOBJ.rayFinal.bx;
			SortpointsT[segmentNumber].y = rayOBJ.rayFinal.by;
			SortpointsT[segmentNumber].angleP = angle;


			
		}



		int n = sizeof(SortpointsT) / sizeof(SortpointsT[0]);

		sort(SortpointsT, SortpointsT + n, SortBYANGLEE); //Sorts the struct by the lower angle
		
		n = sizeof(SortpointsB) / sizeof(SortpointsB[0]);

		sort(SortpointsB, SortpointsB + n, SortBYANGLEE);

		for (int segmentNumber = 0; segmentNumber < rayOBJ.NUMsegments; segmentNumber++)
		{

			Blackness.setPoint(segmentNumber, Vector2f(SortpointsT[segmentNumber].x, SortpointsT[segmentNumber].y));

			Blackness2.setPoint(segmentNumber, Vector2f(SortpointsB[segmentNumber].x, SortpointsB[segmentNumber].y));
		}


		
		Blackness.setFillColor(Color(155, 155, 255, 255));
		Blackness2.setFillColor(Color(255, 155, 155, 255));
		m_BackgroundMainMenuTexture = TextureHolder::GetTexture("graphics/titleScreen.png");
		m_BackgroundMainMenu.setTexture(m_BackgroundMainMenuTexture);
		m_BackgroundMainMenu.setColor(Color(255, 255, 255, 255));
		rt1.clear(Color::Black);
		rt2.clear(Color (255, 255, 255, 5));
		rt3.clear(Color(255, 255, 255, 5));

		rt1.draw(m_BackgroundMainMenu, BlendNone);
		rt2.draw(Blackness, BlendNone);
		rt2.display();
		rt3.draw(Blackness2, BlendNone);
		rt3.display();
		m_BackgroundMainMenu.setTexture(rt2.getTexture());
		rt1.draw(m_BackgroundMainMenu, BlendAdd);
		m_BackgroundMainMenu.setTexture(rt3.getTexture());
		rt1.draw(m_BackgroundMainMenu, BlendAdd);

	/*	m_Window.draw(Blackness2);
		rt2.draw(Blackness2, BlendNone);
		rt2.display();
		m_BackgroundMainMenu.setTexture(rt2.getTexture());
		rt1.draw(m_BackgroundMainMenu, BlendAdd);
		m_Window.draw(Blackness);*/
		rt1.display();

	}

	else
	{
		// Split-screen view is active

		// First draw Thomas' side of the screen

		// Switch to background view
		m_Window.setView(m_BGLeftView);
		// Draw the background
		m_Window.draw(m_BackgroundSprite);
		// Switch to m_LeftView
		m_Window.setView(m_LeftView);

		// Draw the Level
		m_Window.draw(m_VALevel, &m_TextureTiles);
			
		// Draw thomas
		if (m_Bob.m_PlayerisDone == false)
		{
			if (spriteClock.getElapsedTime().asMicroseconds() > 3700 && m_Bob.m_IsInteracting == false)
			{
				if (m_Bob.rectSourceSprite.left == 300)
				{
					m_Bob.rectSourceSprite.left = 0;
				}
				else
				{
					m_Bob.rectSourceSprite.left += 50;
				}
				m_Bob.m_Sprite.setTextureRect(m_Bob.rectSourceSprite);
			}
			m_Window.draw(m_Bob.getSprite());
		}

	


		if (m_Thomas.m_PlayerisDone == false)
		{
			if (spriteClock.getElapsedTime().asMicroseconds() > 3700 && m_Thomas.m_IsInteracting == false)
			{
				if (m_Thomas.rectSourceSprite.left == 300)
				{
					m_Thomas.rectSourceSprite.left = 0;
				}
				else
				{
					m_Thomas.rectSourceSprite.left += 50;
				}
				m_Thomas.m_Sprite.setTextureRect(m_Thomas.rectSourceSprite);
			}
			m_Window.draw(m_Thomas.getSprite());
		}
	
		m_Window.draw(item1.getSprite());
		m_Window.draw(item2.getSprite());
		m_Window.draw(item3.getSprite());
		m_Window.draw(item4.getSprite());
		m_Window.draw(item5.getSprite());
		for (int i = 0; i < 4; i++)
		{
			m_Window.draw(moneyBills[i].getSprite());
		}
		// Now draw Bob's side of the screen


		for (int i = 0; i < 4; i++)
		{
			m_Window.draw(m_Enemy[i].getSprite());
			if (Mark[i] != NULL)
			{
				Mark[i]->setPosition(m_Enemy[i].getPos().x - 20, m_Enemy[i].getPos().y - 100);
				m_Window.draw(*Mark[i]);
			}
		}

		// Switch to background view
		m_Window.setView(m_BGRightView);
		// Draw the background
		m_Window.draw(m_BackgroundSprite);
		// Switch to m_RightView
		m_Window.setView(m_RightView);

		// Draw the Level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		if (m_Thomas.m_PlayerisDone == false)
		{
			if (spriteClock.getElapsedTime().asMicroseconds() > 3700 && m_Thomas.m_IsInteracting == false)
			{
				if (m_Thomas.rectSourceSprite.left == 300)
				{
					m_Thomas.rectSourceSprite.left = 0;
				}
				else
				{
					m_Thomas.rectSourceSprite.left += 50;
				}
				m_Thomas.m_Sprite.setTextureRect(m_Thomas.rectSourceSprite);
			}
			m_Window.draw(m_Thomas.getSprite());
		}
	

		for (int i = 0; i < 4; i++)
		{
			m_Window.draw(m_Enemy[i].getSprite());
			if (Mark[i] != NULL)
			{
				Mark[i]->setPosition(m_Enemy[i].getPos().x - 20, m_Enemy[i].getPos().y - 100);
				m_Window.draw(*Mark[i]);
			}
		}
		// Draw bob
	//	m_Window.draw(m_Bob.getSprite());

		
		if (m_Bob.m_PlayerisDone == false)
		{
			if (spriteClock.getElapsedTime().asMicroseconds() > 3700 && m_Bob.m_IsInteracting == false)
			{
				if (m_Bob.rectSourceSprite.left == 300)
				{
					m_Bob.rectSourceSprite.left = 0;
				}
				else
				{
					m_Bob.rectSourceSprite.left += 50;
				}
				m_Bob.m_Sprite.setTextureRect(m_Bob.rectSourceSprite);
			}
			m_Window.draw(m_Bob.getSprite());
		}

	}



	// Draw the HUD
	// Switch to m_HudView
	m_Window.setView(m_HudView);
	m_BackgroundMainMenu.setTexture(rt1.getTexture());
	m_Window.draw(m_BackgroundMainMenu, BlendMultiply);
	stringstream ssMoneyThomas;
	ssMoneyThomas <<"Thomas Money: " <<m_Thomas.money;

	UIMoneyThomas.setString(ssMoneyThomas.str());
	m_Window.draw(UIMoneyThomas);
	
	stringstream ssMoneyBob;
	ssMoneyBob <<"Bob Money: "<< m_Bob.money;

	UIMoneyBob.setString(ssMoneyBob.str());
	m_Window.draw(UIMoneyBob);
	if (m_Thomas.m_hasScrewDriver == true || m_Thomas.m_hasMasterKey == true)
	{
		if (m_Thomas.m_hasMasterKey == true && m_Thomas.m_hasScrewDriver != true)
		{
			stringstream ssHealthThomas;
			ssHealthThomas << "MasterCard ";

			UIHasScrewThomas.setString(ssHealthThomas.str());
			m_Window.draw(UIHasScrewThomas);
		}
		else if (m_Thomas.m_hasMasterKey != true && m_Thomas.m_hasScrewDriver == true)
		{
			stringstream ssHealthThomas;
			ssHealthThomas << "screwDriver: ";

			UIHasScrewThomas.setString(ssHealthThomas.str());
			m_Window.draw(UIHasScrewThomas);
		}
		else
		{
			stringstream ssHealthThomas;
			ssHealthThomas << "screwDriver::MasterCard ";

			UIHasScrewThomas.setString(ssHealthThomas.str());
			m_Window.draw(UIHasScrewThomas);
		}
	}

	if (m_Bob.m_hasMasterKey == true || m_Bob.m_hasScrewDriver == true)
	{
		if (m_Bob.m_hasMasterKey == true && m_Bob.m_hasScrewDriver != true)
		{
			stringstream ssHealthBob;
			ssHealthBob << "MasterCard: ";

			UIHasCardBob.setString(ssHealthBob.str());
			m_Window.draw(UIHasCardBob);
		}
		else if (m_Bob.m_hasMasterKey != true && m_Bob.m_hasScrewDriver == true)
		{
			stringstream ssHealthBob;
			ssHealthBob << "ScrewDriver: ";

			UIHasCardBob.setString(ssHealthBob.str());
			m_Window.draw(UIHasCardBob);
		}
		else
		{
			stringstream ssHealthBob;
			ssHealthBob << "ScrewDriver::MasterCard ";

			UIHasCardBob.setString(ssHealthBob.str());
			m_Window.draw(UIHasCardBob);
		}
	}
	stringstream ssTimer;
	if (currentlevel == 1)
	{

	}
	if (currentlevel == 1)
	{
		engine_timer = 300;// 0; *****HERE*****
	}
	else
	{
		engine_timer = 120;// 0; *****HERE*****
	}
	if (time_detected_enemy == true)
	{
		if (engine_timer >= 21)
		{
			
			engine_timer = engine_timer - (int)m_GameTimeTotal.asSeconds();
			ssTimer << "You have been detected "<<engine_timer;
			UITimer.setString(ssTimer.str());
			UITimer.setFillColor(Color::Yellow);
			m_Window.draw(UITimer);
		}
		else if (engine_timer <= 20 && engine_timer>=11)
		{
			
			engine_timer = engine_timer - (int)m_GameTimeTotal.asSeconds();
			ssTimer << "Time is up! " << engine_timer;
			UITimer.setString(ssTimer.str());
			UITimer.setFillColor(Color::Red);
			m_Window.draw(UITimer);

		}
		else if (engine_timer <= 10 && engine_timer>0)
		{
			
			engine_timer = engine_timer - m_GameTimeTotal.asSeconds();
			ssTimer << "Time is up! " << engine_timer;
			UITimer.setString(ssTimer.str());
			UITimer.setFillColor(Color::Red);
			m_Window.draw(UITimer);

		}
		else if(engine_timer <=0)
		{
			engine_timer = 0;
			m_Thomas.m_PlayerisDone = true;
			m_Bob.m_PlayerisDone = true;
		}
	}
	else
	{
		// Timing 	
		Clock clock1;
		Time reset = clock1.restart();
		m_GameTimeTotal = reset;
		ssTimer << "Undetected "<<engine_timer;
		UITimer.setString(ssTimer.str());
		UITimer.setFillColor(Color::Green);
		m_Window.draw(UITimer);
	}
	m_Window.draw(m_PortraitBobSprite);
	m_Window.draw(mPortraitThomasSprite);
	spriteClock.restart();
	// Show everything we have just drawn




	m_Window.display();
	
}

/*float_pointMap[atan(fabs(((((rayOBJ.rayFinal.ay) - (rayOBJ.rayFinal.ay)) / ((rayOBJ.rayFinal.ax + 1000) - (rayOBJ.rayFinal.ax)))
	- (((rayOBJ.rayFinal.by) - (rayOBJ.rayFinal.ay)) / ((rayOBJ.rayFinal.bx) - (rayOBJ.rayFinal.ax)))) /
	(1 + ((((rayOBJ.rayFinal.ay) - (rayOBJ.rayFinal.ay)) / ((rayOBJ.rayFinal.ax + 1000) - (rayOBJ.rayFinal.ax)))
		* (((rayOBJ.rayFinal.by) - (rayOBJ.rayFinal.ay)) / ((rayOBJ.rayFinal.bx) - (rayOBJ.rayFinal.ax))))))) *180/3.141592]
	= Vector2f(rayOBJ.Points[segmentNumber].x, rayOBJ.Points[segmentNumber].y);*/

	//= Vector2f(rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by);



//			p1	rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay           p2 	rayOBJ.rayFinal.ax + 1000, rayOBJ.rayFinal.ay
//			
//slope		((rayOBJ.rayFinal.ay) - (rayOBJ.rayFinal.ay)) / ((rayOBJ.rayFinal.ax + 1000) - (rayOBJ.rayFinal.ax))
//			
//			


			/*	atan(fabs	(((((rayOBJ.rayFinal.ay) - (rayOBJ.rayFinal.ay)) / ((rayOBJ.rayFinal.ax + 1000) - (rayOBJ.rayFinal.ax)))
							- (((rayOBJ.rayFinal.by) - (rayOBJ.rayFinal.ay)) / ((rayOBJ.rayFinal.bx) - (rayOBJ.rayFinal.ax)))) /
						(1 + ((((rayOBJ.rayFinal.ay) - (rayOBJ.rayFinal.ay)) / ((rayOBJ.rayFinal.ax + 1000) - (rayOBJ.rayFinal.ax)))
							* (((rayOBJ.rayFinal.by) - (rayOBJ.rayFinal.ay)) / ((rayOBJ.rayFinal.bx) - (rayOBJ.rayFinal.ax)))))));
*/


//			
//			
//			
//			p11	rayOBJ.rayFinal.ax, rayOBJ.rayFinal.ay           p21 	rayOBJ.rayFinal.bx, rayOBJ.rayFinal.by
//			
//slope		((rayOBJ.rayFinal.by) - (rayOBJ.rayFinal.ay)) / ((rayOBJ.rayFinal.bx) - (rayOBJ.rayFinal.ax))
