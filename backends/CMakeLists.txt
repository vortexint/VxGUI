add_library(vxgui_webgpu)
add_library(vxgui::webgpu ALIAS vxgui_webgpu)
target_sources(vxgui_webgpu PUBLIC
webgpu.cpp
)