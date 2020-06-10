#include "rng_utils.h"

namespace rng_utils {
	int rand_int(int lowerInc, int upperInc) {
		static std::default_random_engine rng{ static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()) };
		std::uniform_int_distribution<int> dist(lowerInc, upperInc);
		return dist(rng);
	}

	float rand_normalized_float(int precision) {
		return static_cast<float>(rand_int(-precision, precision)) / static_cast<float>(precision);
	}

	float rand_float(float min, float max) {
		auto val = ((min + max) + rand_normalized_float() * (max - min)) / 2.f;
		return val;
	}

	float random_angle_deg() {
		return rand_float(0.f, 360.f);
	}

	float random_angle_rad() {
		static constexpr float PI_2 = 2.f * 3.1415926f;
		return rand_float(0.f, PI_2);
	}

#ifdef USE_SFML
	sf::Vector2f random_vector(float minXY, float maxXY) {
		return sf::Vector2f(rand_float(minXY, maxXY), rand_float(minXY, maxXY));
	}

	sf::Vector2f random_unit_direction() {
		float randomRadianAngle = random_angle_rad();
		return sf::Vector2f(std::cosf(randomRadianAngle), std::sinf(randomRadianAngle));
	}

	sf::Vector2f random_point_within_circle(float circleRadius) {
		return random_unit_direction() * rand_float(0.f, circleRadius);
	}

	sf::Vector2f random_point_inside_donut(float innerRadius, float outerRadius) {
		return random_unit_direction() * rand_float(innerRadius, outerRadius);
	}
#endif // USE_SFML
}
