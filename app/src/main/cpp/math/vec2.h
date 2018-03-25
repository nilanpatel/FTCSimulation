#pragma once

#include <math.h>

#include "vec3.h"

struct vec2 {
	float x, y;

	vec2();
	vec2(float scalar);
	vec2(float x, float y);
	vec2(const vec3 &vector);

	vec2& add(const vec2 &other);
	vec2& subtract(const vec2 &other);
	vec2& multiply(const vec2 &other);
	vec2& divide(const vec2 &other);

	friend vec2& operator+(vec2 &left, const vec2 &right);
	friend vec2& operator-(vec2 &left, const vec2 &right);
	friend vec2& operator*(vec2 &left, const vec2 &right);
	friend vec2& operator/(vec2 &left, const vec2 &right);


	bool operator==(const vec2& other);
	bool operator!=(const vec2& other);

	vec2& operator+=(const vec2 &other);
	vec2& operator-=(const vec2 &other);
	vec2& operator*=(const vec2 &other);
	vec2& operator/=(const vec2 &other);

	float magnitude() const;
	vec2 normalize() const;
	float distance(const vec2 &other) const;
	float dot(const vec2 &other) const;

};