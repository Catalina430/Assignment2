#pragma once

#include <string>
#include<memory>

#include "Components.cpp"

class Entity
{
private:
	const size_t		m_id = 0;
	const std::string	m_tag = "Default";
	bool				m_alive = true;

	Entity(const std::string& tag, size_t id);
	Entity() {};

	friend class EntityManager;
public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CShape> cShape;
	//std::shared_ptr<CName> cName;
	//std::shared_ptr<CBBox> cBBox;
	std::shared_ptr<CUserInput> cUserInput;
	std::shared_ptr<CCollision> cCollision;

	bool isAlive() const;
	void destroy();
	std::string tag() const;

};