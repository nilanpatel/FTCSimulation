#pragma once

#include <FreeImage.h>
#include <FreeImage/Utilities.h>

#include "../types.h"
#include "../system/console.h"
#include "engineiostream.h"

byte* loadImage(const char *path, int *width, int *height, uint *bits);

