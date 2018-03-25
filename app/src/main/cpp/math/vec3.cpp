#include "vec3.h"
#include "vec2.h"
#include "vec4.h"

vec3::vec3() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

vec3::vec3(float scalar) {
	this->x = scalar;
	this->y = scalar;
	this->z = scalar;
}

vec3::vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

vec3::vec3(const vec2 &other) {
	this->x = other.x;
	this->y = other.y;
	this->z = 0.0f;
}

vec3::vec3(float x, float y) {
	this->x = x;
	this->y = y;
	this->z = 0.0f;
}

vec3::vec3(const vec4 &other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

vec3& vec3::add(const vec3 &other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

vec3& vec3::subtract(const vec3 &other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

vec3& vec3::multiply(const vec3 &other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	return *this;
}

vec3& vec3::divide(const vec3 &other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	return *this;
}
vec3& vec3::add(float other)
{
	x += other;
	y += other;
	z += other;

	return *this;
}

vec3& vec3::subtract(float other)
{
	x -= other;
	y -= other;
	z -= other;

	return *this;
}

vec3& vec3::multiply(float other)
{
	x *= other;
	y *= other;
	z *= other;

	return *this;
}

vec3& vec3::divide(float other)
{
	x /= other;
	y /= other;
	z /= other;

	return *this;
}


vec3& operator+(vec3 &left, const vec3 &right) {
	return left.add(right);
}

vec3& operator-(vec3 &left, const vec3 &right) {
	return left.subtract(right);
}

vec3& operator*(vec3 &left, const vec3 &right) {
	return left.multiply(right);
}

vec3& operator/(vec3 &left, const vec3 &right) {
	return left.divide(right);
}

vec3 operator+(vec3 left, float right) {
	return left.add(right);
}

vec3 operator-(vec3 left, float right) {
	return left.subtract(right);
}

vec3 operator*(vec3 left, float right) {
	return left.multiply(right);
}

vec3 operator/(vec3 left, float right) {
	return left.divide(right);
}

vec3& vec3::operator+=(const vec3 &other) {
	*this = *this + other;
	return *this;
}

vec3& vec3::operator-=(const vec3 &other) {
	*this = *this - other;
	return *this;
}

vec3& vec3::operator*=(const vec3 &other) {
	*this = *this * other;
	return *this;
}

vec3& vec3::operator/=(const vec3 &other) {
	*this = *this / other;
	return *this;
}

bool vec3::operator==(const vec3& other) {
	return x == other.x && y == other.y && z == other.z;
}

bool vec3::operator!=(const vec3& other) {
	return !(*this == other);
}

float vec3::distance(const vec3 &other) const {
	float a = x - other.x;
	float b = y - other.y;
	float c = z - other.z;
	return sqrt(a * a + b * b + c * c);
}

float vec3::dot(const vec3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

vec3 vec3::cross(const vec3& other) const
{
	return vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

vec3 vec3::normalize() const {
	float magnitude = sqrt((x * x) + (y * y) + (z * z));
	return vec3(x / magnitude, y / magnitude, z / magnitude);
}