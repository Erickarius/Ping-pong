#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

using namespace sf;
using namespace std;

template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right()
		&& A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool collisionTestLowerPaddle(Paddle& paddle_1, Ball& ball)
{
	if (!isIntersecting(paddle_1, ball)) return false;

	ball.moveUp();

	if (ball.getPosition().x < paddle_1.getPosition().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paddle_1.getPosition().x)
	{
		ball.moveRight();
	}
}

bool collisionTestUpperPaddle(Paddle& paddle_2, Ball& ball)
{
	if (!isIntersecting(paddle_2, ball)) return false;

	ball.moveDown();

	if (ball.getPosition().x < paddle_2.getPosition().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paddle_2.getPosition().x)
	{
		ball.moveRight();
	}
}


int main() {
	Ball ball(400, 300);
	Paddle paddle_1(400, 559), paddle_2(400, 50);
	RenderWindow window{ VideoMode{800, 600}, "Ping-pong" };
	window.setFramerateLimit(60);
	Event event; 
	unsigned blocksX{ 10 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{ 20 };

	while (true)
	{
		window.clear(Color::Green);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		ball.update();
		paddle_1.update_1();
		collisionTestLowerPaddle(paddle_1, ball);
		paddle_2.update_2();
		collisionTestUpperPaddle(paddle_2, ball);

		window.draw(ball);
		window.draw(paddle_1);
		window.draw(paddle_2);
		window.display();
	}
	return 0;
}