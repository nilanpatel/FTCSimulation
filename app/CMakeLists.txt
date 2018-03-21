cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -Wall")

add_library(
                # Sets the name of the library.
                FTCSimulation

                # Sets the library as a shared library.
                SHARED

                # graphics
                src/main/cpp/graphics/renderer2d.h
                src/main/cpp/graphics/renderer2d.cpp
             )

 include_directories(src/main/cpp/)

 find_library(log-lib log)

 target_link_libraries( # Specifies the target library.
                        FTCSimulation
                        EGL
                        GLESv2
                        android
                        # Links the target library to the log library
                        # included in the NDK.
                        ${log-lib} )