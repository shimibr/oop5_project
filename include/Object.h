#pragma once

#include <SFML/Graphics.hpp>
#include "io.h"

class Wall;
class Robot;
class Guard;
class Explosion;
class Door;
class Gift;
class GiftStopGuards;
class Bomb;
class Stone;
class Object
{
public:
	Object();
	virtual ~Object() { ;}
	Object(sf::Texture& texture, sf::Vector2f position);
	virtual void update(sf::RenderWindow& window);
	bool isDead() const;
	sf::FloatRect getGlobalLoc() const;

	virtual void collided(Guard& guard) {}
	virtual void collided(Wall& wall) {}
	virtual void collided(Robot& robot) {}
	virtual void collided(Door& door) {}
	virtual void collided(Bomb& bomb) {}
	virtual void collided(Explosion& explosion) {}
	virtual void collided(Stone& stone) {}

protected:
	sf::Sprite m_sprite;
	bool m_isDead = false;
};
