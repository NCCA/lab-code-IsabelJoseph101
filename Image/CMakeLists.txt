# We will always try to use a version > 3.1 if avaliable
cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

# name of the project It is best to use something different from the exe name
project(Image_build) 

# Here we set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
include_directories(include)

# Now we add our target executable and the file it is built from.
add_executable(Image)
# We now add the source files we want for the project. for now we are going to just add main.cpp
# See here for more details https://crascit.com/2016/01/31/enhanced-source-file-handling-with-target_sources/
target_sources(Image PRIVATE src/main.cpp src/Image.cpp)

# testing code
find_package(GTest CONFIG REQUIRED)
add_executable(ImageTests)
target_sources(ImageTests PRIVATE test/ImageTests.cpp
                                    test/RGBATests.cpp
                                    include/RGBA.h
                                    src/Image.cpp)
target_link_libraries(ImageTests PRIVATE GTest::gtest GTest::gtest_main)    