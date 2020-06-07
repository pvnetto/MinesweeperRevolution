#pragma once
#include "SFML/Graphics.hpp"

/// <summary>
/// Abstract class for game entities.
/// </summary>
class Entity {
protected:
	/// <summary>
	/// If false, entity is not drawn by context
	/// </summary>
	bool active = true;

public:
	/// <summary>
	/// Entities should use window to draw themselves.
	/// </summary>
	virtual void draw(sf::RenderWindow& window) = 0;

	inline bool isActive() { return active; }
	void setActive(bool val);
};