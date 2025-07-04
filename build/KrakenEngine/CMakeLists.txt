cmake_minimum_required(VERSION 3.8)
project(SFMLTest)

set(CMAKE_CXX_STANDARD 17)

# Set the SFML directory
set(SFML_DIR "/opt/homebrew/opt/sfml/lib/cmake/SFML")

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(SFMLTest src/main.cpp)
target_link_libraries(SFMLTest sfml-graphics sfml-window sfml-system)
