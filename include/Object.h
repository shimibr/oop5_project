#pragma once
class Wall;
class Robot;
class Guard;
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
	//const sf::Sprite& getSprite(); // צריך לבדוק אולי אפשר למחוק

protected:
	sf::Sprite m_sprite;
	bool m_isDead = false;
};
