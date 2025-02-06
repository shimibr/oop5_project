#pragma once
#include "GiftAddLife.h"
#include "Robot.h"

GiftAddLife::GiftAddLife()
	: Gift(0) { }
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
