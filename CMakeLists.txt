#cmake_minimum_required(VERSION 3.21)
cmake_minimum_required(VERSION 3.16)

project("restapi-boilerplate" VERSION 1.0.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# Include header files
include_directories(include)

# Include source files
set(SOURCES 
    src/test.cpp
    src/service/MongoDbHandler.cpp
)

add_executable(restapi-boilerplate src/main.cpp ${SOURCES})

target_link_libraries(restapi-boilerplate 
    CONAN_PKG::drogon
    CONAN_PKG::mongo-cxx-driver
)
