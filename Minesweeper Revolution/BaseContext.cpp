#include "BaseContext.h"

BaseContext::BaseContext(ContextManager& ctxManager) {
	this->ctxManager = &ctxManager;
}

void BaseContext::draw(sf::RenderWindow& window) {
	for (auto it = entities.begin(); it != entities.end(); it++) {
		auto entity = (*it);
		if (entity->isActive()) {
			entity->draw(window);
		}
	}
}