#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "Item.h"
#include "enemy.h"
#include "Rays.h"
#include "Point.h"
#include <map>

#include <list>
#include <vector>
#include<sstream>  
#include <iostream>
using namespace sf;

enum xboxButtons
{
	BUTTON_A = 0,
	BUTTON_B,
	BUTTON_X,
	BUTTON_Y,
	BUTTON_LEFTB,
	BUTTON_RIGHTB,
	BUTTON_BACK,
	BUTTON_START,
	BUTTON_LEFT_STICK_DOWN,
	BUTTON_RIGHT_STICK_DOWN,//10


	NUM_OF_BUTTONS

};

struct SortingPoint
{
	int x, y;
	float angleP;
};

class Engine
{
	Rays rayOBJ;
private:
	// The texture holder
	TextureHolder th;
	Text pausedText;
	Font font;
	Text UIMoneyThomas;
	Text UIMoneyBob;
	Text UIHasScrewThomas;
	Text UIHasCardThomas;
	Text UIHasScrewBob;
	Text UIHasCardBob;
	Text UITimer;
	// Thomas and his friend, Bob
	Thomas m_Thomas;
	Bob m_Bob;
	enemy m_Enemy[4];
	Item item1;
	Item item2;
	Item item3;
	Item item4;
	Item item5;

	Item moneyBills[4];
	// A class to manage all the levels
	LevelManager m_LM;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	int num = 0;
	bool stopy = false;
	bool stopx = false;
	bool time_detected_enemy = false;
	float engine_timer = 80;
	// The force pushing the characters down


	// A regular RenderWindow
	RenderWindow m_Window;
	RenderTexture rt1;
	RenderTexture rt2;
	RenderTexture rt3;

	// The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// Three views for the background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;
	View m_TextureView;
	View m_HudView;

	// Declare a sprite and a Texture for the background
	Sprite m_BackgroundSprite;
	Sprite m_BackgroundMainMenu;
	Sprite m_PauseMainMenu;
	Texture m_TutorialMenu1_Texture; // Add texture to these 2
	Texture m_BackgroundTexture;
	Sprite m_PortraitBobSprite;
	Sprite mPortraitThomasSprite;
	Texture m_PortraitBobTexture;
	Texture mPortraitThomasTexture;
	Texture m_BackgroundMainMenuTexture;
	Texture m_PauseMainMenuTexture;
	Sprite m_floorSprite;
	Texture m_floorTexture;
	Sprite m_EndScreenSprite;
	Texture m_EndScreenTexture;
	Texture m_ExclamationTexture;
	Texture m_QuestionMarkTexture;
	Texture m_blackBGTexture;
	// Timing 	
	Clock spriteClock;
	// Is the game currently playing?
	bool m_Playing = false;

	// Is character 1 or 2 the current focus?
	bool m_Character1 = true;
	bool tutorial_done = false;
	// Start in full screen mode
	bool m_SplitScreen = false;

	// How much time is left in the current level

	Time m_GameTimeTotal;

	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	// The vertex array for the level design
	VertexArray m_VALevel;

	// The 2d array with the map for the level
	// A pointer to a pointer
	int** m_ArrayLevel = NULL;

	Sprite* Mark[4];
	// Texture for the background and the level tiles
	Texture m_TextureTiles;
	void yar();
	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();
	void SpawnItem1(Item &m_item, int chance, int loc);
	// Load a new level
	void loadLevel(int currentLevel);

	// Run will call all the private functions
	bool detectCollisions(PlayableCharacter& character);

public:
	void endScreen();
	void centerPoint();
	// The Engine constructor
	Engine();
	void clearMemory();
	void titleScreen();
	void pauseScreen();
	void titleScreen2();
	void titleScreen3();
	void titleScreen4();

	// Run will call all the private functions
	void run(int clevel);
	bool mamaCocoIsAlive = false;
	bool paused = false;
	int goToX[4] = { 0,0,0,0 };
	int goToY[4] = { 0,0,0,0 };
	int cornerCount;
	int currentlevel =0;
	map <float, Vector2f> float_pointMap;
	map<float, Vector2f> ::iterator it;

	int jay = 0;
	int amount;

	struct corner
	{
		float x;
		float y;
	};
	
	int enState[4] = { PATROL,PATROL,PATROL,PATROL };
	int xrand[4], yrand[4];
	bool check = true;
	bool hit[4] = { false,false,false,false };
	list<int> pathListX[4];
	list<int> pathListY[4];
	int spawnx[4];
	int spawny[4];

	//SortingPoints

	// A global point needed for  sorting points with reference 
	// to the first point. Used in compare function of qsort() 
//	SortingPoint p0;

	// A utility function to swap two points 
	//void swap(SortingPoint& p1, SortingPoint& p2);

	// A utility function to return square of distance between 
	// p1 and p2 
	//int dist(SortingPoint p1, SortingPoint p2);

	// To find orientation of ordered triplet (p, q, r). 
	// The function returns following values 
	// 0 --> p, q and r are colinear 
	// 1 --> Clockwise 
	// 2 --> Counterclockwise 
//	int orientation(SortingPoint p, SortingPoint q, SortingPoint r);

	// A function used by library function qsort() to sort 
	// an array of points with respect to the first point 
	//int compare(const void* vp1, const void* vp2);

	// Prints simple closed path for a set of n points. 
	void printClosedPath(SortingPoint points[], int n);


	vector<corner> corners;
	void InitializeWalls();
	void init();
};
