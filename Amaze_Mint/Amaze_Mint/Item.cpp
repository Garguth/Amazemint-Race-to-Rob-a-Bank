#include "Item.h"
#include "TextureHolder.h"
Item::Item()
{

	// Associate a texture with the sprite
	timer = 0;
}
void Item::setSprite(int spriteType)
{
	if (spriteType == 1)
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/money.png"));
	}
	if (spriteType == 2)
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/card.png"));
	}
	if (spriteType == 3)
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/screwDriver.png"));
	}
	type = spriteType;
}
bool Item::handleInput()
{
	return false;
}