#pragma once
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>


class SoundManager {
public:
    static SoundManager& getInstance();

    SoundManager& operator=(SoundManager& other) = delete;
    SoundManager(SoundManager& other) = delete;

    void playWinSound();
    void playLoseSound();
    void playExlosionSound();
    void playGiftSound();
    void stopAllSounds();

private:
   SoundManager();

    sf::SoundBuffer m_winBuffer;
    sf::SoundBuffer m_loseBuffer;
    sf::SoundBuffer m_exlosionBuffer;
    sf::SoundBuffer m_giftBuffer;

    sf::Sound m_winSound;
    sf::Sound m_loseSound;
    sf::Sound m_exlosionSound;
    sf::Sound m_giftSound;

    void loadSound(sf::SoundBuffer& buffer, sf::Sound& sound, const std::string& filePath);
};
