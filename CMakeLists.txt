cmake_minimum_required(VERSION 3.30)
project(landlord)

set(CMAKE_CXX_STANDARD 20)

add_executable(landlord
        main.cpp
        MessageHandler.cc
        SumController.cc
        TanController.cc
        TestCtrl.cc
)


find_package(fmt CONFIG REQUIRED)
target_link_libraries(landlord PRIVATE fmt::fmt)

find_package(Drogon CONFIG REQUIRED)
target_link_libraries(landlord PRIVATE Drogon::Drogon)