#pragma once
#include "SoundManager.h"
#include <iostream>

SoundManager& SoundManager::getInstance() {
    static SoundManager instance;
    return instance;
}
//======================================
SoundManager::SoundManager() {
    loadSound(m_winBuffer, m_winSound, "win.wav");
//    loadSound(m_loseBuffer, m_loseSound, "lose.wav");
    loadSound(m_exlosionBuffer, m_exlosionSound, "exlosion.wav");
    loadSound(m_giftBuffer, m_giftSound, "gift.wav");
    loadSound(m_startLevelBuffer, m_startLevelSound, "startLevel.wav");
    loadSound(m_clickBuffer, m_clickSound, "click.wav");
    loadSound(m_winBuffer, m_winSound, "win.wav");
    loadSound(m_timerBuffer, m_timerSound, "timer.wav");
    loadSound(m_lostLiveBuffer, m_lostLiveSound, "lostLive.wav");
    loadSound(m_bombTimerBuffer, m_bombTimerSound, "lostLive.wav");
}
//======================================
void SoundManager::loadSound(sf::SoundBuffer& buffer, sf::Sound& sound, const std::string& filePath) {
    buffer.loadFromFile(filePath);
    sound.setBuffer(buffer);
}
//=======================================
void SoundManager::stopAllSounds() {
    m_winSound.stop();
    m_loseSound.stop();
    m_exlosionSound.stop();
    m_clickSound.stop();
    m_timerSound.stop();
}
//======================================
