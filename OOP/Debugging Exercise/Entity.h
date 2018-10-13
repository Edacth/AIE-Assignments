#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	bool isAlive();
	int getAttack();
	void takeDamage(int damage);

protected:
	int health;
	int maxHealth;
	int attackValue;
	bool alive;
};

