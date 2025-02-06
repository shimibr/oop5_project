#pragma once
#include "GiftStopGuards.h"
#include "Guard.h"

GiftStopGuards::GiftStopGuards()
	: Gift(0) { }
//==================================
void GiftStopGuards::collided(Robot& robot)
{
	if (m_hidden)
		return;

	SoundManager::getInstance().playGiftSound();
	m_isDead = true;
	Guard::dontMove(4);
}
