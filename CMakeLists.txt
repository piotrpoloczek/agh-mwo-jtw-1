cmake_minimum_required(VERSION 3.24)
project(agh_mwo_jtw_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(agh_mwo_jtw_1
        main.cpp
        rational/Rational.cpp
)

target_include_directories(agh_mwo_jtw_1 PRIVATE rational)
