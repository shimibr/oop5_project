#pragma once
#include "GiftKillOneGuard.h"
#include "Robot.h"
#include "Guard.h"

GiftKillOneGuard::GiftKillOneGuard()
	: Gift(0) { }
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
