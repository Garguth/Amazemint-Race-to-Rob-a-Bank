#pragma once
#include "PlayableCharacter.h"
class Item :
	public PlayableCharacter
{
public:
	Item();
	void setSprite(int spriteType);
	int type;
	int value;
	bool virtual handleInput();

};

