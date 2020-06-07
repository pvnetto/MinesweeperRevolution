#pragma once
#include "InteractableEntity.h"
#include "GameManager.h"
#include "ContextManager.h"

/// <summary>
/// InteractableEntity for a simple UI Button, with background, text and border.
/// </summary>
class Button : public InteractableEntity {
public:

	/// <summary>
	/// Helper class for button click actions
	/// </summary>
	class ButtonAction {
	public:
		/// <summary>
		/// Implements action logic. Called when the button is clicked.
		/// </summary>
		virtual void action(BaseContext & ctx) = 0;
	};

	/// <summary>
	/// Restarts the current game.
	/// <summary>
	class RestartAction : public ButtonAction {
	public:
		virtual void action(BaseContext&ctx) override {
			GameManager* gm = ctx.findEntity<GameManager>();
			gm->restart(ctx);
		}
	};

	/// <summary>
	/// Quits the game.
	/// <summary>
	class QuitAction : public ButtonAction {
	private:
		sf::Window* window = nullptr;
	public:
		QuitAction(sf::Window& window) {
			this->window = &window;
		}

		virtual void action(BaseContext&ctx) override {
			window->close();
		}
	};

	/// <summary>
	/// Switches the current Context.
	/// <summary>
	template <class T>
	class ContextAction : public ButtonAction {
	public:
		virtual void action(BaseContext&ctx) override {
			ctx.getContextManager()->switchContext<T>();
		}
	};

public:
	sf::Font font;
	sf::RectangleShape btnShape;
	sf::RectangleShape btnBorder;
	sf::Text btnText;

	sf::Texture* btnTexture = nullptr;
	ButtonAction* clickAction = nullptr;
public:
	Button();
	Button(std::string text, sf::Vector2f pos, sf::Vector2f size, ButtonAction* clickAction);
	~Button();

	virtual void draw(sf::RenderWindow & window) override;
	virtual sf::Shape* getShape() override;
	virtual void handleAction(Action action, BaseContext & ctx) override;

	void setFillColor(sf::Color newColor);
	void setTexture(std::string path);
};