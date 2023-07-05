cmake_minimum_required(VERSION 3.25)
project(OOKFormatCalculate)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(OOKFormatCalculate
        src/Algo226x.cpp
        src/Algo226x.h
        src/Algo1527_2242.cpp
        src/Algo1527_2242.h
        src/Interface.cpp
        src/Interface.h
        src/processUnit.cpp
        src/processUnit.h
        src/AlgoGeneral.h
        src/AlgoGeneral.cpp
        src/main.h
        src/main.cpp)
