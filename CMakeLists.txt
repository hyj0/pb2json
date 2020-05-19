#CMakeLists.txt
add_library(pb2json byReflection/pb2json.cpp)

include(FindProtobuf)

if (NOT PROTOBUF_PROTOC_EXECUTABLE)
    get_filename_component(PROTO_LIB_DIR ${PROTOBUF_LIBRARY} DIRECTORY)
    set (PROTOBUF_PROTOC_EXECUTABLE "${PROTO_LIB_DIR}/../bin/protoc")
endif()

protobuf_generate_cpp(PROTO_SRC PROTO_HEADER config.proto)
exec_program(${PROTOBUF_PROTOC_EXECUTABLE} ARGS  --cpp_out=${CMAKE_CURRENT_BINARY_DIR} --proto_path=${CMAKE_CURRENT_SOURCE_DIR}  ${CMAKE_CURRENT_SOURCE_DIR}/*.proto)

include_directories(${CMAKE_CURRENT_BINARY_DIR} byReflection)
add_executable(pb2json_repeat pb2json_repeat.cpp  ${PROTO_SRC} ${PROTO_HEADER})
target_link_libraries(pb2json_repeat pb2json   protobuf )


