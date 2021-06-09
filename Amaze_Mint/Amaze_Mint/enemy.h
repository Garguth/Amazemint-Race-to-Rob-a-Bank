#pragma once
#include "Thomas.h"
using namespace sf;


enum enemyState
{
	PATROL = 0,
	CHASE,
	ALARM,

	NUM_OF_STATES
};

enum enemyLook
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,

	NUM_OF_LOOKS
};

class enemy
{
public:
	// A constructor specific to Bob
	enemy();
	Sprite m_Sprite;
	bool handleInput1(int _x, int _y, int _state);
private:protected:
	// Of course we will need a sprite
	
	

	// How long does a jump last
	float m_JumpDuration;
	float timer;
	// Is character currently jumping or falling
	bool m_IsJumping;
	bool m_IsFalling;

	// Which directions is the character currently moving in
	bool m_LeftPressed;
	bool m_RightPressed;
	bool m_UpPressed;
	bool m_DownPressed;
	// How long has this jump lasted so far
	float m_TimeThisJump;

	// Has the player just initialted a jump
	bool m_JustJumped = false;

	// Private variables and functions come next
private:
	// What is the gravity
	float m_Gravity;

	// How fast is the character
	float m_Speed = 150;

	// Where is the player
	Vector2f m_Position;

	// Where are the characters various body parts?
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	// And a texture
	Texture m_Texture;

	// All our public functions will come next
public:

	bool hitting[4];

	int directionLooking;

	void spawn(Vector2f startPosition, float gravity);

	// This class is now abstract and cannot be instanciated

	// Where is the player
	FloatRect getPosition();

	// A rectangle representing the position of different parts of the sprite
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// Make the character stand firm
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopUp(float position);
	void stopJump();
	void spin(int from, int to);

	// Where is the center of the character
	Vector2f getCenter();
	Vector2f getPos();

	// We will call this function once every frame
	void update(float elapsedTime);
};

