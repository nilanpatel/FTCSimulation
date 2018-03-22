#include "vec4.h"

namespace lumos {

	vec4::vec4(float scalar) {
		this->x = scalar;
		this->y = scalar;
		this->z = scalar;
		this->w = scalar;
	}

	vec4::vec4(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4::vec4(const vec3 &xyz, float w) {
		this->x = xyz.x;
		this->y = xyz.y;
		this->z = xyz.z;
		this->w = w;
	}

	vec4& vec4::add(const vec4 &other) {
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	vec4& vec4::subtract(const vec4 &other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	vec4& vec4::multiply(const vec4 &other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	vec4& vec4::divide(const vec4 &other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
		return *this;
	}

	vec4& operator+(vec4 &left, const vec4 &right) {
		return left.add(right);
	}

	vec4& operator-(vec4 &left, const vec4 &right) {
		return left.subtract(right);
	}

	vec4& operator*(vec4 &left, const vec4 &right) {
		return left.multiply(right);
	}

	vec4& operator/(vec4 &left, const vec4 &right) {
		return left.divide(right);
	}

	vec4& vec4::operator+=(const vec4 &other) {
		*this = *this + other;
		return *this;
	}

	vec4& vec4::operator-=(const vec4 &other) {
		*this = *this - other;
		return *this;
	}

	vec4& vec4::operator*=(const vec4 &other) {
		*this = *this * other;
		return *this;
	}

	vec4& vec4::operator/=(const vec4 &other) {
		*this = *this / other;
		return *this;
	}

	bool vec4::operator==(const vec4& other) {
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	bool vec4::operator!=(const vec4& other) {
		return !(*this == other);
	}
}