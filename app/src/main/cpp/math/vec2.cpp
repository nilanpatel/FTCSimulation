#include "vec2.h"

vec2::vec2() {
	this->x = 0.0f;
	this->y = 0.0f;
}

vec2::vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

vec2::vec2(float scalar) {
	this->x = scalar;
	this->y = scalar;
}

vec2::vec2(const vec3 &vector) {
	this->x = vector.x;
	this->y = vector.y;
}

vec2& vec2::add(const vec2 &other) {
	x += other.x;
	y += other.y;
	return *this;
}

vec2& vec2::subtract(const vec2 &other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

vec2& vec2::multiply(const vec2 &other) {
	x *= other.x;
	y *= other.y;
	return *this;
}

vec2& vec2::divide(const vec2 &other) {
	x /= other.x;
	y /= other.y;
	return *this;
}

vec2& operator+(vec2 &left, const vec2 &right) {
	return left.add(right);
}

vec2& operator-(vec2 &left, const vec2 &right) {
	return left.subtract(right);
}

vec2& operator*(vec2 &left, const vec2 &right) {
	return left.multiply (right);
}

vec2& operator/(vec2 &left, const vec2 &right) {
	return left.divide(right);
}

vec2& vec2::operator+=(const vec2 &other) {
	*this = *this + other;
	return *this;
}

vec2& vec2::operator-=(const vec2 &other) {
	*this = *this - other;
	return *this;
}

vec2& vec2::operator*=(const vec2 &other) {
	*this = *this * other;
	return *this;
}

vec2& vec2::operator/=(const vec2 &other) {
	*this = *this / other;
	return *this;
}

bool vec2::operator==(const vec2& other) {
	return x == other.x && y == other.y;
}

bool vec2::operator!=(const vec2& other) {
	return !(*this == other);
}

float vec2::magnitude() const {
	return sqrt(x * x + y * y);
}

vec2 vec2::normalize() const {
	float length = magnitude();
	return vec2(x / length, y / length);
}

float vec2::distance(const vec2 &other) const {
	float a = x - other.x;
	float b = y - other.y;
	return sqrt(a * a + b * b);
}

float vec2::dot(const vec2 &other) const {
	return x * other.x + y * other.y;
}