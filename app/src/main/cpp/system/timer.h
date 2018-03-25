#pragma once

#include <chrono>

class Timer {
private:
	typedef std::chrono::high_resolution_clock h_clock;
	typedef std::chrono::duration<float, std::milli> millisecond_type;
	std::chrono::time_point<h_clock> m_start;

public:
	Timer() {
		reset();
	}

	void reset() {
		m_start = h_clock::now();
	}

	float elapsed() {
		return std::chrono::duration_cast<millisecond_type>(h_clock::now() - m_start).count() / 1000.0f;
	}
};