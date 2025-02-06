#pragma once
#include "GiftAddTime.h"
#include "Robot.h"

GiftAddTime::GiftAddTime(sf::Texture& texture, sf::Vector2f position, const bool isHidden)
	: Gift(texture, position, isHidden) { }
//=====================================
void GiftAddTime::collided(Robot& robot)
{
	if (m_hidden)
		return;

	SoundManager::getInstance().playGiftSound();
	m_isDead = true;
	robot.collided(*this);
}
//=====================================
