cmake_minimum_required(VERSION 2.8)

project(fdfs_client)
add_compile_options(-std=c++17 -fpermissive)
INCLUDE_DIRECTORIES(/usr/include/fastcommon /usr/include/fastdfs)
LINK_DIRECTORIES(/home/whl/Documents/qtproject/fdfs_client/json/lib)
find_package(spdlog REQUIRED)
aux_source_directory(. Client_Sources)
add_executable(${PROJECT_NAME} ${Client_Sources})
target_link_libraries(${PROJECT_NAME} spdlog::spdlog_header_only fdfsclient fastcommon)
