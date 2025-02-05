#pragma once
#include "GiftAddTime.h"
#include "Robot.h"

GiftAddTime::GiftAddTime(sf::Texture& texture, sf::Vector2f position)
	: Gift(texture, position) { }
//=====================================
void GiftAddTime::collided(Robot& robot)
{
	SoundManager::getInstance().playGiftSound();
	m_isDead = true;
	robot.collided(*this);
}
//=====================================
