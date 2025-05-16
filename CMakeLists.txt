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
        BieuDo.cc
        lease.cc
        rooms.cc
)

find_package(Drogon CONFIG REQUIRED)
target_link_libraries(landlord PRIVATE Drogon::Drogon)

set(VIEW_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/generated_views")

# Gọi hàm với đủ 3 tham số bắt buộc
drogon_create_views(landlord
        "${CMAKE_CURRENT_SOURCE_DIR}/views"
        ${VIEW_OUTPUT_PATH}
)

find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(landlord PRIVATE unofficial::sqlite3::sqlite3)
