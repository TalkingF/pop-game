# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

cmake_minimum_required(VERSION 3.15)
project(pop-game)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the installation directory
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

# Add your libraries and include directories
add_subdirectory(lib/raylib)

include_directories(
    lib/raylib/src
    lib/raygui/src
)

file(GLOB_RECURSE SRCS src/*.cpp)

set(PROJECT_NAME_LIB ${PROJECT_NAME}_lib)
add_library(${PROJECT_NAME_LIB} STATIC ${SRCS} "src/Game.cpp")

add_executable(${PROJECT_NAME} "src/main.cpp" "src/Entity.cpp" "src/Game.cpp")

target_include_directories(${PROJECT_NAME_LIB} PUBLIC
    lib/raylib/src
    lib/raygui/src
)

target_link_libraries(${PROJECT_NAME}
    ${PROJECT_NAME_LIB}
    raylib

)


