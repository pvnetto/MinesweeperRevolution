#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
///	Handles animation logic by swapping textures from spritesheets.
/// </summary>
class Animation {
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float animationDuration);
	~Animation();

	/// <summary>
	///	Runs the animation
	/// </summary>
	void Update(int row, float deltaTime);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentUV;

	float animationDuration;
	float switchDuration;
	
	// State Management
	float switchTime = 0.0;

};