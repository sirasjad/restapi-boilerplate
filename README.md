# restapi-boilerplate
REST API boilerplate code using Drogon C++ HTTP Framework

## Build from source
```
mkdir build; cd build
conan install --settings build_type=Debug ..
cmake -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug
```
