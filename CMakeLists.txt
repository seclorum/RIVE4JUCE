cmake_minimum_required(VERSION 3.15)
project(RIVE4JUCE VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent module
include(FetchContent)

# Fetch JUCE from GitHub
FetchContent_Declare(
        juce
        GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
        GIT_TAG 7.0.9  # Use a specific stable version
)
FetchContent_MakeAvailable(juce)

# Fetch Rive runtime
FetchContent_Declare(
        rive
        GIT_REPOSITORY https://github.com/seclorum/rive-cpp-legacy.git
#        GIT_TAG v0.1.0  # Use a specific version; adjust as needed
)
FetchContent_MakeAvailable(rive)

# Define Rive paths using fetched content
set(RIVE_SOURCE_DIR ${rive_SOURCE_DIR})
set(RIVE_CPP_INCLUDE_DIR "${RIVE_SOURCE_DIR}/include")
set(RIVE_RENDERER_INCLUDE_DIR "${RIVE_SOURCE_DIR}/renderer/include")
set(RIVE_RENDERER_SRC_DIR "${RIVE_SOURCE_DIR}/renderer/src")

# Build Rive as a static library
add_library(rive_static STATIC
        "${RIVE_SOURCE_DIR}/src/animation/animation.cpp"
        "${RIVE_SOURCE_DIR}/src/animation/animation_state.cpp"
        # Add more source files as needed - this is a minimal set
        # Full list would need to be expanded based on Rive's build requirements
        "${RIVE_SOURCE_DIR}/src/core/field_types/core_field_types.cpp"
        "${RIVE_SOURCE_DIR}/src/renderer.cpp"
)
target_include_directories(rive_static PUBLIC
        ${RIVE_CPP_INCLUDE_DIR}
        ${RIVE_RENDERER_INCLUDE_DIR}
        ${RIVE_RENDERER_SRC_DIR}
)

# Add the plugin
juce_add_plugin(RIVE4JUCE
        COMPANY_NAME "DemoCorp"
        PLUGIN_MANUFACTURER_CODE "Rive"
        PLUGIN_CODE "R4JD"
        FORMATS VST3 Standalone
        PRODUCT_NAME "RIVE4JUCE"
)

juce_generate_juce_header(RIVE4JUCE)

target_sources(RIVE4JUCE
        PRIVATE
        Source/PluginProcessor.cpp
        Source/PluginEditor.cpp
        Source/RiveRenderer.cpp
        Source/PluginProcessor.h
        Source/PluginEditor.h
        Source/RiveRenderer.h
)

target_include_directories(RIVE4JUCE
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Source
        ${RIVE_CPP_INCLUDE_DIR}
        ${RIVE_RENDERER_INCLUDE_DIR}
        ${RIVE_RENDERER_SRC_DIR}
)

target_compile_definitions(RIVE4JUCE
        PRIVATE
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_DISPLAY_SPLASH_SCREEN=0
)

target_link_libraries(RIVE4JUCE
        PRIVATE
        juce::juce_audio_utils
        juce::juce_opengl
        juce::juce_audio_plugin_client
        rive_static
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
)