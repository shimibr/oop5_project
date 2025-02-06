#pragma once
#include "GiftAddTime.h"
#include "Robot.h"

GiftAddTime::GiftAddTime()
	: Gift(0) { }
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
