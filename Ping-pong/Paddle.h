#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Paddle : public sf::Drawable
{
public:
	Paddle(float t_X, float t_Y);
	Paddle() = delete;

	~Paddle() = default;

	void update_1();
	void update_2();

	float left();
	float right();
	float top();
	float bottom();

	Vector2f getPosition();

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape;
	const float paddleWidth{ 80.0f };
	const float paddleHeight{ 20.0f };
	const float paddleVelocity{ 8.0f };
	Vector2f velocity{ paddleVelocity, 0.f };
};