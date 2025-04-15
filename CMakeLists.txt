cmake_minimum_required(VERSION 3.30)
project(landlord)

set(CMAKE_CXX_STANDARD 20)

add_executable(landlord main.cpp)

find_package(jsoncpp)
target_link_libraries(landlord JsonCpp::JsonCpp)

find_package(ZLIB)
target_link_libraries(landlord ZLIB::ZLIB)

find_package(OpenSSL)
target_link_libraries(landlord openssl::openssl)

find_package(Drogon)
target_link_libraries(landlord Drogon::Drogon)