#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float animationDuration) {
	this->imageCount = imageCount;
	this->animationDuration = animationDuration;
	this->switchDuration = animationDuration / (imageCount.x * imageCount.y);

	currentUV.x = 0;
	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.width = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation() { }

void Animation::Update(int row, float deltaTime) {
	currentUV.y = row;
	switchTime += deltaTime;

	if (switchTime >= switchDuration) {
		switchTime -= switchDuration;
		currentUV.x = currentUV.x + 1 < imageCount.x ? currentUV.x + 1 : 0;
	}

	// Pans UV Rect instead of changing its size
	uvRect.left = currentUV.x * uvRect.width;
	uvRect.top = currentUV.y * uvRect.height;
}
