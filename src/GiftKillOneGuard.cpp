#pragma once
#include "GiftKillOneGuard.h"
#include "Robot.h"
#include "Guard.h"

GiftKillOneGuard::GiftKillOneGuard(sf::Texture& texture, sf::Vector2f position)
	: Gift(texture, position) { }
//=====================================
void GiftKillOneGuard::collided(Robot& robot)
{
	m_isDead = true;
	Guard::killOneGuard();
}
//=====================================
