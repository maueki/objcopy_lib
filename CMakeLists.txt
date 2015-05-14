cmake_minimum_required(VERSION 2.8)

project(objcopy_test)

add_executable(test1 test.cpp)
add_executable(test2 test.cpp)

add_custom_command(OUTPUT test_data.o
  COMMAND objcopy --input binary --output elf64-x86-64 -B i386 test.data ${CMAKE_CURRENT_BINARY_DIR}/test_data.o
  DEPENDS test.data
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )

set_source_files_properties(
  test_data.o
  PROPERTIES
  EXTERNAL_OBJECT true
  GENERATED true
  )

add_library(test_static STATIC func.cpp test_data.o)
add_library(test_shared SHARED func.cpp test_data.o)

#set_target_properties(
#  test_shared
#  PROPERTIES
#  LINK_FLAGS
#  "-Wl,-Bsymbolic"
#  )

target_link_libraries(test1 test_static)
target_link_libraries(test2 test_shared)

set(CMAKE_CXX_FLAGS "-g")
