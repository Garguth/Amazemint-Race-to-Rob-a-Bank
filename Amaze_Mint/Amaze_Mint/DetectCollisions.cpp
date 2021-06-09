//#include "stdafx.h"
#include "Engine.h"
#include <list>

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal = false;
	// Make a rect for all his parts
	FloatRect detectionZone = character.getPosition();

	// Make a FloatRect to test each block
	FloatRect block;

	   
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Build a zone around thomas to detect collisions
	int startX = (int)(detectionZone.left / TILE_SIZE) - 50;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 50;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 80;

	// Thomas is quite tall so check a few tiles vertically
	int endY = (int)(detectionZone.top / TILE_SIZE) + 40;

	// Make sure we don't test positions lower than zero
	// Or higher than the end of the array
	if (startX < 0)startX = 0;
	if (startY < 0)startY = 0;
	if (endX >= m_LM.getLevelSize().x)
		endX = m_LM.getLevelSize().x;
	if (endY >= m_LM.getLevelSize().y)
		endY = m_LM.getLevelSize().y;

	// Has the character fallen out of the map?
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!This can be part of level manager!!!!!!!!!!!!!!!!!!!!!!!!
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);
	if (!character.getPosition().intersects(level))
	{
		// respawn the character
		character.spawn(m_LM.getStartPosition(), 0);
	}
	for (int i = 0; i < 4; i++)
	{
		if (moneyBills[i].getSprite().getGlobalBounds().intersects(m_Thomas.getSprite().getGlobalBounds()))
		{
			m_Thomas.money++;

			moneyBills[i].spawn((Vector2f(100000, 100000)), 0);
			//item1.spawn(Vector2f((rand() % 100)+100, (rand() % 100) + 100), 0);
			//detectCollisions(item1);
		}
		if (moneyBills[i].getSprite().getGlobalBounds().intersects(m_Bob.getSprite().getGlobalBounds()))
		{
			m_Bob.money++;

			moneyBills[i].spawn((Vector2f(100000, 100000)), 0);
			//item1.spawn(Vector2f((rand() % 100)+100, (rand() % 100) + 100), 0);
			//detectCollisions(item1);
		}
	}
	if (item1.getSprite().getGlobalBounds().intersects(m_Thomas.getSprite().getGlobalBounds()))
	{
		m_Thomas.money++;

		SpawnItem1(item1,50,2);
		//item1.spawn(Vector2f((rand() % 100)+100, (rand() % 100) + 100), 0);
		//detectCollisions(item1);
	}
	if (item1.getSprite().getGlobalBounds().intersects(m_Bob.getSprite().getGlobalBounds()))
	{
		m_Bob.money++;

		SpawnItem1(item1,50,2);
		//item1.spawn(Vector2f((rand() % 100)+100, (rand() % 100) + 100), 0);
		//detectCollisions(item1);
	}

	if (item2.getSprite().getGlobalBounds().intersects(m_Thomas.getSprite().getGlobalBounds()) && m_Thomas.m_hasScrewDriver == false)
	{
		m_Thomas.m_hasScrewDriver = true;
	//	SpawnItem1(item2, 50, 2);
		item2.spawn((Vector2f(100000, 100000)), 0);
	}
	if (item2.getSprite().getGlobalBounds().intersects(m_Bob.getSprite().getGlobalBounds())&& m_Bob.m_hasScrewDriver == false)
	{
		m_Bob.m_hasScrewDriver = true;
		//SpawnItem1(item2, 50, 2);
		item2.spawn((Vector2f(100000, 100000)), 0);

	}
	if (item3.getSprite().getGlobalBounds().intersects(m_Thomas.getSprite().getGlobalBounds()) && m_Thomas.m_hasScrewDriver == false)
	{
		m_Thomas.m_hasScrewDriver = true;
	//	SpawnItem1(item3, 50, 2);
		item3.spawn((Vector2f(100000, 100000)), 0);
	}
	if (item3.getSprite().getGlobalBounds().intersects(m_Bob.getSprite().getGlobalBounds()) && m_Bob.m_hasScrewDriver == false)
	{
		m_Bob.m_hasScrewDriver = true;
	//	SpawnItem1(item3, 50, 2);
		item3.spawn((Vector2f(100000, 100000)), 0);
	}
	if (item4.getSprite().getGlobalBounds().intersects(m_Thomas.getSprite().getGlobalBounds()) && m_Thomas.m_hasMasterKey == false)
	{
		m_Thomas.m_hasMasterKey = true;
		item4.spawn(Vector2f(16500, 40000), 0);
	}
	if (item4.getSprite().getGlobalBounds().intersects(m_Bob.getSprite().getGlobalBounds())&& m_Bob.m_hasMasterKey == false)
	{
		m_Bob.m_hasMasterKey = true;
		item4.spawn(Vector2f(16500, 40000), 0);
	}
	if (item5.getSprite().getGlobalBounds().intersects(m_Thomas.getSprite().getGlobalBounds()) && m_Thomas.m_hasMasterKey == false)
	{
		m_Thomas.m_hasMasterKey = true;
	//	SpawnItem1(item5, 2, 2);
		item5.spawn((Vector2f(100000, 100000)), 0);
	}
	if (item5.getSprite().getGlobalBounds().intersects(m_Bob.getSprite().getGlobalBounds()) && m_Bob.m_hasMasterKey == false)
	{
		m_Bob.m_hasMasterKey = true;
	//	SpawnItem1(item5, 2, 2);
		item5.spawn((Vector2f(100000, 100000)), 0);
	}
	for (int i = 0; i < amount; i++)
	{
		if (m_Enemy[i].getSprite().getGlobalBounds().intersects(m_Thomas.getSprite().getGlobalBounds()))
		{
			m_Thomas.spawn(m_LM.getStartPosition(), 0);
			m_Thomas.m_hasMasterKey = false;
			m_Thomas.m_hasScrewDriver = false;
			m_Thomas.health--;
			m_Thomas.money = 0;

			hit[i] = true;

			if (enState[0] != PATROL)
			{
				if (amount == 4)
				{
					m_Enemy[0].spawn(Vector2f(1650, 400), 0);
				}
				else if (amount == 1)
				{
					m_Enemy[0].spawn(Vector2f(1200, 1150), 0);
				}
				if (!pathListX[0].empty())
				{
					pathListX[0].clear();
					pathListY[0].clear();
					enState[0] = PATROL;
					delete[] Mark[0];
					Mark[0] = NULL;
				}
			}
			if (enState[1] != PATROL)
			{

				m_Enemy[1].spawn(Vector2f(450, 900), 0);
				if (!pathListX[1].empty())
				{
					pathListX[1].clear();
					pathListY[1].clear();
					enState[1] = PATROL;
					delete[] Mark[1];
					Mark[1] = NULL;
				}
			}
			if (enState[2] != PATROL)
			{
				m_Enemy[2].spawn(Vector2f(2250, 750), 0);
				if (!pathListX[2].empty())
				{
					pathListX[2].clear();
					pathListY[2].clear();
					enState[2] = PATROL;
					delete[] Mark[2];
					Mark[2] = NULL;
				}
			}
			if (enState[3] != PATROL)
			{
				m_Enemy[3].spawn(Vector2f(1400, 1250), 0);
				if (!pathListX[3].empty())
				{
					pathListX[3].clear();
					pathListY[3].clear();
					enState[3] = PATROL;
					delete[] Mark[3];
					Mark[3] = NULL;
				}
			}
		}
		if (m_Enemy[i].getSprite().getGlobalBounds().intersects(m_Bob.getSprite().getGlobalBounds()))
		{
			m_Bob.spawn(m_LM.getStartPosition(), 0);
			m_Bob.m_hasMasterKey = false;
			m_Bob.m_hasScrewDriver = false;
			m_Bob.health--;
			m_Bob.money = 0;

			hit[i] = true;

			if (enState[0] != PATROL)
			{
				if (amount == 4)
				{
					m_Enemy[0].spawn(Vector2f(1650, 400), 0);
				}
				else if (amount == 1)
				{
					m_Enemy[0].spawn(Vector2f(1200, 1150), 0);
				}
				if (!pathListX[0].empty())
				{
					pathListX[0].clear();
					pathListY[0].clear();
					enState[0] = PATROL;
					delete[] Mark[0];
					Mark[0] = NULL;
				}
			}
			if (enState[1] != PATROL)
			{
				m_Enemy[1].spawn(Vector2f(450, 900), 0);
				if (!pathListX[1].empty())
				{
					pathListX[1].clear();
					pathListY[1].clear();
					enState[1] = PATROL;
					delete[] Mark[1];
					Mark[1] = NULL;
				}
			}
			if (enState[2] != PATROL)
			{
				m_Enemy[2].spawn(Vector2f(2250, 750), 0);
				if (!pathListX[2].empty())
				{
					pathListX[2].clear();
					pathListY[2].clear();
					enState[2] = PATROL;
					delete[] Mark[2];
					Mark[2] = NULL;
				}
			}
			if (enState[3] != PATROL)
			{
				m_Enemy[3].spawn(Vector2f(1400, 1250), 0);
				if (!pathListX[3].empty())
				{
					pathListX[3].clear();
					pathListY[3].clear();
					enState[3] = PATROL;
					delete[] Mark[3];
					Mark[3] = NULL;
				}
			}
		}
	}
	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			// Initialize the starting position of the current block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			// Has character been burnt or drowned?
			// Use head as this allows him to sink a bit
			if (m_ArrayLevel[y][x] == 10)
			{
				if (character.getSprite().getGlobalBounds().intersects(block))// Fire, ouch!
				{
					if (character.m_InteractPressed == true && character.m_hasScrewDriver == true)
					{
						character.moneyget = 100;
						character.m_IsInteracting = true;
						//	character.m_hasScrewDriver = false;

					}
					if (character.timer == 299)
					{
						moneyBills[0].spawn((Vector2f(x * block.width, y * block.height)), 0);
						moneyBills[1].spawn((Vector2f(x * block.width + 50, y * block.height)), 0);
						moneyBills[2].spawn((Vector2f(x * block.width + 50, y * block.height - 50)), 0);
						moneyBills[3].spawn((Vector2f(x * block.width, y * block.height - 50)), 0);
					}
				}

			}

			if (m_ArrayLevel[y][x] == 4)
			{
			//	if (character.getHead().intersects(block))
				{
					//character(m_LM.getStartPosition(), 0);
					// Which sound should be played?
					if (character.getSprite().getGlobalBounds().intersects(block))// Fire, ouch!
					{
						if (character.m_hasMasterKey == true && character.m_InteractPressed == true)
						{
							if (currentlevel == 1)
							{
								character.moneyget = 20;
							}
							else if (currentlevel == 2)
							{
								character.moneyget = 100;
							}
							character.m_IsInteracting = true;
							character.m_hasMasterKey = false;
						//	character.money += 100;
						}
						// Play a sound
					//	if ((rand() % 20) == 1)
						{
						//	item1.spawn((Vector2f(x*block.width, y*block.height)), 0);
						}	
					}
					else // Water
					{
						// Play a sound
					}
				}
			}
			if (m_ArrayLevel[y][x] == 30)
			{
				//	if (character.getHead().intersects(block))
				{
					//character(m_LM.getStartPosition(), 0);
					// Which sound should be played?
					if (character.getSprite().getGlobalBounds().intersects(block))// Fire, ouch!
					{
						if ( character.m_InteractPressed == true)
						{
							character.moneyget = 5;
							character.m_IsInteracting = true;
							//	character.money += 100;
						}
						// Play a sound
					//	if ((rand() % 20) == 1)
						{
							//	item1.spawn((Vector2f(x*block.width, y*block.height)), 0);
						}
					}
					else // Water
					{
						// Play a sound
					}
				}
			}
			if (m_ArrayLevel[y][x] == 15)
			{
				//	if (character.getHead().intersects(block))
				{
					//character(m_LM.getStartPosition(), 0);
					// Which sound should be played?

					if (character.getSprite().getGlobalBounds().intersects(block))// Fire, ouch!
					{
									
						// Play a sound
					//	if ((rand() % 20) == 1)

						if(m_ArrayLevel[y + 1][x] == 13 || m_ArrayLevel[y - 1][x] == 13 || m_ArrayLevel[y][x + 1] == 13 || m_ArrayLevel[y][x - 1] == 13)
							{
							if (character.m_InteractPressed == true)
							{
								//character.money = 100;
								for (int i = 0; i < amount; i++)
								{
									if (round(m_Enemy[i].getPos().x / 50) - x < 10 &&
										round(m_Enemy[i].getPos().x / 50) - x > -10)
									{
										if (round(m_Enemy[i].getPos().y / 50) - y < 10 &&
											round(m_Enemy[i].getPos().y / 50) - y > -10)
										{
											delete[] Mark[i];
											Mark[i] = NULL;
											Mark[i] = new Sprite;
											Mark[i]->setTexture(m_QuestionMarkTexture);
											enState[i] = ALARM;
											goToX[i] = m_Enemy[i].getPos().x;
											goToY[i] = m_Enemy[i].getPos().y;
											pathListX[i].push_front(character.getPos().x);
											pathListY[i].push_front(character.getPos().y);

											//left
											if (m_Enemy[i].getPos().y < 1100)
											{
												if (pathListX[i].front() - 250 < 50 &&
													pathListX[i].front() - 250 > -50)
												{
													if (pathListY[i].front() - 1200 < 50 &&
														pathListY[i].front() - 1200 > -50)
													{
														pathListX[i].push_front(450);
														pathListY[i].push_front(1200);
														pathListX[i].push_front(450);
														pathListY[i].push_front(1000);
													}
												}
											}

											//bott
											if (m_Enemy[i].getPos().y > 1050)
											{
												if (pathListX[i].front() - 1550 < 50 &&
													pathListX[i].front() - 1550 > -50)
												{
													if (pathListY[i].front() - 1000 < 50 &&
														pathListY[i].front() - 1000 > -50)
													{

														pathListX[i].push_front(1400);
														pathListY[i].push_front(850);
														pathListX[i].push_front(1200);
														pathListY[i].push_front(850);

														pathListY[i].push_front(1000);
														pathListX[i].push_front(1100);
														pathListY[i].push_front(1200);
														pathListX[i].push_front(1100);
													
													}
												}
											}
											else 
											{
												if (pathListX[i].front() - 1550 < 50 &&
													pathListX[i].front() - 1550 > -50)
												{
													if (pathListY[i].front() - 1000 < 50 &&
														pathListY[i].front() - 1000 > -50)
													{
														if (m_Enemy[i].getPos().x < 1300)
														{
															pathListX[i].push_front(1400);
															pathListY[i].push_front(850);
															pathListX[i].push_front(1200);
															pathListY[i].push_front(850);
														}
													}
												}
											}
										}
									}
								}
							}
						}
						if (m_ArrayLevel[y + 1][x] == 16 || m_ArrayLevel[y - 1][x] == 16 || m_ArrayLevel[y][x + 1] == 16 || m_ArrayLevel[y][x - 1] == 16)

						{
							if (character.m_InteractPressed == true)
							{
						
								for (int i = 0; i < amount; i++)
								{
									if (round(m_Enemy[i].getPos().x / 50) - x < 18 &&
										round(m_Enemy[i].getPos().x / 50) - x > -18)
									{
										if (round(m_Enemy[i].getPos().y / 50) - y < 18 &&
											round(m_Enemy[i].getPos().y / 50) - y > -18)
										{
											delete[] Mark[i];
											Mark[i] = NULL;
											Mark[i] = new Sprite;
											Mark[i]->setTexture(m_QuestionMarkTexture);
											enState[i] = ALARM;
											goToX[i] = m_Enemy[i].getPos().x;
											goToY[i] = m_Enemy[i].getPos().y;
											pathListX[i].push_front(character.getPos().x);
											pathListY[i].push_front(character.getPos().y);
											
											//top
											if (m_Enemy[i].getPos().x < 700)
											{
												if (pathListX[i].front() - 450 < 50 &&
													pathListX[i].front() - 450 > -50)
												{
													if (pathListY[i].front() - 100 < 50 &&
														pathListY[i].front() - 100 > -50)
													{
														pathListX[i].push_front(950);
														pathListY[i].push_front(100);

														if (m_Enemy[i].getPos().y > 200)
														{
															pathListX[i].push_front(950);
															pathListY[i].push_front(250);

															if (m_Enemy[i].getPos().y > 800)
															{
																pathListX[i].push_front(800);
																pathListY[i].push_front(850);
																pathListX[i].push_front(600);
																pathListY[i].push_front(850);
															}
															else
															{
																pathListX[i].push_front(950);
																pathListY[i].push_front(450);
															}
														}

													}
												}
											}
											else
											{
												if (pathListX[i].front() - 450 < 50 &&
													pathListX[i].front() - 450 > -50)
												{
													if (pathListY[i].front() - 100 < 50 &&
														pathListY[i].front() - 100 > -50)
													{
														pathListX[i].push_front(950);
														pathListY[i].push_front(100);

														if (m_Enemy[i].getPos().y > 200)
														{
															pathListX[i].push_front(950);
															pathListY[i].push_front(250);
														}
													}
												}
											}


											//mid
											if (m_Enemy[i].getPos().x < 1950)
											{
												if (pathListX[i].front() - 1950 < 50 &&
													pathListX[i].front() - 1950 > -50)
												{
													if (pathListY[i].front() - 750 < 50 &&
														pathListY[i].front() - 750 > -50)
													{

														if (m_Enemy[i].getPos().y < 600 && m_Enemy[i].getPos().x > 1450)
														{
															pathListX[i].push_front(1450);
															pathListY[i].push_front(850);
															pathListX[i].push_front(1250);
															pathListY[i].push_front(850);

															pathListX[i].push_front(1200);
															pathListY[i].push_front(450);
															pathListX[i].push_front(1400);
															pathListY[i].push_front(450);
														}
														else if (m_Enemy[i].getPos().y < 1100)
														{
															if (m_Enemy[i].getPos().x < 1450)
															{
																pathListX[i].push_front(1450);
																pathListY[i].push_front(850);
																pathListX[i].push_front(1250);
																pathListY[i].push_front(850);
															}
														}
														else
														{
															
															pathListX[i].push_front(1450);
															pathListY[i].push_front(850);
															pathListX[i].push_front(1250);
															pathListY[i].push_front(850);
															
														
															pathListY[i].push_front(1000);
															pathListX[i].push_front(1100);
															pathListY[i].push_front(1200);
															pathListX[i].push_front(1100);
														}

													}
												}
											}
											else
											{
												if (pathListX[i].front() - 1950 < 50 &&
													pathListX[i].front() - 1950 > -50)
												{
													if (pathListY[i].front() - 750 < 50 &&
														pathListY[i].front() - 750 > -50)
													{
														pathListX[i].push_front(1450);
														pathListY[i].push_front(850);
														pathListX[i].push_front(1250);
														pathListY[i].push_front(850);


														pathListY[i].push_front(1000);
														pathListX[i].push_front(1100);
														pathListY[i].push_front(1200);
														pathListX[i].push_front(1100);
														pathListY[i].push_front(1400);
														pathListX[i].push_front(1800);
														
														pathListY[i].push_front(1400);
														pathListX[i].push_front(2250);

														if (m_Enemy[i].getPos().y < 1100)
														{
															pathListY[i].push_front(900);
															pathListX[i].push_front(2250);
														}
													}
												}
											}


										}
									}
								}
							}
						}
					}

				}
			}
			if (m_ArrayLevel[y][x] == 18 || m_ArrayLevel[y][x] == 19 || m_ArrayLevel[y][x] == 20 || m_ArrayLevel[y][x] == 21)
			{
				if (character.health > 0)
				{
					if (character.getSprite().getGlobalBounds().intersects(block))
					{
						character.m_PlayerisDone = true;
						character.TotalMoney += character.money;
						character.money = 0;
					}
					else
					{
						character.m_PlayerisDone = false;
					}
				}

			}
			// Is character colliding with a regular block

		
			if (m_ArrayLevel[y][x] == 1 || m_ArrayLevel[y][x] == 3 || (m_ArrayLevel[y][x] == 8 && character.m_hasScrewDriver == false) || m_ArrayLevel[y][x] == 13 || m_ArrayLevel[y][x] == 14 || m_ArrayLevel[y][x] == 16 || (m_ArrayLevel[y][x] == 33 && character.m_hasScrewDriver == false))
			{
				if (character.m_LeftPressed == true)
				{
					if (character.getSprite().getGlobalBounds().intersects(block))
					{
						character.disable_left = true;
						character.m_Position.x += 2.5;
					}
			
				}
				else
				{
					character.disable_left = false;
				}
				if (character.m_DownPressed == true)
				{
					if (character.getSprite().getGlobalBounds().intersects(block))
					{
						character.disable_down = true;
						character.m_Position.y += 2.5;
					}
	
				}
				else
				{
					character.disable_down = false;
				}
				if (character.m_RightPressed == true)
				{
					if (character.getSprite().getGlobalBounds().intersects(block))
					{
						character.disable_right = true;
						character.m_Position.x -= 2.5;
					}

				}
				else
				{
					character.disable_right = false;
				}
				if (character.m_UpPressed == true)
				{
					if (character.getSprite().getGlobalBounds().intersects(block))
					{
						character.disable_up = true;
						character.m_Position.y -= 2.5;
					}
				}
				else
				{
					character.disable_up = false;
				}

				//if (character.getSprite().getGlobalBounds().intersects(block))
				//{
				//	float blockcenx = block.left + block.width / 2; //cenx
				//	float blockceny = block.top + block.height / 2; //ceny
				//	float  CX = character.getCenter().x - 25;
				//	float  CY = character.getCenter().y - 25;

				//	float DistanceBlock = sqrt((blockcenx - CX) * (blockcenx - CX) + (blockceny - CY) * (blockceny - CY));

				//if ((blockcenx - CX) > (blockceny - CY) && block.height / 2 < blockceny + CY)
				//{
				//		character.m_Position.x += (blockcenx - CX + 50);
				//}

				//if ((blockceny - CY) > (blockcenx - CX) && block.height / 2 < blockceny - CY)
				//{
				//		character.m_Position.y += (blockceny - CY - 50);
				//}


				//if ((blockcenx - CX) > (blockceny - CY) && block.height / 2 < blockceny - CX)
				//{
				//	character.m_Position.x += (blockcenx - CX - 50);
				//}

				//if ((blockceny - CY) > (blockcenx - CX) && block.height / 2 < blockceny + CY)
				//{
				//	character.m_Position.y += (blockceny - CY + 50);
				//}
				//	
				//}


		
				for (int i = 0; i < amount; i++)
				{
					if (enState[i] == ALARM)
					{
						if (m_Enemy[i].getPos().x - goToX[i] < 1 &&
							m_Enemy[i].getPos().x - goToX[i] > -1)
						{
							if (m_Enemy[i].getPos().y - goToY[i] < 1 &&
								m_Enemy[i].getPos().y - goToY[i] > -1)
							{
								if (!pathListX[i].empty())
								{
									goToX[i] = pathListX[i].front();
									pathListX[i].pop_front();
								}
								if (!pathListY[i].empty())
								{
									goToY[i] = pathListY[i].front();
									pathListY[i].pop_front();
								}
							}
						}
						
						if (m_Enemy[i].handleInput1(goToX[i], goToY[i], enState[i]))
						{
							
						}

						//top
						if (m_Enemy[i].getPos().x - 450 < 50 &&
							m_Enemy[i].getPos().x - 450 > -50)
						{
							if (m_Enemy[i].getPos().y - 100 < 50 &&
								m_Enemy[i].getPos().y - 100 > -50)
							{
								while (!pathListX[i].empty())
								{
									pathListX[i].pop_front();
									pathListY[i].pop_front();
								}
								pathListX[i].push_front(-1);
								pathListY[i].push_front(-1);

								//top guy
								if (i == 0)
								{
									pathListX[i].push_front(2250);
									pathListY[i].push_front(450);
									pathListX[i].push_front(950);
									pathListY[i].push_front(250);
									pathListX[i].push_front(950);
									pathListY[i].push_front(100);
								}

								//left guy
								if (i == 1)
								{
									pathListX[i].push_front(600);
									pathListY[i].push_front(850);
									pathListX[i].push_front(800);
									pathListY[i].push_front(850);
									pathListX[i].push_front(950);
									pathListY[i].push_front(250);
									pathListX[i].push_front(950);
									pathListY[i].push_front(100);
								}

								//right guy
								if (i == 2)
								{
									pathListX[i].push_front(2300);
									pathListY[i].push_front(850);
									pathListX[i].push_front(2300);
									pathListY[i].push_front(50);
								}
								
								//bott guy
								if (i == 3)
								{
									pathListX[i].push_front(950);
									pathListY[i].push_front(1250);
									pathListX[i].push_front(950);
									pathListY[i].push_front(250);
									pathListX[i].push_front(950);
									pathListY[i].push_front(100);
								}

							}
						}

						
						//left
						if (m_Enemy[i].getPos().x - 250 < 50 &&
							m_Enemy[i].getPos().x - 250 > -50)
						{
							if (m_Enemy[i].getPos().y - 1200 < 50 &&
								m_Enemy[i].getPos().y - 1200 > -50)
							{
								while (!pathListX[i].empty())
								{
									pathListX[i].pop_front();
									pathListY[i].pop_front();
								}
								pathListX[i].push_front(-1);
								pathListY[i].push_front(-1);

								//top guy
								if (i == 0)
								{

									pathListX[i].push_front(1400);
									pathListY[i].push_front(450);
									pathListX[i].push_front(1200);
									pathListY[i].push_front(450);
									pathListX[i].push_front(1100);
									pathListY[i].push_front(850);

									pathListX[i].push_front(450);
									pathListY[i].push_front(850);
									pathListX[i].push_front(450);
									pathListY[i].push_front(1200);
								}

								//left guy
								if (i == 1)
								{
									pathListX[i].push_front(450);
									pathListY[i].push_front(1000);
									pathListX[i].push_front(450);
									pathListY[i].push_front(1200);
								}

								//right guy
								if (i == 2)
								{
									pathListY[i].push_front(600);
									pathListX[i].push_front(2250);
									pathListY[i].push_front(1400);
									pathListX[i].push_front(2250);
									pathListY[i].push_front(1300);
									pathListX[i].push_front(1100);
									pathListY[i].push_front(1000);
									pathListX[i].push_front(1100);
									pathListX[i].push_front(1100);
									pathListY[i].push_front(850);

									pathListX[i].push_front(450);
									pathListY[i].push_front(850);
									pathListX[i].push_front(450);
									pathListY[i].push_front(1200);
								}

								//bott guy
								if (i == 3)
								{
									pathListX[i].push_front(1100);
									pathListY[i].push_front(1300);
									pathListX[i].push_front(1100);
									pathListY[i].push_front(850);

									pathListX[i].push_front(450);
									pathListY[i].push_front(850);
									pathListX[i].push_front(450);
									pathListY[i].push_front(1200);
								}
							}
						}

						//midd
						if (m_Enemy[i].getPos().x - 1950 < 50 &&
							m_Enemy[i].getPos().x - 1950 > -50)
						{
							if (m_Enemy[i].getPos().y - 750 < 50 &&
								m_Enemy[i].getPos().y - 750 > -50)
							{
								while (!pathListX[i].empty())
								{
									pathListX[i].pop_front();
									pathListY[i].pop_front();
								}
								pathListX[i].push_front(-1);
								pathListY[i].push_front(-1);

								//top guy
								if (i == 0)
								{
									pathListX[i].push_front(1400);
									pathListY[i].push_front(450);
									pathListX[i].push_front(1200);
									pathListY[i].push_front(450);
									pathListX[i].push_front(1200);
									pathListY[i].push_front(850);
									pathListX[i].push_front(1400);
									pathListY[i].push_front(850);
								}

								//left guy
								if (i == 1)
								{
									pathListX[i].push_front(600);
									pathListY[i].push_front(850);
									pathListX[i].push_front(1400);
									pathListY[i].push_front(850);
								}

								//right guy
								if (i == 2)
								{
									pathListY[i].push_front(600);
									pathListX[i].push_front(2250);
									pathListY[i].push_front(1400);
									pathListX[i].push_front(2250);
									pathListY[i].push_front(1400);
									pathListX[i].push_front(1100);
									pathListY[i].push_front(1000);
									pathListX[i].push_front(1100);
									pathListX[i].push_front(1200);
									pathListY[i].push_front(850);
									pathListX[i].push_front(1400);
									pathListY[i].push_front(850);
								}

								//bott guy
								if (i == 3)
								{
									pathListY[i].push_front(1200);
									pathListX[i].push_front(1100);
									pathListY[i].push_front(1000);
									pathListX[i].push_front(1100);
									pathListX[i].push_front(1200);
									pathListY[i].push_front(850);
									pathListX[i].push_front(1400);
									pathListY[i].push_front(850);
								}

							}
						}


						//bott
						if (m_Enemy[i].getPos().x - 1550 < 50 &&
							m_Enemy[i].getPos().x - 1550 > -50)
						{
							if (m_Enemy[i].getPos().y - 950 < 50 &&
								m_Enemy[i].getPos().y - 950 > -50)
							{
								while (!pathListX[i].empty())
								{
									pathListX[i].pop_front();
									pathListY[i].pop_front();
								}
								pathListX[i].push_front(-1);
								pathListY[i].push_front(-1);

								//top guy
								if (i == 0)
								{
									pathListX[i].push_front(1400);
									pathListY[i].push_front(450);
									pathListX[i].push_front(1200);
									pathListY[i].push_front(450);
									pathListX[i].push_front(1200);
									pathListY[i].push_front(850);
									pathListX[i].push_front(1400);
									pathListY[i].push_front(850);
								}

								//left guy
								if (i == 1)
								{
									pathListX[i].push_front(600);
									pathListY[i].push_front(850);
									pathListX[i].push_front(1400);
									pathListY[i].push_front(850);
								}

								//right guy
								if (i == 2)
								{
									pathListY[i].push_front(600);
									pathListX[i].push_front(2250);
									pathListY[i].push_front(1400);
									pathListX[i].push_front(2250);
									pathListY[i].push_front(1400);
									pathListX[i].push_front(1100);
									pathListY[i].push_front(1000);
									pathListX[i].push_front(1100);
									pathListX[i].push_front(1200);
									pathListY[i].push_front(850);
									pathListX[i].push_front(1400);
									pathListY[i].push_front(850);
								}

								//bott guy
								if (i == 3)
								{
									pathListY[i].push_front(1200);
									pathListX[i].push_front(1100);
									pathListY[i].push_front(1000);
									pathListX[i].push_front(1100);
									pathListX[i].push_front(1200);
									pathListY[i].push_front(850);
									pathListX[i].push_front(1400);
									pathListY[i].push_front(850);
								}
							}
						}

						if (pathListX[i].front() == -1 && pathListY[i].front() == -1)
						{
							delete[] Mark[i];
							Mark[i] = NULL;

							enState[i] = PATROL;
							while (!pathListX[i].empty())
							{
								pathListX[i].pop_front();
								pathListY[i].pop_front();
							}
						}
						

					}
				}
				
				for (int i = 0; i < amount; i++)
				{
					if (enState[i] == CHASE)
					{
						if ((Keyboard::isKeyPressed(Keyboard::U)) &&
							!(m_Enemy[i].getSprite().getGlobalBounds().intersects(block)))
						{
							
							goToX[i] = m_Thomas.getPos().x;
							goToY[i] = m_Thomas.getPos().y;
							hit[i] = false;
						}

						if ((int)m_Enemy[i].getPos().x % 50 == 0 && !pathListX[i].empty())
						{
							if (pathListX[i].front() != (int)m_Enemy[i].getPos().x)
							{
								//if (pathListY[i].front() != (((int)(m_Enemy[i].getPos().y / 50)) * 50))
								{
									pathListX[i].push_front((int)m_Enemy[i].getPos().x);
									pathListY[i].push_front(round(m_Enemy[i].getPos().y / 50) * 50);
								}
							}
							
						}
						if ((int)m_Enemy[i].getPos().y % 50 == 0 && !pathListY[i].empty())
						{
							if (pathListY[i].front() != (int)m_Enemy[i].getPos().y)
							{
								//if (pathListX[i].front() != (((int)(m_Enemy[i].getPos().x / 50)) * 50))
								{
									pathListX[i].push_front(round(m_Enemy[i].getPos().x / 50) * 50);
									pathListY[i].push_front((int)m_Enemy[i].getPos().y);
								}
							}

						}

						if (pathListX[i].empty() && pathListY[i].empty())
						{
							pathListX[i].push_front((int)m_Enemy[i].getPos().x);
							pathListY[i].push_front((int)m_Enemy[i].getPos().y);
							spawnx[i] = (int)m_Enemy[i].getPos().x;
							spawny[i] = (int)m_Enemy[i].getPos().y;

						}


						if (m_Enemy[i].getSprite().getGlobalBounds().intersects(block))
						{

							if (goToX[i] > m_Enemy[i].getPos().x && !hit[i])//right
							{
								goToX[i] = (int)m_Enemy[i].getPos().x-1;

							}
							else if (goToX[i] <= m_Enemy[i].getPos().x && !hit[i])//left
							{
								goToX[i] = (int)m_Enemy[i].getPos().x+1;
							}

							if (goToY[i] > m_Enemy[i].getPos().y && !hit[i])//down
							{
								goToY[i] = (int)m_Enemy[i].getPos().y-1;
							}
							else if (goToY[i] <= m_Enemy[i].getPos().y && !hit[i])//up
							{
								goToY[i] = (int)m_Enemy[i].getPos().y+1;
							}

							hit[i] = true;
						}
						else
						{
//							if (!hit[i])
//							{
///*here*/						//goToX[i] = m_Thomas.getPos().x;
//								goToX[i] = rayOBJ.rayFinal.ax;
///*here*/						//goToY[i] = m_Thomas.getPos().y;
//								goToY[i] = rayOBJ.rayFinal.ay;
//							}
						}

						if (goToX != 0 && goToY != 0)
						{
							
							if (m_Enemy[i].handleInput1(goToX[i], goToY[i], enState[i]))
							{
								
							}
							else
							{
								
								/*if (!hit[i] && m_Enemy[i].getPos().x == goToX[i] && m_Enemy[i].getPos().y == goToY[i])
								{
									hit[i] = true;
								}*/
							}
							

						}
						if (hit[i])
						{
							if (!(pathListX[i].empty()) && !(pathListY[i].empty()))
							{
								if ((	m_Enemy[i].getPos().x - spawnx[i] < 1 &&
										m_Enemy[i].getPos().x - spawnx[i] > -1) && 
									(	m_Enemy[i].getPos().y - spawny[i] < 1 &&
										m_Enemy[i].getPos().y - spawny[i] > -1))
								{
									
									delete[] Mark[i];
									Mark[i] = NULL;
									enState[i] = PATROL;
								}
									if (!(pathListX[i].empty()))
									{
										
										goToX[i] = pathListX[i].front();
										
									}

									if (!(pathListY[i].empty()))
									{
										
										goToY[i] = pathListY[i].front();
										
									}

									
									if (m_Enemy[i].handleInput1(goToX[i], goToY[i], enState[i]))
									{

									}
									
									if ((m_Enemy[i].getPos().x - goToX[i] > -1 &&
										m_Enemy[i].getPos().x - goToX[i] < 1) &&
										(m_Enemy[i].getPos().y - goToY[i] > -1 &&
											m_Enemy[i].getPos().y - goToY[i] < 1))
									{
										if (!(pathListX[i].empty()))
										{
											pathListX[i].pop_front();
										}
										if (!(pathListY[i].empty()))
										{
											pathListY[i].pop_front();
										}
									}

							}

						}
							
						
					}
				}
		

				
				for (int i = 0; i < amount; i++)
				{
					if (enState[i] == PATROL)
					{
						if (check)
						{
							goToX[i] = m_Enemy[i].getPos().x;
							goToY[i] = m_Enemy[i].getPos().y;
						}
						if ((m_Enemy[i].getPos().x - goToX[i] < 5 && m_Enemy[i].getPos().x - goToX[i] > -5) &&
							m_Enemy[i].getPos().y - goToY[i] < 5 && m_Enemy[i].getPos().y - goToY[i] > -5)
						{
							xrand[0] = ((rand() % 500) + 1) - 250;
							yrand[0] = ((rand() % 250) + 1) - 150; //top

							xrand[1] = ((rand() % 400) + 1) - 200;
							yrand[1] = ((rand() % 200) + 1) - 100; //left

							xrand[2] = ((rand() % 100) + 1) - 50;
							yrand[2] = ((rand() % 800) + 1) - 450; //right

							xrand[3] = ((rand() % 1100) + 1) - 600;
							yrand[3] = ((rand() % 250) + 1) - 150; //bott


							//patrol spot
							
							if (amount == 4)
							{
								if (i == 0)
								{
									goToX[i] = 1650 + xrand[0];
									goToY[i] = 400 + yrand[0];
								}
								else if (i == 1)
								{
									goToX[i] = 450 + xrand[1];
									goToY[i] = 900 + yrand[1];
								}
								else if (i == 2)
								{
									goToX[i] = 2250 + xrand[2];
									goToY[i] = 650 + yrand[2];
								}
								else if (i == 3)
								{
									goToX[i] = 1400 + xrand[3];
									goToY[i] = 1300 + yrand[3];
								}
							}
							else if (amount == 1)
							{
								goToX[i] = 1200 + xrand[3];
								goToY[i] = 1150 + yrand[3];
							}
							
						}
						check = false;
						if (m_Enemy[i].getSprite().getGlobalBounds().intersects(block))
						{
					
							goToX[i] = m_Enemy[i].getPos().x;
							goToY[i] = m_Enemy[i].getPos().y;
						}

						
						if (m_Enemy[i].handleInput1(goToX[i], goToY[i], enState[i]))
						{

						}
						
					}
				}

				if (Keyboard::isKeyPressed(Keyboard::O))
				{

					for (int i = 0; i < amount; i++)
					{
						delete[] Mark[i];
						Mark[i] = NULL;
						Mark[i] = new Sprite;
						Mark[i]->setTexture(m_ExclamationTexture);
						pathListX[i].clear();
						pathListY[i].clear();
						enState[i] = CHASE;
					}
				}
				
			
							
				//if (m_Enemy[num].getPos().x - goToX < m_Enemy[num].getPos().y - goToY) right
				//if (m_Enemy[num].getPos().x - goToX > m_Enemy[num].getPos().y - goToY) up
				//if (goToX - m_Enemy[num].getPos().x > goToY - m_Enemy[num].getPos().y) down
				//if (goToX - m_Enemy[num].getPos().x < goToY - m_Enemy[num].getPos().y) up
				

			//	if (goToX != 0 && goToY != 0)
				{
			//		if (m_Enemy[num].handleInput1(goToX, goToY, enState[i]))
					{
				
					}

				}
					//if (character.getFeet().intersects(block))
					//{
					//	character.stopFalling(block.top);
					//}

			/*	if (m_ArrayLevel[y][x] == 1)
				{

					if (character.getRight().intersects(block))
					{
						character.stopRight(block.left);
					}
					else if (character.getLeft().intersects(block))
					{
						character.stopLeft(block.left);
					}


					if (character.getFeet().intersects(block))
					{
						character.stopFalling(block.top);
					}
					else if (character.getHead().intersects(block))
					{
						character.stopJump();
					}
				}*/
				//if ((character.getRight().intersects(block)))
				//{
				//	character.stopLeft(block.left);
			
				//}
				//
				//if ((character.getHead().intersects(block)))
				//{
				//	character.stopFalling(block.top);
				//}
				//
				//if ((character.getFeet().intersects(block)))
				//{
				//	character.stopUp(block.top);
				//}

				//if ((character.getLeft().intersects(block)))
				//{
				//	character.stopRight(block.left);
				//}

			}

			//character.money = 100;


			
			
							//if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
							//{
							//	m_Bob.stopFalling(m_Thomas.getHead().top);
							//}
							//else if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
							//{
							//	m_Thomas.stopFalling(m_Bob.getHead().top);
							//}
							//if(m_Bob.getSprite().getGlobalBounds().intersects(m_Thomas.getSprite().getGlobalBounds()))

			


			
			// More collision detection here once we have learned about particle effects

			// Has the character reached the goal?
			if (m_ArrayLevel[y][x] == 4)
			{
				// Character has reached the goal
				//reachedGoal = true;
			}

		}

	}

	// All done, return, wheteher or not a new level might be required
	return reachedGoal;
}