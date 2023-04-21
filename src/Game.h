#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include "EntityManager.h"

class Entity;

class EntityManager;

class Game
{
private:

	sf::RenderWindow m_window;
	EntityManager m_entityManager;

	bool m_isRunning;
	bool m_isPaused;

	std::shared_ptr<Entity> m_player;

	void sCollision();
	void sSpawner();
	void sUserInput();
	void sMovement();
	void sRender();

	//Read in the config file
	void init(const std::string& file);
	void update();

	ConfigVariables configVariables;

public:

	Game(const std::string& configFilePath);
	void run();

};

struct ConfigVariables
{
	//Window


	//Player


	//Enemy

};