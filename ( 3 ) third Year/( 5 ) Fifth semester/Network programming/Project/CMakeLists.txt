cmake_minimum_required(VERSION 3.16)
project(ImageRedactor LANGUAGES CXX)

# Image Editor Client
add_executable(image_redactor_client
    main.cpp
)

target_compile_features(image_redactor_client PRIVATE cxx_std_20)

target_include_directories(image_redactor_client PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/ImageProcessing
)

# Image Editor Server
add_executable(image_redactor_server
    server/main.cpp
)

target_compile_features(image_redactor_server PRIVATE cxx_std_20)

target_include_directories(image_redactor_server PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/ImageProcessing
    ${CMAKE_CURRENT_SOURCE_DIR}/server
)

