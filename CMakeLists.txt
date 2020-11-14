# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(mempool)

# creates the variable EXEC and sets it to hello
set(EXEC mempool)

# set the C++14 standard
set(CMAKE_CXX_STANDARD 14)

# I../includes
include_directories(includes)



# puts all .cpp files inside src to the SOURCES variable
file(GLOB_RECURSE SOURCES .src/*.cpp .src/*.hpp ./src/main.cpp)

# compiles the files defined by SOURCES to generante the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})


