set(CMAKE_CXX_STANDARD 20)
add_executable(day2 main.cpp)
#target_compile_options(day2 PUBLIC -Wall -Wpedantic -Wextra)
target_compile_options(day2 PUBLIC -march=native)