#pragma once

#include "Gift.h"

//=================================
Gift::Gift(sf::Texture& texture, sf::Vector2f position ,const bool isHidden)
	:Object(texture, position) , m_hidden(isHidden) { }
//=================================
void Gift::collided(Explosion& explosion)
{
	if (m_hidden)
		m_hidden = false;
}
//====================================
