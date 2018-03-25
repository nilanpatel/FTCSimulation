#pragma once

#include <stdio.h>
#include <string.h>
#include <cmath>

#include "vec3.h"
#include "vec4.h"

struct Quaternion;

struct mat4 {

	union {
		float elements[4 * 4];
		vec4 columns[4];
	};

	mat4();
	mat4(float diagonal);
	mat4(float *elements);
	mat4(const vec4& column0, const vec4& column1, const vec4& column2, const vec4& column3);

	static mat4 identity();

	mat4& multiply(const mat4& other);
	mat4& operator*=(const mat4& other);
	friend mat4 operator*(mat4 left, const mat4 &right);

	vec3 multiply(const vec3& other) const;
	friend vec3 operator*(const mat4& left, const vec3& right);

	vec4 multiply(const vec4& other) const;
	friend vec4 operator*(const mat4& left, const vec4& right);

	mat4 &invert();

	static const mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
	static const mat4 perspective(float fov_degrees, float aspect_ratio, float near, float far);

	static mat4 translation(const vec3& translation);
	static mat4 rotation(float angle_degrees, const vec3& axis);
	static mat4 rotation(const Quaternion& quat);
	static mat4 scale(const vec3& scalar);
	static mat4 invert(const mat4 &matrix);
	static mat4 transpose(const mat4& matrix);
};