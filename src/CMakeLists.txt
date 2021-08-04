cmake_minimum_required(VERSION 3.2)
project(MyApp)

add_subdirectory(vendor/nlohmann)
# find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(myExe main.cpp utils/math.cpp)

target_link_libraries(myExe PRIVATE nlohmann_json::nlohmann_json)


