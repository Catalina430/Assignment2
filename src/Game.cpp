#include "Game.h"

#include <fstream>

//Check for collision of the entities
void Game::sCollision()
{
	for (auto& e : m_entityManager.getEntities("Enemy"))
	{
		//Calculate the collision against the walls 
		for (auto& e : m_entityManager.getEntities("Player"))
		{
			//Calculate the collision && calculate the collision against the walls

			//TODO : Make sure that collision works even if we are calculating in the Enemy vs Player Collision loop
		}
	}
}

//Spawn the enemies
void Game::sSpawner()
{
}

//Read in the user input of the player
void Game::sUserInput()
{
	//SFML code right here 
	//Poll the event etc.
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		//Window input
		//
		//Closes the application and the window if we press X on the window
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			m_isRunning = false;
		}
		//Pauses the game if we are not on the window
		if (event.type == sf::Event::LostFocus)
		{
			m_isPaused = true;
		}
		else if (event.type == sf::Event::GainedFocus)
		{
			m_isPaused = false;
		}
		m_entityManager;

		//Debug why theres no entities in the vector
		//
		//Player input
		for (auto& e : m_entityManager.getEntities("Player"))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:
				{
					e->cUserInput->wPressed = true;
					break;
				}
				case sf::Keyboard::S:
				{
					e->cUserInput->sPressed = true;
					break;
				}
				case sf::Keyboard::A:
				{
					e->cUserInput->aPressed = true;
					break;
				}
				case sf::Keyboard::D:
				{
					e->cUserInput->dPressed = true;
					break;
				}
				case sf::Keyboard::Escape:
				{
					//Make sure this doesnt do an
					//TODO : Check if this causes any issues
					m_window.close();
					m_isRunning = false;
					std::cout << "Escape was pressed\n";
				}
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:
				{
					e->cUserInput->wPressed = false;
				
					break;
				}
				case sf::Keyboard::S:
				{
					e->cUserInput->sPressed = false;
					break;
				}
				case sf::Keyboard::A:
				{
					e->cUserInput->aPressed = false;
					break;
				}
				case sf::Keyboard::D:
				{
					e->cUserInput->dPressed = false;
					break;
				}
				}
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Left:
				{
					e->cUserInput->leftMouse = true;
					break;
				}
				case sf::Mouse::Right:
				{
					e->cUserInput->rightMouse = true;
					break;
				}
				}
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Left:
				{
					e->cUserInput->leftMouse = false;
					break;
				}
				case sf::Mouse::Right:
				{
					e->cUserInput->rightMouse = false;
					break;
				}
				}
			}
		}

		
	}
}

//Update the position of the player with the input and also the enemies position
void Game::sMovement()
{
	//This is where we check if the player pressed a key with the input component 
	//and add velocity
	//Also need to do the same for the enemies.
}

//Render all the entities of the game 
void Game::sRender()
{
	m_window.clear();

	for (auto& e : m_entityManager.getEntities())
	{
		m_window.draw(e->cShape->shape);
	}

	m_window.display();
}

//Read in the config file and set the config variables 
void Game::init(const std::string& file)
{
	std::ifstream input(file, std::ifstream::in);

	if (input.good())
	{
		std::string identifier = "";

		while (input >> identifier)
		{
			if (identifier == "Window")
			{

			}
			else if (identifier == "player")
			{

			}
			else if(identifier == "Enemy")
			{

			}
		}
	}
	//Debug stuff
	m_window.create(sf::VideoMode(800, 800), "Assigment 2");

	std::shared_ptr<Entity> entity = m_entityManager.addEntity("Player");
	entity->cUserInput = std::make_shared<CUserInput>();
	entity->cShape = std::make_shared<CShape>(sf::CircleShape(30.0f, 16));

	//Set the origin of the shape to the center of the circle to make it easier to calculate the collisions
}

void Game::update()
{

	//Updates the entity manager so the entities in m_toAdd get added to the ingame entities
	m_entityManager.update();

	//We still want the user input and the rendering to work even if the game is paused
	sUserInput();
	if (!m_isPaused)
	{
		sMovement();
		sSpawner();
		sCollision();
	}
	sRender();

}

Game::Game(const std::string& configFilePath)
	: m_isRunning(true), m_isPaused(false)
{
	init(configFilePath);
}

void Game::run()
{
	while (m_isRunning)
	{
		update();
	}

}
