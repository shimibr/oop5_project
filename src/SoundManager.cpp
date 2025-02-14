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
    loadSound(m_exlosionBuffer, m_exlosionSound, "exlosion.wav");
    loadSound(m_giftBuffer, m_giftSound, "gift.wav");
    loadSound(m_startLevelBuffer, m_startLevelSound, "startLevel.wav");
    loadSound(m_clickBuffer, m_clickSound, "click.wav");
    loadSound(m_winBuffer, m_winSound, "win.wav");
    loadSound(m_timerBuffer, m_timerSound, "timer.wav");
    loadSound(m_lostLiveBuffer, m_lostLiveSound, "lostLive.wav");
    loadSound(m_bombTimerBuffer, m_bombTimerSound, "bombTimer.wav");
    m_backgroundMusic.openFromFile("background.wav");
}
//======================================
void SoundManager::loadSound(sf::SoundBuffer& buffer, sf::Sound& sound, const std::string& filePath) {
    buffer.loadFromFile(filePath);
    sound.setBuffer(buffer);
}
//======================================
void SoundManager::playBackgroundMusic()
{
    m_backgroundMusic.setLoop(true);
    m_backgroundMusic.setVolume(50);
    m_backgroundMusic.play();
}
//=======================================
void SoundManager::stopAllSounds() {
    m_winSound.stop();
    m_exlosionSound.stop();
    m_clickSound.stop();
    m_timerSound.stop();
    m_backgroundMusic.stop();
}
//======================================
