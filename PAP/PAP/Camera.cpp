#include "Camera.h"
#include "Include.h"

View& Camera::load()
{
	View camera;
	camera.reset(FloatRect(0, 0, 960, 540));
	return camera;
}

void Camera::move(View& camera, const Vector2f& pos)
{
	camera.setCenter(pos);
}

void Camera::render(View& camera, RenderWindow& window)
{
	window.setView(camera);
}

void Camera::scrolle(View& camera, Event& event)
{
	if (event.type == sf::Event::MouseWheelScrolled)
	{
		if (event.mouseWheelScroll.delta < 0)
			camera.zoom(1.1f);
		else if (event.mouseWheelScroll.delta > 0)
			camera.zoom(0.9f);
	}
}