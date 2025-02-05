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
    loadSound(m_secendBuffer, m_secendSound, "win.wav");
    loadSound(m_lostLiveBuffer, m_lostLiveSound, "win.wav");
}
//======================================
void SoundManager::loadSound(sf::SoundBuffer& buffer, sf::Sound& sound, const std::string& filePath) {
    buffer.loadFromFile(filePath);
    sound.setBuffer(buffer);
}
//=======================================
void SoundManager::playsecendSounds()
{
    //m_timerCount += timer.getElapsedTime().asSeconds();
    //if(m_timerCount >= 1)
    //{
    //    m_secendSound.play();
    //    timer.restart();
    //    m_timerCount--;
    //}

}
//======================================
void SoundManager::stopAllSounds() {
    m_winSound.stop();
    m_loseSound.stop();
    m_exlosionSound.stop();
    m_clickSound.stop();
}
//======================================
