cmake_minimum_required(VERSION 3.10)
project(VulkanTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source and header files
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/include/*.h" "${CMAKE_SOURCE_DIR}/include/*.hpp")

# Add the executable
add_executable(VulkanTest ${SRC_FILES} ${HEADER_FILES})

# Add the include directory for your headers
target_include_directories(VulkanTest PRIVATE "${CMAKE_SOURCE_DIR}/include")

# ----------------------------
# GLFW Setup
# ----------------------------

# Prefer using system GLFW (Homebrew/vcpkg), fallback to subdirectory if needed
option(USE_SYSTEM_GLFW "Use system-installed GLFW" ON)

if(USE_SYSTEM_GLFW)
    find_package(glfw3 REQUIRED)
    target_link_libraries(VulkanTest PRIVATE glfw)
else()
    add_subdirectory(external/glfw)
    target_link_libraries(VulkanTest PRIVATE glfw)
endif()

# ----------------------------
# Vulkan Setup (Platform-specific)
# ----------------------------

if(WIN32)
    set(VULKAN_SDK_PATH "C:/VulkanSDK/1.3.243.0")  # Change this to your actual path

    set(Vulkan_INCLUDE_DIR "${VULKAN_SDK_PATH}/Include")
    set(Vulkan_LIBRARY_DIR "${VULKAN_SDK_PATH}/Lib")

    if(NOT EXISTS "${Vulkan_INCLUDE_DIR}/vulkan/vulkan.h")
        message(FATAL_ERROR "Vulkan header not found at: ${Vulkan_INCLUDE_DIR}/vulkan/vulkan.h")
    endif()

    find_library(Vulkan_LIBRARIES
        NAMES vulkan-1
        PATHS ${Vulkan_LIBRARY_DIR}
        REQUIRED
        NO_DEFAULT_PATH
    )

    message(STATUS "Using Vulkan SDK at: ${VULKAN_SDK_PATH}")
    target_include_directories(VulkanTest PRIVATE ${Vulkan_INCLUDE_DIR})
    target_link_libraries(VulkanTest PRIVATE ${Vulkan_LIBRARIES})

    # Copy Vulkan DLL after build
    add_custom_command(TARGET VulkanTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${VULKAN_SDK_PATH}/Bin/vulkan-1.dll"
            $<TARGET_FILE_DIR:VulkanTest>
        COMMENT "Copying Vulkan DLL to output directory"
    )

elseif(APPLE)
    set(Vulkan_SDK_PATH "/opt/homebrew")  # Or /usr/local on Intel Macs

    set(Vulkan_INCLUDE_DIR "${Vulkan_SDK_PATH}/include")
    set(Vulkan_LIBRARY_DIR "${Vulkan_SDK_PATH}/lib")

    find_path(Vulkan_INCLUDE_DIR
        NAMES vulkan/vulkan.h
        PATHS ${Vulkan_INCLUDE_DIR}
        REQUIRED
    )

    find_library(Vulkan_LIBRARIES
        NAMES vulkan
        PATHS ${Vulkan_LIBRARY_DIR}
        REQUIRED
    )

    message(STATUS "Using Vulkan SDK from: ${Vulkan_SDK_PATH}")
    target_include_directories(VulkanTest PRIVATE ${Vulkan_INCLUDE_DIR})
    target_link_libraries(VulkanTest PRIVATE ${Vulkan_LIBRARIES})

    # macOS system frameworks required by MoltenVK
    find_library(COCOA_LIBRARY Cocoa)
    find_library(METAL_LIBRARY Metal)
    find_library(QUARTZCORE_LIBRARY QuartzCore)

    target_link_libraries(VulkanTest PRIVATE
        ${COCOA_LIBRARY}
        ${METAL_LIBRARY}
        ${QUARTZCORE_LIBRARY}
    )

else()
    message(FATAL_ERROR "Unsupported platform")
endif()
