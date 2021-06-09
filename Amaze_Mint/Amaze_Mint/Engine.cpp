//#include "stdafx.h"
#include "Engine.h"


Engine::Engine()
{
	
		item1.setSprite(1);
		item2.setSprite(3);
		item3.setSprite(3);
		item4.setSprite(2);
		item5.setSprite(2);
		for (int i = 0; i < 4; i++)
		{
			moneyBills[i].setSprite(1);
		}
		// Get the screen resolution and create an SFML window and View
		Vector2f resolution;
		resolution.x = VideoMode::getDesktopMode().width;
		resolution.y = VideoMode::getDesktopMode().height;

		m_Window.create(VideoMode(resolution.x, resolution.y),
			"Thomas was late",
			Style::Fullscreen);
		// Initialize the full screen view
		m_MainView.setSize(resolution);

		// Two lines below used to create zoomed our screenshots for the book
		//m_BGMainView.zoom(2.5);
		//m_MainView.zoom(2.5);
		m_HudView.reset(
			FloatRect(0, 0, resolution.x, resolution.y));
		if (!rt1.create(resolution.x, resolution.y))
		{
			// error...
		}
		if (!rt2.create(resolution.x, resolution.y))
		{
			// error...
		}
		if (!rt3.create(resolution.x, resolution.y))
		{
			// error...
		}
		// Inititialize the split-screen Views
		m_LeftView.setViewport(
			FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

		m_RightView.setViewport(
			FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

		m_BGLeftView.setViewport(
			FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

		m_BGRightView.setViewport(
			FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

		// Can this graphics card use shaders?
		if (!sf::Shader::isAvailable())
		{
			// Time to get a new PC
			m_Window.close();
		}
		//                                                                                              Fonts
		font.loadFromFile("fonts/slkscr.ttf");

		pausedText.setFont(font);
		pausedText.setCharacterSize(85);
		pausedText.setFillColor(Color::Black);
		pausedText.setPosition(540, 780);
		if (Joystick::isConnected(0))
		{
			pausedText.setString("   Press a \nto continue");
		}
		else
		{
			pausedText.setString("   Press H \nto continue");
		}



		UIMoneyThomas.setFont(font);
		UIMoneyThomas.setCharacterSize(25);
		UIMoneyThomas.setFillColor(Color(51, 171, 249));
		UIMoneyThomas.setPosition(50, 1025);


		UIMoneyBob.setFont(font);
		UIMoneyBob.setCharacterSize(25);
		UIMoneyBob.setFillColor(Color(255, 83, 0));
		UIMoneyBob.setPosition(950, 1025);

		UIHasScrewThomas.setFont(font);
		UIHasScrewThomas.setCharacterSize(25);
		UIHasScrewThomas.setFillColor(Color(51, 171, 249));
		UIHasScrewThomas.setPosition(350, 1025);

		UIHasCardBob.setFont(font);
		UIHasCardBob.setCharacterSize(25);
		UIHasCardBob.setFillColor(Color(255, 83, 0));
		UIHasCardBob.setPosition(1250, 1025);

		UITimer.setFont(font);
		UITimer.setCharacterSize(25);
		UITimer.setFillColor(Color::Black);
		UITimer.setPosition(0, 0);
		m_EndScreenTexture = TextureHolder::GetTexture("graphics/endScreen.png");
		m_EndScreenSprite.setTexture(m_EndScreenTexture);

		m_BackgroundTexture = TextureHolder::GetTexture(
			"graphics/background.png");
		m_BackgroundMainMenuTexture = TextureHolder::GetTexture("graphics/titleScreen2.png");
		m_TutorialMenu1_Texture = TextureHolder::GetTexture("graphics/Tutorial.png");
		m_PauseMainMenuTexture = TextureHolder::GetTexture("graphics/pauseScreen.jpg");
		m_floorTexture = TextureHolder::GetTexture("graphics/floorTile.png");
		// Associate the sprite with the texture
		m_BackgroundSprite.setTexture(m_BackgroundTexture);
		m_floorSprite.setTexture(m_floorTexture);
		m_BackgroundMainMenu.setTexture(m_BackgroundMainMenuTexture);
		m_PauseMainMenu.setTexture(m_PauseMainMenuTexture);
		// Load the texture for the background vertex array
		m_TextureTiles = TextureHolder::GetTexture(
			"graphics/tiles_sheet2.png");

		mPortraitThomasTexture = TextureHolder::GetTexture(
			"graphics/portrait1.png");
		mPortraitThomasSprite.setTexture(mPortraitThomasTexture);
		mPortraitThomasSprite.setPosition(-10, 1000);

		m_PortraitBobTexture = TextureHolder::GetTexture(
			"graphics/portrait2.png");
		m_ExclamationTexture = TextureHolder::GetTexture(
			"graphics/exclamationmark.png");
		m_QuestionMarkTexture = TextureHolder::GetTexture("graphics/questionmark.png");
		m_blackBGTexture = TextureHolder::GetTexture("graphics/light.png");
		m_PortraitBobSprite.setTexture(m_PortraitBobTexture);
		m_PortraitBobSprite.setPosition(1635, 1000);

		//rt1.setView(m_MainView);
		m_MainView.move(700, 250);
		m_TextureView = m_MainView;
		//m_TextureView.move(25,25);
		m_MainView.zoom(1.4f);
		m_TextureView.zoom(1.4f);
		//m_TextureView.move(0, 5);
		rt2.setView(m_TextureView);
		rt3.setView(m_TextureView);

	
}
void Engine::titleScreen()
{
	m_BackgroundMainMenu.setTexture(m_BackgroundMainMenuTexture);
	while (mamaCocoIsAlive == false)
	{
		
		m_Window.draw(m_BackgroundMainMenu);
		m_Window.draw(pausedText);
		m_Window.display();
		input();
	}
	mamaCocoIsAlive = false;
	m_BackgroundMainMenu.setTexture(m_TutorialMenu1_Texture);
	while (mamaCocoIsAlive == false)
	{
		m_Window.draw(m_BackgroundMainMenu);
		m_Window.draw(pausedText);
		m_Window.display();
		input();
	}
	mamaCocoIsAlive = false;
	m_TutorialMenu1_Texture = TextureHolder::GetTexture("graphics/Tutorial_2.png");
	m_BackgroundMainMenu.setTexture(m_TutorialMenu1_Texture);
	while (mamaCocoIsAlive == false)
	{
		m_Window.draw(m_BackgroundMainMenu);
		m_Window.draw(pausedText);
		m_Window.display();
		input();
	}
	mamaCocoIsAlive = false;
	m_TutorialMenu1_Texture = TextureHolder::GetTexture("graphics/Tutorial_3.png");
	m_BackgroundMainMenu.setTexture(m_TutorialMenu1_Texture);
	while (mamaCocoIsAlive == false)
	{
		m_Window.draw(m_BackgroundMainMenu);
		m_Window.draw(pausedText);
		m_Window.display();
		input();
	}
}
void Engine::titleScreen2()
{
	mamaCocoIsAlive = false;
	m_TutorialMenu1_Texture = TextureHolder::GetTexture("graphics/Tutorial_4.png");
	m_BackgroundMainMenu.setTexture(m_TutorialMenu1_Texture);
	while (mamaCocoIsAlive == false)
	{
		m_Window.draw(m_BackgroundMainMenu);
		m_Window.draw(pausedText);
		m_Window.display();
		input();
	}
}
void Engine::titleScreen3()
{
	mamaCocoIsAlive = false;
	m_TutorialMenu1_Texture = TextureHolder::GetTexture("graphics/Tutorial_5.png");
	m_BackgroundMainMenu.setTexture(m_TutorialMenu1_Texture);
	while (mamaCocoIsAlive == false)
	{
		m_Window.draw(m_BackgroundMainMenu);
		m_Window.draw(pausedText);
		m_Window.display();
		input();
	}
}
void Engine::titleScreen4()
{
	mamaCocoIsAlive = false;
	m_TutorialMenu1_Texture = TextureHolder::GetTexture("graphics/Tutorial_6.png");
	m_BackgroundMainMenu.setTexture(m_TutorialMenu1_Texture);
	while (mamaCocoIsAlive == false)
	{
		m_Window.draw(m_BackgroundMainMenu);
		m_Window.draw(pausedText);
		m_Window.display();
		input();
	}
}
void Engine::pauseScreen()
{
	while (paused)
	{
		m_Window.draw(m_PauseMainMenu);
		//m_Window.draw(pausedText);
		m_Window.display();
		input();
	}

}

void Engine::endScreen()
{
	m_Window.clear();
	UIMoneyThomas.setCharacterSize(40);
	UIMoneyThomas.setPosition(50, 925);
	UIMoneyBob.setCharacterSize(40);
	UIMoneyBob.setPosition(950, 925);
	stringstream ssMoneyThomas;
	ssMoneyThomas << "Thomas Total Money: " << m_Thomas.TotalMoney;

	UIMoneyThomas.setString(ssMoneyThomas.str());

	
	stringstream ssMoneyBob;
	
	ssMoneyBob << "Bob Total Money: " << m_Bob.TotalMoney;

	UIMoneyBob.setString(ssMoneyBob.str());
	m_Window.draw(UIMoneyBob);
	m_Window.draw(m_EndScreenSprite);
	m_Window.draw(UIMoneyThomas);
	m_Window.draw(UIMoneyBob);
	m_Window.display();
	input();

}


void Engine::run(int clevel)
{
	// Timing 	
	Clock clock;
	currentlevel = clevel;
	m_Thomas.m_PlayerisDone = false;
	m_Bob.m_PlayerisDone = false;
	loadLevel(currentlevel);
	titleScreen2();

	while (m_Window.isOpen())
	{
		
		while ((m_Thomas.m_PlayerisDone == false || m_Bob.m_PlayerisDone == false))
		{
			
			if (Joystick::isConnected(0))
			{
				
			}


			/*if (Joystick::isButtonPressed(0, BUTTON_B))
			{
				cout << " YOU PRESSED B" << endl;
			}*/

			Time dt = clock.restart();
			// Update the total game time
			m_GameTimeTotal += dt;
			// Make a decimal fraction from the delta time
			float dtAsSeconds = dt.asSeconds();
			input();
			update(dtAsSeconds);
			draw();
			if (m_Thomas.TotalMoney > 0 || m_Bob.TotalMoney > 0)
			{
				tutorial_done = true;
			}
		}
		if (tutorial_done == false)
		{
			titleScreen3();
			m_Thomas.m_PlayerisDone = false;
			m_Bob.m_PlayerisDone = false;
			m_Bob.health = 3;
			m_Thomas.health = 3;
			m_Bob.m_hasScrewDriver = true;
			m_Thomas.m_hasScrewDriver = true;
			time_detected_enemy = false;
			loadLevel(currentlevel);
		}
		if (currentlevel == 1 && tutorial_done == true)
		{
			
			titleScreen4();
			currentlevel = clevel + 1;
			m_Thomas.m_PlayerisDone = false;
			m_Bob.m_PlayerisDone = false;
			time_detected_enemy = false;
			loadLevel(currentlevel);
		}
		while ((m_Thomas.m_PlayerisDone == false || m_Bob.m_PlayerisDone == false) && tutorial_done == true)
		{


			if (Joystick::isConnected(0))
			{

			}


			/*if (Joystick::isButtonPressed(0, BUTTON_B))
			{
				cout << " YOU PRESSED B" << endl;
			}*/

			Time dt = clock.restart();
			// Update the total game time
			m_GameTimeTotal += dt;
			// Make a decimal fraction from the delta time
			float dtAsSeconds = dt.asSeconds();
			input();
			update(dtAsSeconds);
			draw();
		}
		if (tutorial_done == true)
		{
			endScreen();
		}
		
	}
}

void Engine::SpawnItem1(Item &m_item, int chance, int loc)
{
	for (int x = 0; x < m_LM.getLevelSize().x; x++)
	{
		for (int y = 0; y < m_LM.getLevelSize().y; y++)
		{
			// Has character been burnt or drowned?
			// Use head as this allows him to sink a bit
				if ((rand() % chance) == 1)
				{
					if (m_ArrayLevel[y][x] == loc)// Fire, ouch!
					{
						// Play a sound

						m_item.spawn((Vector2f(x * 50, y * 50)), 0);

					}
				}
				else // Water
				{
					// Play a sound
				}
		}
	}
	
}
void Engine::centerPoint()
{
	cornerCount = 0;
	yar();
	for (int x = 0; x < m_LM.getLevelSize().x; x++)
	{
		for (int y = 0; y < m_LM.getLevelSize().y; y++)
		{
			if (x == 0)
			{
				if (m_ArrayLevel[y][x] == 1)
				{
					if (m_ArrayLevel[y][x+1] == 1)
					{
						corners[cornerCount].x = x * 50 +50 ;
						corners[cornerCount].y = y * 50 ;
						cornerCount++;
						corners[cornerCount].x = x * 50 + 50;
						corners[cornerCount].y = y * 50 + 50;
						cornerCount++;
					}
				}
			}
			if (x == m_LM.getLevelSize().x-1)
			{
				if (m_ArrayLevel[y][x] == 1)
				{
					if (m_ArrayLevel[y][x-1] == 1)
					{
						corners[cornerCount].x = x * 50;
						corners[cornerCount].y = y * 50;
						cornerCount++;
						corners[cornerCount].x = x * 50;
						corners[cornerCount].y = y * 50+50;
						cornerCount++;
					}
				}
			}
			if (y == 0)
			{
				if (m_ArrayLevel[y][x] == 1)
				{
					if (m_ArrayLevel[y+1][x] == 1)
					{
						corners[cornerCount].x = x * 50;
						corners[cornerCount].y = y * 50+50;
						cornerCount++;
						corners[cornerCount].x = x * 50 + 50;
						corners[cornerCount].y = y * 50 + 50;
						cornerCount++;
					}
				}
			}
			if (y == m_LM.getLevelSize().y-1)
			{
				if (m_ArrayLevel[y][x] == 1)
				{
					if (m_ArrayLevel[y - 1][x] == 1)
					{
						corners[cornerCount].x = x * 50;
						corners[cornerCount].y = y * 50;
						cornerCount++;
						corners[cornerCount].x = x * 50+50;
						corners[cornerCount].y = y * 50;
						cornerCount++;
					}
				}
			}
			if (x > 0 && y > 0 && x < m_LM.getLevelSize().x - 1 && y < m_LM.getLevelSize().y - 1)
			{
				if (m_ArrayLevel[y][x] == 1)
				{
					if (m_ArrayLevel[y + 1][x] == 1 || m_ArrayLevel[y - 1][x] == 1 || m_ArrayLevel[y][x + 1] == 1 || m_ArrayLevel[y][x - 1] == 1)
					{
						if ((m_ArrayLevel[y + 1][x] == 1 && m_ArrayLevel[y - 1][x] == 1) && ((m_ArrayLevel[y][x + 1] == 1) || (m_ArrayLevel[y][x - 1] == 1)))
						{
							if (m_ArrayLevel[y][x + 1] == 1)
							{
								corners[cornerCount].x = x * 50 + 50;
								corners[cornerCount].y = y * 50 - 0;
								cornerCount++;
								corners[cornerCount].x = x * 50 + 50;
								corners[cornerCount].y = y * 50 + 50;
								cornerCount++;
							}
							else if (m_ArrayLevel[y][x - 1] == 1)
							{
								;
								corners[cornerCount].x = (x * 50 - 0);
								corners[cornerCount].y = (y * 50 - 0);

								cornerCount++;
								corners[cornerCount].x = x * 50;
								corners[cornerCount].y = y * 50 + 50;
								cornerCount++;
							}
						}
						if ((m_ArrayLevel[y + 1][x] == 1 || m_ArrayLevel[y - 1][x] == 1) && ((m_ArrayLevel[y][x + 1] == 1) && (m_ArrayLevel[y][x - 1] == 1)))
						{
							if (m_ArrayLevel[y + 1][x] == 1)
							{
								corners[cornerCount].x = (x * 50 - 0);
								corners[cornerCount].y = (y * 50 + 50);
								cornerCount++;
								corners[cornerCount].x = (x * 50 + 50);
								corners[cornerCount].y = (y * 50 + 50);
								cornerCount++;
							}
							else if (m_ArrayLevel[y - 1][x] == 1)
							{

								corners[cornerCount].x = (x * 50 - 0);
								corners[cornerCount].y = (y * 50 - 0);

								cornerCount++;

								corners[cornerCount].x = (x * 50 + 50);
								corners[cornerCount].y = (y * 50 - 0);

								cornerCount++;
							}
						}
						if (m_ArrayLevel[y + 1][x] == 1 && m_ArrayLevel[y - 1][x] != 1 && m_ArrayLevel[y][x + 1] != 1 && m_ArrayLevel[y][x - 1] != 1)
						{

							corners[cornerCount].x = (x * 50 - 0);
							corners[cornerCount].y = (y * 50 + 0);

							cornerCount++;

							corners[cornerCount].x = (x * 50 + 50);
							corners[cornerCount].y = (y * 50 + 0);

							cornerCount++;

						}
						if (m_ArrayLevel[y + 1][x] != 1 && m_ArrayLevel[y - 1][x] == 1 && m_ArrayLevel[y][x + 1] != 1 && m_ArrayLevel[y][x - 1] != 1)
						{

							corners[cornerCount].y = (y * 50 + 50);
							corners[cornerCount].x = (x * 50 - 0);

							cornerCount++;

							corners[cornerCount].y = (y * 50 + 50);
							corners[cornerCount].x = (x * 50 + 50);

							cornerCount++;
						}
						if (m_ArrayLevel[y + 1][x] != 1 && m_ArrayLevel[y - 1][x] != 1 && m_ArrayLevel[y][x + 1] == 1 && m_ArrayLevel[y][x - 1] != 1)
						{

							corners[cornerCount].y = (y * 50 + 0);
							corners[cornerCount].x = (x * 50 + 0);

							cornerCount++;

							corners[cornerCount].y = (y * 50 + 50);
							corners[cornerCount].x = (x * 50 + 0);

							cornerCount++;
						}
						if (m_ArrayLevel[y + 1][x] != 1 && m_ArrayLevel[y - 1][x] != 1 && m_ArrayLevel[y][x + 1] != 1 && m_ArrayLevel[y][x - 1] == 1)
						{

							corners[cornerCount].y = (y * 50 + 0);
							corners[cornerCount].x = (x * 50 + 50);

							cornerCount++;

							corners[cornerCount].y = (y * 50 + 50);
							corners[cornerCount].x = (x * 50 + 50);

							cornerCount++;
						}
						if ((m_ArrayLevel[y + 1][x] == 1 || m_ArrayLevel[y - 1][x] == 1) && (m_ArrayLevel[y][x + 1] == 1 || m_ArrayLevel[y][x - 1] == 1))
						{
							if (m_ArrayLevel[y + 1][x] == 1 && m_ArrayLevel[y][x + 1] == 1)
							{
								corners[cornerCount].y = (y * 50 + 50);
								corners[cornerCount].x = (x * 50 + 50);

								cornerCount++;

								corners[cornerCount].y = (y * 50);
								corners[cornerCount].x = (x * 50);

								cornerCount++;
							}
							if (m_ArrayLevel[y - 1][x] == 1 && m_ArrayLevel[y][x + 1] == 1)
							{
								corners[cornerCount].y = (y * 50 - 0);
								corners[cornerCount].x = (x * 50 + 50);

								cornerCount++;

								corners[cornerCount].y = (y * 50 + 50);
								corners[cornerCount].x = (x * 50);

								cornerCount++;
							}
							if (m_ArrayLevel[y + 1][x] == 1 && m_ArrayLevel[y][x - 1] == 1)
							{
								corners[cornerCount].y = (y * 50 + 50);
								corners[cornerCount].x = (x * 50 - 0);

								cornerCount++;
								corners[cornerCount].y = (y * 50);
								corners[cornerCount].x = (x * 50 + 50);

								cornerCount++;
							}
							if (m_ArrayLevel[y - 1][x] == 1 && m_ArrayLevel[y][x - 1] == 1)
							{
								corners[cornerCount].y = (y * 50 - 0);
								corners[cornerCount].x = (x * 50 - 0);

								cornerCount++;
								corners[cornerCount].y = (y * 50 + 50);
								corners[cornerCount].x = (x * 50 + 50);

								cornerCount++;
							}
						}
					}
				}
			}
		}
	}
}

void  Engine::clearMemory()
{
	for (int i = 0; i < corners.size(); i++)
	{
//		delete[] corners.back();
		corners.pop_back();
	}
}

void Engine::yar()
{
int newSize = (m_LM.getLevelSize().x);
	int newSizes = (m_LM.getLevelSize().y);
	vector<corner> newCorners{ 832,corner()};
	corners = newCorners;
}

//
//// A utility function to swap two points 
//void  Engine::swap(SortingPoint& p1, SortingPoint& p2)
//{
//	SortingPoint temp = p1;
//	p1 = p2;
//	p2 = temp;
//}
//
//// A utility function to return square of distance between 
//// p1 and p2 
//int  Engine::dist(SortingPoint p1, SortingPoint p2)
//{
//	return (p1.x - p2.x) * (p1.x - p2.x) +
//		(p1.y - p2.y) * (p1.y - p2.y);
//}
//
//// To find orientation of ordered triplet (p, q, r). 
//// The function returns following values 
//// 0 --> p, q and r are colinear 
//// 1 --> Clockwise 
//// 2 --> Counterclockwise 
//int  Engine::orientation(SortingPoint p, SortingPoint q, SortingPoint r)
//{
//	int val = (q.y - p.y) * (r.x - q.x) -
//		(q.x - p.x) * (r.y - q.y);
//
//	if (val == 0) return 0;  // colinear 
//	return (val > 0) ? 1 : 2; // clockwise or counterclock wise 
//}

//// A function used by library function qsort() to sort 
////  an array of points with respect to the first point 
//int  Engine::compare(const void* vp1, const void* vp2)
//{
//	SortingPoint* p1 = (SortingPoint*)vp1;
//	SortingPoint* p2 = (SortingPoint*)vp2;
//
//	// Find orientation 
//	int o = orientation(p0, *p1, *p2);
//	if (o == 0)
//		return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;
//
//	return (o == 2) ? -1 : 1;
//}
//
//// Prints simple closed path for a set of n points. 
//void  Engine::printClosedPath(SortingPoint points[], int n, Vector2f coords, Engine &e)
//{
//	// Find the bottommost point 
//	//int ymin = points[0].y, min = 0;
//	//for (int i = 1; i < n; i++)
//	//{
//	//	int y = points[i].y;
//
//	//	// Pick the bottom-most. In case of tie, chose the 
//	//	// left most point 
//	//	if ((y < ymin) || (ymin == y &&
//	//		points[i].x < points[min].x))
//	//		ymin = points[i].y, min = i;
//	//}
//
//	SortingPoint spawn;
//	spawn.x = coords.x;
//	spawn.y = coords.y;
//
//	// Place the bottom-most point at first position 
//	swap(points[0], spawn);//points[min]);
//
//	// Sort n-1 points with respect to the first point. 
//	// A point p1 comes before p2 in sorted ouput if p2 
//	// has larger polar angle (in counterclockwise 
//	// direction) than p1 
//	p0 = points[0];
//	qsort(&points[1], n - 1, sizeof(SortingPoint), e.compare());
//	
//
//	// Now stack has the output points, print contents 
//	// of stack 
//	for (int i = 0; i < n; i++)
//		cout << "(" << points[i].x;// << ", "
//		//<< points[i].y << "), ";
//}
