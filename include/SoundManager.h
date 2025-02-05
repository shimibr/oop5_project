#pragma once
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>


class SoundManager {
public:
    static SoundManager& getInstance();

    SoundManager& operator=(SoundManager& other) = delete;
    SoundManager(SoundManager& other) = delete;

    void playWinSound(){ m_winSound.play(); }
    void playLoseSound(){ m_loseSound.play();}
    void playExlosionSound(){ m_exlosionSound.play(); }
    void playGiftSound(){ m_giftSound.play(); }
    void playStartLevelSounds() { m_startLevelSound.play(); }
    void playClickSounds() { m_clickSound.play(); }

    void stopAllSounds();

private:
   SoundManager();

    sf::SoundBuffer m_winBuffer;
    sf::SoundBuffer m_loseBuffer;
    sf::SoundBuffer m_exlosionBuffer;
    sf::SoundBuffer m_giftBuffer;
    sf::SoundBuffer m_startLevelBuffer;
    sf::SoundBuffer m_clickBuffer;

    sf::Sound m_winSound;
    sf::Sound m_loseSound;
    sf::Sound m_exlosionSound;
    sf::Sound m_giftSound;
    sf::Sound m_startLevelSound;
    sf::Sound m_clickSound;

    void loadSound(sf::SoundBuffer& buffer, sf::Sound& sound, const std::string& filePath);
};
