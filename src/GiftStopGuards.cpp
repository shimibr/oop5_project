#pragma once
#include "GiftStopGuards.h"
#include "Guard.h"

GiftStopGuards::GiftStopGuards(sf::Texture& texture, sf::Vector2f position, const bool isHidden)
	: Gift(texture, position, isHidden) { }
//==================================
void GiftStopGuards::collided(Robot& robot)
{
	if (m_hidden)
		return;

	SoundManager::getInstance().playGiftSound();
	m_isDead = true;
	Guard::dontMove(4);
}
