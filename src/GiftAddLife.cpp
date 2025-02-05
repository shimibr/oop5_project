#pragma once
#include "GiftAddLife.h"
#include "Robot.h"

GiftAddLife::GiftAddLife(sf::Texture& texture, sf::Vector2f position)
	: Gift(texture, position) { }
//=====================================
void GiftAddLife::collided(Robot& robot)
{
	SoundManager::getInstance().playGiftSound();
	m_isDead = true;
	robot.collided(*this);
}
//=====================================
