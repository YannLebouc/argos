cmake_minimum_required(VERSION 3.15)

# Base project name and language used 
project(basalt LANGUAGES CXX)

# Force the compiler to use the C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json for LSP compatibility (Helix, clangd, Neovim)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define static internal modules (one main file per module for now)
add_library(networking STATIC networking/networking.cpp)
add_library(storage STATIC storage/storage.cpp)
add_library(protocol STATIC protocol/protocol.cpp)

# Define the main executable
add_executable(server_app core/main.cpp)

# Link the internal modules to the main executable
target_link_libraries(server_app PRIVATE networking storage protocol)

# Allow include paths to look like: #include "networking/networking.hpp"
target_include_directories(server_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
