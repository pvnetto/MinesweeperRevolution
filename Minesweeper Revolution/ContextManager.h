#pragma once
#include "BaseContext.h"
#include <type_traits>

class ContextManager {
private:
	BaseContext* currentContext = nullptr;
	BaseContext* nextContext = nullptr;
	sf::RenderWindow* window;

public:
	ContextManager(sf::RenderWindow& window);

	///	<summary>
	/// Handles game loop logic, delegates events and rendering to the current context.
	/// </summary>
	void run();

	///	<summary>
	/// Deletes current context and switches to a new one.
	/// </summary>
	template<class T>
	void switchContext();

	/// <summary>
	/// Changes context only after the current context finishes processing its draw and event calls
	/// </summary>
	void handleContextSwitch();
};

template<class T>
inline void ContextManager::switchContext() {
	// Checks if T inherits from BaseContext
	static_assert(std::is_base_of<BaseContext, T>::value, "T must inherit from BaseContext.");

	T* newContext = new T(*this, *window);
	nextContext = newContext;
}
