#include "loadimage.h"

#include <string>
#include <iostream>

static EngineIOStream *s_iostream;

unsigned DLL_CALLCONV
FreeImageRead(void *buffer, unsigned size, unsigned count, fi_handle handle) {
    return s_iostream->read(buffer, size, count);
}

unsigned DLL_CALLCONV
FreeImageWrite(void *buffer, unsigned size, unsigned count, fi_handle handle) {
    return s_iostream->write(buffer, size, count);
}

int DLL_CALLCONV
FreeImageSeek(fi_handle handle, long offset, int origin) {
    switch (origin) {
        case SEEK_SET:
            return s_iostream->seek(offset, Origin_SET) ? 0 : 1;
            break;

        case SEEK_CUR:
            return s_iostream->seek(offset, Origin_CUR) ? 0 : 1;
            break;

        case SEEK_END:
            return s_iostream->seek(offset, Origin_END) ? 0 : 1;
            break;
    }
}

long DLL_CALLCONV
FreeImageTell(fi_handle handle) {
    return s_iostream->tell();
}

byte* loadImage(const char *path, int *width, int *height, uint *bits) {
    FIBITMAP *dib = NULL;
    FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

    s_iostream = new EngineIOStream(path);

    LOGD("GOT HERE");

    FreeImageIO *io = new FreeImageIO();
    io->read_proc = FreeImageRead;
    io->seek_proc = FreeImageSeek;
    io->tell_proc = FreeImageTell;
    io->write_proc = FreeImageWrite;

    fif = FreeImage_GetFileTypeFromHandle(io, 0);

    if (fif == FIF_UNKNOWN) {
        return nullptr;
    }
    if (FreeImage_FIFSupportsReading(fif)) {
        dib = FreeImage_LoadFromHandle(fif, io, 0);
    }

    if (!dib) LOGE("Could not load image %s!", path);

    byte *pixels = FreeImage_GetBits(dib);

    *width = FreeImage_GetWidth(dib);
    *height = FreeImage_GetHeight(dib);

    *bits = FreeImage_GetBPP(dib);

#ifdef ANDROID
    SwapRedBlue32(dib);
#endif

    int size = (*width) * (*height) * ((*bits) / 8);
    byte *result = new byte[size];
    memcpy(result, pixels, size);

    FreeImage_Unload(dib);
    return result;
}