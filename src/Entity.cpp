#include "Entity.h"
#include <iostream>

Entity::Entity(const std::string& tag, size_t id)
	:m_tag(tag), m_id(id), m_alive(true)
{
	std::cout << "Entity Created\n" << m_tag << '\n';
}

bool Entity::isAlive() const
{
	return m_alive;
}

void Entity::destroy()
{
	m_alive = false;
	std::cout << "Entity destroyed\n";
}

std::string Entity::tag() const
{
	return m_tag;
}
