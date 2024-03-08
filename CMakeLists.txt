cmake_minimum_required(VERSION 3.21)

# Project settings
set(PROJECT_NAME "restapi-boilerplate")
set(PROJECT_VERSION 1.0.0)

set(EXECUTABLE_NAME ${PROJECT_NAME})
set(LIBRARY_NAME ${PROJECT_NAME}-lib)
set(UNIT_TEST_NAME ${PROJECT_NAME}-test)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)

# Packages
find_package(Boost REQUIRED)
find_package(Drogon CONFIG REQUIRED)
find_package(mongocxx CONFIG REQUIRED)
find_package(bsoncxx CONFIG REQUIRED)

# Include header files
include_directories(include)

# Include source files
set(SOURCES 
    src/Service/HttpServer.cpp
    src/Service/MongoDb.cpp
    src/Endpoint/UserController.cpp
)

add_library(${LIBRARY_NAME} SHARED ${SOURCES})
add_executable(${EXECUTABLE_NAME} src/main.cpp ${SOURCES})

# Shared library
target_link_libraries(${LIBRARY_NAME} 
    Boost::boost
    Drogon::Drogon
    $<IF:$<TARGET_EXISTS:mongo::mongocxx_static>,mongo::mongocxx_static,mongo::mongocxx_shared>
    $<IF:$<TARGET_EXISTS:mongo::bsoncxx_static>,mongo::bsoncxx_static,mongo::bsoncxx_shared>
)

target_compile_definitions(${LIBRARY_NAME} PUBLIC
    DLL_EXPORTS
)

# Executable
target_link_libraries(${EXECUTABLE_NAME} 
    ${LIBRARY_NAME}
)
