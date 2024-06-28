cmake_minimum_required(VERSION 3.27)
project(VxGui LANGUAGES C CXX)

add_library(vxgui)

target_sources(vxgui PUBLIC
vxgui.hpp
vxgui_logical.cpp
)

add_subdirectory(submodules)
add_subdirectory(backends)

target_link_libraries(vxgui PUBLIC cglm freetype)

include(CTest)
enable_testing()

