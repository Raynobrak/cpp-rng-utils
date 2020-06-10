#pragma once

#include <random>
#include <chrono>

// Uncomment the following USE_SFML #define if sfml is linked to your project.
//#define USE_SFML

#ifdef USE_SFML
#include <SFML/System/Vector2.hpp>
#endif // USE_SFML

namespace rng_utils {
	int rand_int(int lowerInc, int upperInc);
	float rand_normalized_float(int precision = 10000000);
	float rand_float(float min, float max);
	float random_angle_deg();
	float random_angle_rad();

#ifdef USE_SFML
	sf::Vector2f random_vector(float minXY, float maxXY);
	sf::Vector2f random_unit_direction();
	sf::Vector2f random_point_within_circle(float circleRadius);
	sf::Vector2f random_point_inside_donut(float innerRadius, float outerRadius);
#endif // USE_SFML
}
