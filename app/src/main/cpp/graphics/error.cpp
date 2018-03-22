#include "common.h"

#include "../system/console.h"

bool GLLogCall(const char* function) {
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		LOGD("[OpenGL Error] (%u): %s\n", error, function);
		return false;
	}
	
	return true;
}