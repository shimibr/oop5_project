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
    loadSound(m_loseBuffer, m_loseSound, "lose.wav");
    loadSound(m_exlosionBuffer, m_exlosionSound, "exlosion.wav");
    loadSound(m_giftBuffer, m_giftSound, "gift.wav");
}
//======================================
void SoundManager::loadSound(sf::SoundBuffer& buffer, sf::Sound& sound, const std::string& filePath) {
    buffer.loadFromFile(filePath);
    sound.setBuffer(buffer);
}
//======================================
void SoundManager::playWinSound() {
    m_winSound.play();
}
//======================================
void SoundManager::playLoseSound() {
    m_loseSound.play();
}
//======================================
void SoundManager::playExlosionSound() {
    m_exlosionSound.play();
}
//======================================
void SoundManager::playGiftSound() {
    m_giftSound.play();
}
//======================================
void SoundManager::stopAllSounds() {
    m_winSound.stop();
    m_loseSound.stop();
    m_exlosionSound.stop();
}
//======================================
