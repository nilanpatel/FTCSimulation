#pragma once

#include <GLES2/gl2.h>
#include <stdio.h>

#include "../../types.h"
#include "../common.h"

#include "../../math/vec4.h"

#include "../../system/loadimage.h"

class Renderer2D {
private:
    vec4 m_clearColor;
public:
	Renderer2D();
	~Renderer2D();

    void initialize();

	void setClearColor(const vec4 &color);
    void clear();

    void setViewport(uint x, uint y, uint width, uint height);
};