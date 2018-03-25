cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fms-extensions")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -Wall")

add_library(
                # Sets the name of the library.
                FTCSimulation

                # Sets the library as a shared library.
                SHARED

                src/main/cpp/types.h

                # application
                src/main/cpp/application/application.h
                src/main/cpp/application/application.cpp

                # graphics
                src/main/cpp/graphics/renderers/renderer2d.h
                src/main/cpp/graphics/renderers/renderer2d.cpp
                src/main/cpp/graphics/common.h
                src/main/cpp/graphics/error.cpp

                # math
                src/main/cpp/math/mat4.h
                src/main/cpp/math/mat4.cpp
                src/main/cpp/math/quaternion.h
                src/main/cpp/math/quaternion.cpp
                src/main/cpp/math/vec2.h
                src/main/cpp/math/vec2.cpp
                src/main/cpp/math/vec3.h
                src/main/cpp/math/vec3.cpp
                src/main/cpp/math/vec4.h
                src/main/cpp/math/vec4.cpp

                # system
                src/main/cpp/system/console.h
                src/main/cpp/system/timer.h
                src/main/cpp/system/loadimage.h
                src/main/cpp/system/loadimage.cpp
                src/main/cpp/system/engineiostream.h
                src/main/cpp/system/engineiostream.cpp
                src/main/cpp/system/androidassetmanager.h
                src/main/cpp/system/androidassetmanager.cpp

                # freetype-gl
                ext/freetype-gl/distance-field.c
                ext/freetype-gl/distance-field.h
                ext/freetype-gl/edtaa3func.c
                ext/freetype-gl/edtaa3func.h
                ext/freetype-gl/font-manager.c
                ext/freetype-gl/font-manager.h
                ext/freetype-gl/freetype-gl.h
                ext/freetype-gl/markup.h
                ext/freetype-gl/opengl.h
                ext/freetype-gl/platform.h
                ext/freetype-gl/platform.c
                ext/freetype-gl/texture-atlas.c
                 ext/freetype-gl/texture-atlas.h
                ext/freetype-gl/texture-font.c
                ext/freetype-gl/texture-font.h
                ext/freetype-gl/utf8-utils.c
                ext/freetype-gl/utf8-utils.h
                ext/freetype-gl/vec234.h
                ext/freetype-gl/vector.c
                ext/freetype-gl/vector.h
                ext/freetype-gl/vertex-attribute.c
                ext/freetype-gl/vertex-attribute.h
                ext/freetype-gl/vertex-buffer.c
                ext/freetype-gl/vertex-buffer.h
             )

 include_directories(
                src/main/cpp/
                ../dependencies/FreeImage/include/
                ../dependencies/freetype/include/ )

add_library(freetype-lib STATIC IMPORTED)
set_target_properties(freetype-lib PROPERTIES IMPORTED_LOCATION
    ${CMAKE_SOURCE_DIR}/../dependencies/freetype/lib/${ANDROID_ABI}/libfreetype2-static.a)

add_library(cpufeatures-lib STATIC IMPORTED)
    set_target_properties(cpufeatures-lib PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../dependencies/FreeImage/lib/${ANDROID_ABI}/libcpufeatures.a)

add_library(FreeImage-lib STATIC IMPORTED)
    set_target_properties(FreeImage-lib PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../dependencies/FreeImage/lib/${ANDROID_ABI}/libFreeImage.a)

 find_library(log-lib log)

 target_link_libraries( # Specifies the target library.
                        FTCSimulation

                        EGL
                        GLESv2
                        android

                        freetype-lib

                        cpufeatures-lib
                        FreeImage-lib

                        # Links the target library to the log library
                        # included in the NDK.

                        ${log-lib} )