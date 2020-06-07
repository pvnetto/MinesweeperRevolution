#include "CanvasEntity.h"
#include "Action.h"

void CanvasEntity::draw(sf::RenderWindow & window) {
	if (view) {
		window.setView(*view);
	}
	else {
		window.setView(window.getDefaultView());
	}

	for (auto it = drawables.begin(); it != drawables.end(); it++) {
		window.draw(*(*it));
	}

	for (auto it = entities.begin(); it != entities.end(); it++) {
		(*it)->draw(window);
	}
}

void CanvasEntity::handleEvents(BaseContext & ctx, const sf::RenderWindow & window, const sf::Event & evt) {
	waitTick = std::max(waitTick - 1, 0);
	if (active && inputEnabled && waitTick <= 0) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosF = sf::Vector2f(mousePos.x, mousePos.y);
		sf::Vector2f mousePosWorld = window.mapPixelToCoords(mousePos);

		for (auto it = entities.begin(); it != entities.end(); it++) {
			auto entity = *it;
			if (entity->getShape()->getGlobalBounds().contains(mousePosWorld)) {
				if (evt.type == sf::Event::MouseButtonReleased) {
					if (evt.mouseButton.button == sf::Mouse::Left) {
						entity->handleAction(Action::LEFT_CLICK, ctx);
					}
					else if (evt.mouseButton.button == sf::Mouse::Right) {
						entity->handleAction(Action::ALT_CLICK, ctx);
					}
				}
				else {
					entity->handleAction(Action::MOUSE_ENTER, ctx);
				}
			}
			else {
				entity->handleAction(Action::MOUSE_LEAVE, ctx);
			}
		}
	}
}

void CanvasEntity::toggleInput(bool val) {
	inputEnabled = val;
	waitTick = 3;
}

void CanvasEntity::deleteCanvas() {
	if (view) {
		delete view;
	}

	for (auto it = drawables.begin(); it != drawables.end(); it++) {
		delete *it;
	}

	for (auto it = entities.begin(); it != entities.end(); it++) {
		delete *it;
	}
}
