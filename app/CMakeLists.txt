
# MAIN_APP CMakeLists.txt

add_executable(main_app main.cpp)
target_link_libraries(main_app PRIVATE sfml-graphics sfml-system sfml-window)