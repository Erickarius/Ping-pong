#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball : public sf::Drawable
{
public:
	Ball(float x, float y);
	Ball() = delete;
	~Ball() = default;

	void update();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	Vector2f getPosition();

	
	float left();
	float right();
	float top();
	float bottom();
private:
	CircleShape shape;
	const float ballRadius{ 10.0f };
	const float ballVelocity{ 5.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };
	void draw(RenderTarget& target, RenderStates state) const override;
};