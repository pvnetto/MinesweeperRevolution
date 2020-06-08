#pragma once
#include "BaseContext.h"
#include "InteractableEntity.h"

/// <summary>
/// Base class for entities that draw other Entities and SFML/Drawable objects. Child classes are
/// expected to initialize all objects they're going to handle and add them to the entities, drawables lists.
/// </summary>
class CanvasEntity : public Entity {
private:
	/// <summary> Prevents input from activating instantly when input is toggled </summary>
	int waitTick = 0;

protected:
	bool inputEnabled = true;
	sf::View* view = nullptr;
	std::vector<InteractableEntity*> entities;
	std::vector<sf::Drawable*> drawables;

public:
	virtual ~CanvasEntity() { deleteCanvas(); };

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

	/// <summary>
	/// Enables/disables input handling.
	/// </summary>
	void toggleInput(bool val);
};