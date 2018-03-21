#pragma once

#include <GLES2/gl2.h>

class Renderer2D {
public:
	Renderer2D();
	~Renderer2D();

	void create();

	void change(int width, int height);

	void render();
};