#pragma once

#include "Vec2.h"
#include <SFML/Graphics.hpp>

class CCollision
{
public:
	float radius;
	CCollision(float r)
		: radius(r)
	{
	}
};

class CScore
{
public:
	float score;
	CScore()
		: score(0)
	{
	}
	//IDK why you would need this lol
	CScore(float s)
		: score(s)
	{
	}
};

class CUserInput
{
public:
	bool wPressed;
	bool sPressed;
	bool aPressed;
	bool dPressed;
	bool leftMouse;
	bool rightMouse;

	CUserInput()
		: wPressed(false), sPressed(false), aPressed(false), dPressed(false), leftMouse(false),rightMouse(false)
	{
	}
};

class CTransform
{
public:
	Vec2 Position;
	//Keep this normalized so we can get a direction an then multiply with the speed
	Vec2 Velocity;
	float speed;

	CTransform(Vec2 p, Vec2 v, float s)
		: Position(p), Velocity(v), speed(s)
	{
	}
	CTransform(float xPosition, float yPosition, float xVelocity, float yVelocity, float spe)
		: Position(xPosition, yPosition), Velocity(xVelocity, yVelocity), speed(spe)
	{
	}
};

class CShape
{
public:
	sf::CircleShape shape;

	CShape(sf::CircleShape s)
		: shape(s)
	{
	}
};