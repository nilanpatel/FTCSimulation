#pragma once

namespace lumos {

	struct vec2;
	struct vec4;

	struct vec3 {
		float x, y, z;

		vec3();
		vec3(float scalar);
		vec3(float x, float y, float z);
		vec3(const vec2 &other);
		vec3(float x, float y);
		vec3(const vec4 &other);

		vec3& add(const vec3 &other);
		vec3& subtract(const vec3 &other);
		vec3& multiply(const vec3 &other);
		vec3& divide(const vec3 &other);

		vec3& add(float other);
		vec3& subtract(float other);
		vec3& multiply(float other);
		vec3& divide(float other);

		friend vec3& operator+(vec3 &left, const vec3 &right);
		friend vec3& operator-(vec3 &left, const vec3 &right);
		friend vec3& operator*(vec3 &left, const vec3 &right);
		friend vec3& operator/(vec3 &left, const vec3 &right);

		friend vec3 operator+(vec3 left, float right);
		friend vec3 operator-(vec3 left, float right);
		friend vec3 operator*(vec3 left, float right);
		friend vec3 operator/(vec3 left, float right);

		bool operator==(const vec3& other);
		bool operator!=(const vec3& other);

		vec3& operator+=(const vec3 &other);
		vec3& operator-=(const vec3 &other);
		vec3& operator*=(const vec3 &other);
		vec3& operator/=(const vec3 &other);

		float distance(const vec3 &other) const;

		float dot(const vec3& other) const;
		vec3 cross(const vec3& other) const;

		vec3 normalize() const;
	};
}

