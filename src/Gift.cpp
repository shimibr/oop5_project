#pragma once

#include "Gift.h"
#include "dataTexture.h"
#include "LoadFile.h"

//=================================
Gift::Gift(bool isHidden)
	:Object(DataTexture::getInstance().getTexture(Entity::GIFT), LoadFile::getInstance().getLegalGiftLoc(isHidden)) , m_hidden(isHidden) { }
//=================================
void Gift::collided(Explosion& explosion)
{
	if (m_hidden)
		m_hidden = false;
}
//====================================
