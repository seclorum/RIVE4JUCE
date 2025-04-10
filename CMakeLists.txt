cmake_minimum_required(VERSION 3.15)
project(RIVE4JUCE VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# JUCE path (assuming it's one level up)
set(JUCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../JUCE" CACHE PATH "Path to JUCE library")
if(NOT EXISTS "${JUCE_PATH}/CMakeLists.txt")
    message(FATAL_ERROR "JUCE path not found at: ${JUCE_PATH}")
endif()

# Rive paths (assuming rive-runtime-main is one level up)
set(RIVE_CPP_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../rive-runtime-main/include")
set(RIVE_RENDERER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../rive-runtime-main/renderer/include")
set(RIVE_RENDERER_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../rive-runtime-main/renderer/src")
set(RIVE_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../rive-runtime-main/out/debug/rive.lib")

add_subdirectory(${JUCE_PATH} ${CMAKE_BINARY_DIR}/JUCE EXCLUDE_FROM_ALL)

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
        "${RIVE_LIB_PATH}"
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
)
