set(CMAKE_CXX_STANDARD 20)
add_executable(day3 main.cpp)
target_compile_options(day3 PUBLIC -Wall -Wpedantic -Wextra)
#target_compile_options(day3 PUBLIC -march=native)