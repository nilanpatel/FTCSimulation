#pragma once

#include "mat4.h"
#include "vec3.h"

#include "mathfunc.h"

#include "../types.h"

namespace lumos {

	struct Quaternion {
		float x, y, z, w;

		Quaternion();
		Quaternion(const Quaternion &quaternion);
		Quaternion(float x, float y, float z, float w);
		Quaternion(const vec3 &xyz, float w);
		Quaternion(const vec4 &vector);
		Quaternion(float scalar);

		Quaternion &operator=(const Quaternion &quaternion);

		Quaternion &setXYZ(const vec3 &vec);
		const vec3 getXYZ() const;

		Quaternion &setElement(uint idx, float value);
		float getElement(uint idx) const;
		vec3 getAxis() const;
		vec3 toEulerAngles() const;

		const Quaternion operator+(const Quaternion &Quaternion) const;
		const Quaternion operator-(const Quaternion &Quaternion) const;
		const Quaternion operator*(const Quaternion &Quaternion) const;
		const Quaternion operator*(float scalar) const;
		const Quaternion operator/(float scalar) const;
		float operator[](uint idx) const;

		Quaternion &operator+=(const Quaternion &Quaternion)
		{
			*this = *this + Quaternion;
			return *this;
		}

		Quaternion &operator-=(const Quaternion &Quaternion)
		{
			*this = *this - Quaternion;
			return *this;
		}

		Quaternion &operator*=(const Quaternion &Quaternion)
		{
			*this = *this * Quaternion;
			return *this;
		}

		Quaternion &operator*=(float scalar)
		{
			*this = *this * scalar;
			return *this;
		}

		Quaternion &operator/=(float scalar)
		{
			*this = *this / scalar;
			return *this;
		}

		const Quaternion operator-() const;
		bool operator==(const Quaternion &quaternion) const;
		bool operator!=(const Quaternion &quaternion) const;
		static Quaternion identity();
		static Quaternion fromEulerAngles(const vec3 &angles);

		static vec3 rotate(const Quaternion &quaternion, const vec3 &vector);

		static const Quaternion rotation(const vec3 &unitVector0, const vec3 &unitVector1);
		static const Quaternion rotation(float radians, const vec3 &unitVector);

		static const Quaternion rotationX(float radians)
		{
			float angle = radians * 0.5f;
			return Quaternion(sin(angle), 0.0f, 0.0f, cos(angle));
		}

		static const Quaternion rotationY(float radians)
		{
			float angle = radians * 0.5f;
			return Quaternion(0.0f, sin(angle), 0.0f, cos(angle));
		}

		static const Quaternion rotationZ(float radians)
		{
			float angle = radians * 0.5f;
			return Quaternion(0.0f, 0.0f, sin(angle), cos(angle));
		}

		float dot(const Quaternion &other) const;
		Quaternion conjugate() const;

	};

}