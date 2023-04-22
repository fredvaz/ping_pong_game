
# MAIN_APP CMakeLists.txt

add_executable(main_app main.cpp entity.cpp background.cpp ball.cpp paddle.cpp interactions.cpp brick.cpp)
target_link_libraries(main_app PRIVATE sfml-graphics sfml-system sfml-window)