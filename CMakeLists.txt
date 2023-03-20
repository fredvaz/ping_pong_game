cmake_minimum_required(VERSION 3.16)

# project name
project(ping_pong_game VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# Set varaibles names
#set(LIBRARY_NAME library)
set(MAIN_APP main_app)

include(FetchContent)
FetchContent_Declare(
   SFML
  GIT_REPOSITORY https://github.com/SFML/SFML
   GIT_TAG 2.5.1)

FetchContent_MakeAvailable(SFML)

#add_subdirectory(src)
add_subdirectory(app)