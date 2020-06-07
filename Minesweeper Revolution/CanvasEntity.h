#pragma once
#include "BaseContext.h"
#include "InteractableEntity.h"

/// <summary>
/// Base class for entities that draw other Entities and SFML/Drawable objects.
/// </summary>
class CanvasEntity : public Entity {
protected:
	bool inputEnabled = true;
	sf::View* view = nullptr;
	std::vector<InteractableEntity*> entities;
	std::vector<sf::Drawable*> drawables;

public:
	/// <summary>
	/// Delegates draw for Entities and Drawables
	/// </summary>
	virtual void draw(sf::RenderWindow& window) override;

	/// <summary>
	/// Delegates events for Entities and Drawables
	/// </summary>
	virtual void handleEvents(BaseContext& ctx, const sf::RenderWindow& window, const sf::Event& evt);

	/// <summary>
	/// Deletes all pointers to Entities and Drawables
	/// </summary>
	void deleteCanvas();

	void toggleInput(bool val);
};