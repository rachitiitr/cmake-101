file(GLOB ProtoFiles "*.proto")
message(STATUS "====> Entering ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "proto definition files: ${ProtoFiles}")
protobuf_generate_cpp(ProtoSources ProtoHeaders ${ProtoFiles})
message(STATUS "ProtoSources ${ProtoSources}")
message(STATUS "ProtoHeaders ${ProtoHeaders}")

add_library(myProtos ${ProtoSources} ${ProtoHeaders})
message(STATUS "<==== Leaving ${CMAKE_CURRENT_SOURCE_DIR}")
