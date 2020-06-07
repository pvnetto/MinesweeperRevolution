#pragma once
#include "InteractableEntity.h"
#include "GameManager.h"

class Button : public InteractableEntity {
public:
	class ButtonAction {
	public:
		virtual void action(BaseContext & ctx) = 0;
	};

	class RestartAction : public ButtonAction {
	public:
		virtual void action(BaseContext&ctx) override {
			GameManager* gm = ctx.findEntity<GameManager>();
			gm->restart(ctx);
		}
	};

	class QuitAction : public ButtonAction {
	public:
		virtual void action(BaseContext&ctx) override {
			printf("quitting....");
		}
	};

public:
	sf::Font font;
	sf::RectangleShape btnShape;
	sf::RectangleShape btnBorder;
	sf::Text btnText;

	ButtonAction* clickAction = nullptr;
public:
	Button();
	Button(std::string text, sf::Vector2f pos, sf::Vector2f size, ButtonAction* clickAction);
	~Button();

	virtual void draw(sf::RenderWindow & window) override;
	virtual sf::Shape* getShape() override;
	virtual void handleAction(Action action, BaseContext & ctx) override;
};