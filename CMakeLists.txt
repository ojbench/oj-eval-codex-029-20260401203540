cmake_minimum_required(VERSION 3.10)
project(problem_029_malloc C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(code src/main.c)

# Be strict about warnings in local builds
if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(code PRIVATE -Wall -Wextra -Werror)
endif()
