cmake_minimum_required(VERSION 3.7)
project(libft C)
set(CMAKE_C_STANDARD 11)

# Add c files of project root directory as source file
file(GLOB_RECURSE SOURCE_FILES srcs/**.c)
file(GLOB HEADER_FILES "include/*.h")

include_directories(include)
add_library(ft ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(ft PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(ft PUBLIC libft)
