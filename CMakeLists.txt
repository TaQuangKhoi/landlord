cmake_minimum_required(VERSION 3.30)
project(landlord)

set(CMAKE_CXX_STANDARD 20)

add_executable(landlord
        main.cpp
        MessageHandler.cc
        SumController.cc
        TanController.cc
        TestCtrl.cc
        admin/User.cc
)

find_package(Drogon CONFIG REQUIRED)
target_link_libraries(landlord PRIVATE Drogon::Drogon)

find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(landlord PRIVATE unofficial::sqlite3::sqlite3)
