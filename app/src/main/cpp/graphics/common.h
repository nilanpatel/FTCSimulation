#pragma once

#include <GLES2/gl2.h>

#include "../system/console.h"

extern bool GLCheckError(const char* function);

#define GLCall(x) GLCheckError(#x);\
		x;