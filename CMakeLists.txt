cmake_minimum_required(VERSION 3.8)
project(VulkanTest)

set(CMAKE_CXX_STANDARD 17)

# Platform-specific Vulkan setup
if(WIN32)
    # Always use your explicit path first
    set(VULKAN_SDK_PATH "C:/VulkanSDK/1.4.313.2")
    
    # Set include and lib paths
    set(Vulkan_INCLUDE_DIR "${VULKAN_SDK_PATH}/Include")
    set(Vulkan_LIBRARY "${VULKAN_SDK_PATH}/Lib/vulkan-1.lib")
    
    # Verify path exists
    if(NOT EXISTS "${Vulkan_INCLUDE_DIR}/vulkan/vulkan.h")
        message(FATAL_ERROR "Vulkan header not found at: ${Vulkan_INCLUDE_DIR}/vulkan/vulkan.h")
    endif()
    
elseif(APPLE)
    # macOS: Use Homebrew paths
    set(Vulkan_INCLUDE_DIR "/opt/homebrew/include")
    set(Vulkan_LIBRARY "/opt/homebrew/lib/libvulkan.dylib")
    
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

# Find Vulkan components
find_path(Vulkan_INCLUDE_DIRS
    NAMES vulkan/vulkan.h
    PATHS ${Vulkan_INCLUDE_DIR}
    REQUIRED
)

find_library(Vulkan_LIBRARIES
    NAMES vulkan
    PATHS ${Vulkan_LIBRARY}
    REQUIRED
)

add_executable(VulkanTest src/main.cpp)
target_include_directories(VulkanTest PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(VulkanTest PRIVATE ${Vulkan_LIBRARIES})

# macOS-specific frameworks
if(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(METAL_LIBRARY Metal)
    find_library(QUARTZCORE_LIBRARY QuartzCore)
    target_link_libraries(VulkanTest PRIVATE
        ${COCOA_LIBRARY}
        ${METAL_LIBRARY}
        ${QUARTZCORE_LIBRARY}
    )
endif()

# Additional Windows-specific setup
if(WIN32)
    # Automatically copy Vulkan DLL to build directory
    add_custom_command(TARGET VulkanTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${VULKAN_SDK_PATH}/Bin/vulkan-1.dll"
            $<TARGET_FILE_DIR:VulkanTest>
        COMMENT "Copying Vulkan DLL to output directory"
    )
    
    # Set runtime library configuration
    set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
    )
    foreach(CompilerFlag ${CompilerFlags})
        string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    endforeach()
endif()