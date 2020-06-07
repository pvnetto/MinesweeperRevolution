#pragma once
#include "Entity.h"

class ContextManager;

/// <summary>
///	Contexts should contain all elements on screen. They're used by the ContextManager
///	to draw entities and delegate events to them.
/// </summary>
class BaseContext {
protected:
	ContextManager* ctxManager;
	std::vector<Entity*> entities;

public:
	BaseContext(ContextManager& ctxManager);
	virtual ~BaseContext() = default;

	/// <summary>
	///	Delegates events to all entities.
	/// </summary>
	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& evt) = 0;

	/// <summary>
	///	Delegates draw to all entities.
	/// </summary>
	virtual void draw(sf::RenderWindow& window);

	/// <summary>
	///	Returns ContextManager. This allows entities to switch context.
	/// </summary>
	inline ContextManager* getContextManager() {
		return ctxManager;
	}

	/// <summary>
	///	Finds the first Entity of type T.
	/// </summary>
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
