#pragma once

// Uncomment the USE_SFML #define if sfml is linked to your project.
#define USE_SFML

#ifdef USE_SFML
#include <SFML/System/Vector2.hpp>
#endif // USE_SFML

namespace rng_utils {

	// Generates a random integer between the given boundaries.
	int rnd_int(int lowerInc, int upperInc);

	// Generates a random float within the given boundaries.
	float rnd_float(float min, float max);

	// Generates a random normalized float (between -1 and 1).
	float rnd_normal_float();

	// Generates a float representing an angle in degrees (between 0 and 360).
	float rnd_angle_deg();

	// Generates a float representing an angle in radians (between 0 and 2*pi).
	float rnd_angle_rad();

#ifdef USE_SFML
	// Generates a vector with random XY values between the given boundaries.
	sf::Vector2f rnd_sfvector(float minX, float maxX, float minY, float maxY);

	// Generates a random unit vector.
	sf::Vector2f rnd_unit_sfvector();

	// Generates a random point located within the given rectangle.
	sf::Vector2f rnd_point_on_rect(sf::Vector2f topLeftCorner, sf::Vector2f size);

	// Generates a random point located within the given rectangle.
	sf::Vector2f rnd_point_on_rect(sf::Vector2f center, float width, float height);

	// Generates a random point located within the given circle.
	sf::Vector2f rnd_point_on_circle(float circleRadius, sf::Vector2f circleCenter = { 0.f,0.f });

	// Generates a random point located on the given taurus (taurus = donut).
	sf::Vector2f rnd_point_on_torus(float innerRadius, float outerRadius, sf::Vector2f torusCenter = { 0.f,0.f });
#endif // USE_SFML
}
