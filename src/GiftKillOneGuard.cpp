#pragma once
#include "GiftKillOneGuard.h"
#include "Robot.h"
#include "Guard.h"

GiftKillOneGuard::GiftKillOneGuard(sf::Texture& texture, sf::Vector2f position, const bool isHidden)
	: Gift(texture, position, isHidden) { }
//=====================================
void GiftKillOneGuard::collided(Robot& robot)
{
	if (m_hidden)
		return;

	SoundManager::getInstance().playGiftSound();
	m_isDead = true;
	Guard::killOneGuard();
}
//=====================================
