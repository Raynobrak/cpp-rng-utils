#include <random>
#include <chrono>

#include "rng_utils.h"

namespace rng_utils {
	int rnd_int(int lowerInc, int upperInc) {
		static std::default_random_engine rng{ static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()) };
		std::uniform_int_distribution<int> dist(lowerInc, upperInc);
		return dist(rng);
	}

	float rnd_float_normalized(int precision) {
		return static_cast<float>(static_cast<float>(rnd_int(-precision, precision))) / static_cast<float>(precision);
	}

	float rnd_float(float min, float max) {
		auto val = ((min + max) + rnd_float_normalized() * (max - min)) / 2.f;
		return val;
	}

	float rnd_angle_deg() {
		return rnd_float(0.f, 360.f);
	}

	float rnd_angle_rad() {
		static constexpr float PI_2 = 2.f * 3.1415926f;
		return rnd_float(0.f, PI_2);
	}

#ifdef USE_SFML
	sf::Vector2f rnd_sfvector(float minX, float maxX, float minY, float maxY) {
		return sf::Vector2f(rnd_float(minX, maxX), rnd_float(minY, maxY));
	}

	sf::Vector2f rnd_unit_sfvector() {
		float randomRadianAngle = rnd_angle_rad();
		return sf::Vector2f(std::cosf(randomRadianAngle), std::sinf(randomRadianAngle));
	}

	sf::Vector2f rnd_point_on_rect(sf::Vector2f topLeftCorner, sf::Vector2f size) {
		auto bottomRightCorner = topLeftCorner + size;
		return rnd_sfvector(topLeftCorner.x, topLeftCorner.y, bottomRightCorner.x, bottomRightCorner.y);
	}

	sf::Vector2f rnd_point_on_rect(sf::Vector2f center, float width, float height) {
		return center + sf::Vector2f(rnd_float_normalized(width / 2.f), rnd_float_normalized(height / 2.f));
	}

	sf::Vector2f rnd_point_on_circle(float circleRadius, sf::Vector2f circleCenter) {
		return circleCenter + rnd_unit_sfvector() * rnd_float(0.f, circleRadius);
	}

	sf::Vector2f rnd_point_on_torus(float innerRadius, float outerRadius, sf::Vector2f torusCenter) {
		return torusCenter + rnd_unit_sfvector() * rnd_float(innerRadius, outerRadius);
	}
#endif // USE_SFML
}
