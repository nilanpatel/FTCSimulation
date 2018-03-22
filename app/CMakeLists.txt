cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -Wall")

add_library(
                # Sets the name of the library.
                FTCSimulation

                # Sets the library as a shared library.
                SHARED

                src/main/cpp/types.h

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
                src/main/cpp/math/mathfunc.h

                # system
                src/main/cpp/system/console.h
             )

 include_directories(src/main/cpp/ dependencies/FreeImage/include)

 find_library(log-lib log)

 target_link_libraries( # Specifies the target library.
                        FTCSimulation
                        EGL
                        GLESv2
                        android
                        # Links the target library to the log library
                        # included in the NDK.
                        ${log-lib} )