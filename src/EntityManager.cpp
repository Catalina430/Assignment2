#include "EntityManager.h"

#include "Entity.h"

void EntityManager::removeDeadEntities(EntityVec& vec)
{
	//If entity is dead remove it from map and vector
	std::erase_if(vec, [](std::shared_ptr<Entity>& entity) {if (entity->isAlive()) return false; });
	
}

void EntityManager::update()
{
	//Called at beginning of each frame by game engine
	//Entities added will now be available to use this frame
	for (std::shared_ptr<Entity> entity : m_toAdd)
	{
		m_entities.push_back(entity);
		m_entityMap[entity->tag()].push_back(entity);
	}
	m_toAdd.clear();

	removeDeadEntities(m_entities);

	//Remove dead entities from each vector in the entity map
	for (auto& [tag, entityVec] : m_entityMap)
	{
		removeDeadEntities(entityVec);
	}
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	//Create a new Entity object
	std::shared_ptr<Entity> entity = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities++));

	//Store it in the vector of all entities
	m_toAdd.push_back(entity);

	return entity;
}

EntityVec& EntityManager::getEntities()
{
	return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag)
{
	return m_entityMap[tag];
}
