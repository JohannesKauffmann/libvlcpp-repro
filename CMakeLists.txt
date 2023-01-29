cmake_minimum_required(VERSION 3.14)

project(libvlcpp-repo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${CMAKE_PROJECT_NAME}
    main.cpp)

target_include_directories(${CMAKE_PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/libvlcpp")

set(libvlc_sdk_dir "${CMAKE_CURRENT_SOURCE_DIR}/libvlc_sdk")
target_include_directories(${CMAKE_PROJECT_NAME}
    PRIVATE
        ${libvlc_sdk_dir}/include)
if(WIN32)
    if(MINGW)
        target_link_libraries(${CMAKE_PROJECT_NAME}
            PRIVATE
                ${libvlc_sdk_dir}/lib/libvlc.dll
                ${libvlc_sdk_dir}/lib/libvlccore.dll)
    elseif(MSVC)
        target_link_libraries(${CMAKE_PROJECT_NAME}
                PRIVATE
                    ${libvlc_sdk_dir}/lib/libvlc.lib
                    ${libvlc_sdk_dir}/lib/libvlccore.lib)
    endif()
    file(COPY ${libvlc_sdk_dir}/lib/libvlc.dll ${libvlc_sdk_dir}/lib/libvlccore.dll
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
else()
    target_link_libraries(${CMAKE_PROJECT_NAME}
        PRIVATE
            vlc)
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/video.mp4
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
