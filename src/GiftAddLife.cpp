#pragma once
#include "GiftAddLife.h"
#include "Robot.h"

GiftAddLife::GiftAddLife(sf::Texture& texture, sf::Vector2f position, const bool isHidden)
	: Gift(texture, position, isHidden) { }
//=====================================
void GiftAddLife::collided(Robot& robot)
{
	if (m_hidden)
		return;

	SoundManager::getInstance().playGiftSound();
	m_isDead = true;
	robot.collided(*this);
}
//=====================================
