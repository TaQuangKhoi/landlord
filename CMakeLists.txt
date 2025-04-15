cmake_minimum_required(VERSION 3.30)
project(land_lord)

set(CMAKE_CXX_STANDARD 20)

add_executable(land_lord main.cpp)

find_package(jsoncpp)
target_link_libraries(land_lord JsonCpp::JsonCpp)

find_package(ZLIB)
target_link_libraries(land_lord ZLIB::ZLIB)

find_package(OpenSSL)
target_link_libraries(land_lord openssl::openssl)

find_package(Drogon)
target_link_libraries(land_lord Drogon::Drogon)