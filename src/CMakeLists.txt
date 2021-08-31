cmake_minimum_required(VERSION 3.2)
project(MyApp)

find_package(Protobuf REQUIRED)

# or you can also do include(protos/protos.cmake)
# but add_subdirectory will follow the folder structure in build directory
add_subdirectory(protos)

add_subdirectory(vendor/nlohmann)
# find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(myExe main.cpp utils/math.cpp)
target_link_libraries(myExe PRIVATE
    nlohmann_json::nlohmann_json
    myProtos
    ${PROTOBUF_LIBRARY}
)
target_include_directories(myExe PRIVATE 
    ${CMAKE_BINARY_DIR}/protos
)


