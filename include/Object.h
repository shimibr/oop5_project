#pragma once
class Wall;
class Robot;
class Guard;
class Explosion;
#include <SFML/Graphics.hpp>
#include "io.h"

class Object
{
public:
	Object();
	Object(sf::Texture& texture, sf::Vector2f position);
	virtual void update(sf::RenderWindow& window);
	bool isDead() const;
	sf::FloatRect getGlobalLoc() const;

	virtual void collided(Guard& guard);
	virtual void collided(Wall& wall);
	virtual void collided(Robot& robot);
	virtual void collided(Explosion& explosion);
	//const sf::Sprite& getSprite(); // ���� ����� ���� ���� �����

protected:
	sf::Sprite m_sprite;
	bool m_isDead = false;
};
