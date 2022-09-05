#cmake_minimum_required(VERSION 3.21)
cmake_minimum_required(VERSION 3.16)

project("restapi-boilerplate" VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#find_package(oatpp REQUIRED)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# Include header files
include_directories(include)

# Include source files
set(SOURCES 
    #src/Publisher.cpp
)

add_executable(restapi-boilerplate main.cpp ${SOURCES})

# Link libraries
target_link_libraries(restapi-boilerplate 
    CONAN_PKG::oatpp
    #oatpp::oatpp
)
