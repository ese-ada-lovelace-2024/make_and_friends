cmake_minimum_required(VERSION 3.10)

# set the project name (and the name f)
project(MPIHelloWorld)

# add the executable
add_executable(hello2 main.cpp)

find_package(MPI REQUIRED)

target_include_directories(hello2 PUBLIC ${MPI_INCLUDE_PATH})
target_link_libraries(hello2 ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
  set_target_properties(hello2 PROPERTIES
    COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
  set_target_properties(hello2 PROPERTIES
    LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()