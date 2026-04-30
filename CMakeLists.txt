cmake_minimum_required(VERSION 3.10)

project(DeferredQueueApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(app
    main.cpp
    Person.cpp
    Student.cpp
    Teacher.cpp
    Diary.cpp
    School.cpp
)
