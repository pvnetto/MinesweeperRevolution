#pragma once
#include "Entity.h"

class BaseContext {
protected:
	std::vector<Entity*> entities;

public:
	virtual ~BaseContext() = default;

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) = 0;
	virtual void draw(sf::RenderWindow& window);

	template<class T>
	T* findEntity();
};

template<class T>
T* BaseContext::findEntity() {
	for (auto iter = entities.begin(); iter != entities.end(); iter++) {
		T* castEntity = dynamic_cast<T*>(*(iter));
		if (castEntity) {
			return castEntity;
		}
	}

	return nullptr;
}
