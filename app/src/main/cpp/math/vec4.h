#pragma once

#include "vec3.h"

struct vec4 {
	float x, y, z, w;

	vec4() = default;
	vec4(float scalar);
	vec4(float x, float y, float z, float w);
	vec4(const vec3 &xyz, float w);

	vec4& add(const vec4 &other);
	vec4& subtract(const vec4 &other);
	vec4& multiply(const vec4 &other);
	vec4& divide(const vec4 &other);

	friend vec4& operator+(vec4 &left, const vec4 &right);
	friend vec4& operator-(vec4 &left, const vec4 &right);
	friend vec4& operator*(vec4 &left, const vec4 &right);
	friend vec4& operator/(vec4 &left, const vec4 &right);


	bool operator==(const vec4& other);
	bool operator!=(const vec4& other);

	vec4& operator+=(const vec4 &other);
	vec4& operator-=(const vec4 &other);
	vec4& operator*=(const vec4 &other);
	vec4& operator/=(const vec4 &other);
};

