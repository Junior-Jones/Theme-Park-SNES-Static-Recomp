cmake_minimum_required(VERSION 3.20)
project(ThemeParkStaticCore LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(STRINGS
  "${CMAKE_CURRENT_SOURCE_DIR}/static-core/generated/scpu/tp_v07_sources.txt"
  THEME_PARK_SCPU_SOURCE_NAMES)
set(THEME_PARK_CORE_SOURCES)
foreach(source_name IN LISTS THEME_PARK_SCPU_SOURCE_NAMES)
  list(APPEND THEME_PARK_CORE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/${source_name}")
endforeach()
list(APPEND THEME_PARK_CORE_SOURCES
  runtime/src/theme_park_bus.c
  runtime/src/theme_park_scheduler.c
  runtime/src/theme_park_dma.c
  runtime/src/theme_park_ppu.c
  runtime/src/theme_park_renderer.c
  runtime/src/theme_park_apu.c
  runtime/src/theme_park_spc700.c
  runtime/generated/theme_park_spc700_aot.c
  runtime/src/theme_park_input.c
  runtime/src/theme_park_sdsp.c
  runtime/src/theme_park_machine.c
  static-core/generated/timing/theme_park_v09_timing.c)

list(LENGTH THEME_PARK_CORE_SOURCES THEME_PARK_CORE_SOURCE_COUNT)
if(NOT THEME_PARK_CORE_SOURCE_COUNT EQUAL 684)
  message(FATAL_ERROR
    "Theme Park production source inventory must contain exactly 684 files")
endif()

add_library(theme_park_static_core STATIC ${THEME_PARK_CORE_SOURCES})
option(THEME_PARK_SIZE_OPTIMIZED_GENERATED
  "Size-optimize generated native authority; requires separate qualification" OFF)
if(THEME_PARK_SIZE_OPTIMIZED_GENERATED)
  foreach(source_name IN LISTS THEME_PARK_CORE_SOURCES)
    if(source_name MATCHES "generated/scpu/.*\\.c$" OR
       source_name MATCHES "runtime/generated/theme_park_spc700_aot\\.c$")
      if(MSVC)
        set_property(SOURCE "${source_name}" APPEND PROPERTY COMPILE_OPTIONS
          "$<$<CONFIG:Release>:/O1>")
      else()
        set_property(SOURCE "${source_name}" APPEND PROPERTY COMPILE_OPTIONS
          "$<$<CONFIG:Release>:-Os>")
      endif()
    endif()
  endforeach()
endif()
target_include_directories(theme_park_static_core PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/runtime/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/static-core/internal"
  "${CMAKE_CURRENT_SOURCE_DIR}/static-core/generated/scpu"
  "${CMAKE_CURRENT_SOURCE_DIR}/static-core/generated/timing")
if(MSVC)
  target_compile_options(theme_park_static_core PRIVATE /W4 /WX /bigobj)
else()
  target_compile_options(theme_park_static_core PRIVATE
    -Wall -Wextra -Wpedantic -Werror)
endif()
