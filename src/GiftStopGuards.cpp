#pragma once
#include "GiftStopGuards.h"
#include "Guard.h"

GiftStopGuards::GiftStopGuards(sf::Texture& texture, sf::Vector2f position)
	: Gift(texture, position) { }
//==================================
void GiftStopGuards::collided(Robot& robot)
{
	m_isDead = true;
	Guard::dontMove(4);
}
