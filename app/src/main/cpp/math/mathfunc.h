#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

struct MathFunctions {
public:

	static inline float degrees_to_radians(float degrees) {
		return (float) ((M_PI / 180) * degrees);
	}

	static inline float radians_to_degrees(float radians) {
		return (float) ((180 / M_PI) * radians);
	}

	static inline int sign(float value) {
		return (value > 0) - (value < 0);
	}

	static float q_rsqrt(float number)
	{
		long i;
		float x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long *)&y;                       // evil floating point bit level hacking
		i = 0x5f3759df - (i >> 1);               // what the fuck? 
		y = *(float *)&i;
		y = y * (threehalfs - (x2 * y * y));   // 1st iteration
											   //	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

		return y;
	}

	static float s_rsqrt(float number) {
		return (1.0f / sqrt(number));
	}
		 
};
