cmake_minimum_required(VERSION 3.5)
project(TH_TE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -std=c++11")

set(SOURCE_FILES
    main.cpp
    parser.h
    save.h
    thsys.h
    todorf.h
    tohaus.hpp
    user.th)

add_executable(TH_TE ${SOURCE_FILES})