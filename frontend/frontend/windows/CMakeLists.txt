cmake_minimum_required(VERSION 3.20)
project(ThemeParkWindowsFrontend LANGUAGES C CXX)

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif()
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

get_filename_component(THEME_PARK_SOURCE_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)
set(THEME_PARK_GAMEPAD_ADAPTER_DIR
  "${THEME_PARK_SOURCE_ROOT}/frontend/third_party/jungle-gamepad")
add_subdirectory("${THEME_PARK_SOURCE_ROOT}"
  "${CMAKE_BINARY_DIR}/static-core" EXCLUDE_FROM_ALL)

include(FetchContent)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(theme_park_sdl
  URL "https://github.com/libsdl-org/SDL/archive/refs/tags/release-3.4.10.zip"
  URL_HASH "SHA256=30DCE54890B17544A35E4521274762016AF6ED59C2183B896EF5E6693E97FB6C"
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_MakeAvailable(theme_park_sdl)

add_executable(theme-park-launcher WIN32
  jungle_launcher_win32.c
  jungle_app_core.c
  launcher_version.rc
  jungle_audio_output_dsound_win32.c
  jungle_audio_resampler.c
  jungle_frontend_settings_win32.c
  ../common/jungle_input_latch.c
  ../common/theme_park_launch_options.c
  "${THEME_PARK_GAMEPAD_ADAPTER_DIR}/jungle_gamepad_input_win32.c")
target_include_directories(theme-park-launcher PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${CMAKE_CURRENT_LIST_DIR}/../common"
  "${THEME_PARK_SOURCE_ROOT}/runtime/include"
  "${THEME_PARK_GAMEPAD_ADAPTER_DIR}")
target_link_libraries(theme-park-launcher PRIVATE
  theme_park_static_core SDL3::SDL3-static
  user32 gdi32 comdlg32 comctl32 shell32 dsound dxguid winmm bcrypt)
target_compile_definitions(theme-park-launcher PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS)
if(MSVC)
  target_compile_options(theme-park-launcher PRIVATE
    /W4 /WX /experimental:deterministic)
  target_link_options(theme-park-launcher PRIVATE $<$<CONFIG:Release>:/Brepro>)
else()
  target_compile_options(theme-park-launcher PRIVATE -Wall -Wextra -Wpedantic)
endif()
set_target_properties(theme-park-launcher PROPERTIES
  OUTPUT_NAME "Launcher"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/release")
add_custom_command(TARGET theme-park-launcher POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E make_directory
    "$<TARGET_FILE_DIR:theme-park-launcher>/Rom"
  COMMAND "${CMAKE_COMMAND}" -E make_directory
    "$<TARGET_FILE_DIR:theme-park-launcher>/Screenshots"
    "$<TARGET_FILE_DIR:theme-park-launcher>/Saves"
    "$<TARGET_FILE_DIR:theme-park-launcher>/Logs"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${THEME_PARK_SOURCE_ROOT}/recomplauncher.json"
    "${THEME_PARK_SOURCE_ROOT}/README.txt"
    "${THEME_PARK_SOURCE_ROOT}/VERSION.txt"
    "${THEME_PARK_SOURCE_ROOT}/SDL-LICENSE.txt"
    "${THEME_PARK_SOURCE_ROOT}/THIRD-PARTY-NOTICES.txt"
    "$<TARGET_FILE_DIR:theme-park-launcher>"
  VERBATIM)

option(THEME_PARK_BUILD_TESTS "Build ROM-free launcher and graphics regression tests" OFF)
if(THEME_PARK_BUILD_TESTS)
  enable_testing()
  add_executable(theme-park-launch-options-test
    "${THEME_PARK_SOURCE_ROOT}/tools/test_launch_options.c"
    ../common/theme_park_launch_options.c)
  target_include_directories(theme-park-launch-options-test PRIVATE ../common)
  target_link_libraries(theme-park-launch-options-test PRIVATE shell32)
  set_target_properties(theme-park-launch-options-test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests/$<CONFIG>")
  if(MSVC)
    target_compile_options(theme-park-launch-options-test PRIVATE /W4 /WX)
  endif()
  add_test(NAME launch-options COMMAND theme-park-launch-options-test)
  foreach(graphics_case IN ITEMS priority mode2_offsets bg_sampling obj_cache)
    set(graphics_target "theme-park-graphics-${graphics_case}-test")
    add_executable(${graphics_target}
      "${THEME_PARK_SOURCE_ROOT}/tests/graphics/test_${graphics_case}.c")
    target_include_directories(${graphics_target} PRIVATE
      "${THEME_PARK_SOURCE_ROOT}/runtime/include"
      "${THEME_PARK_SOURCE_ROOT}/static-core/internal")
    set_target_properties(${graphics_target} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests/$<CONFIG>")
    if(MSVC)
      target_compile_options(${graphics_target} PRIVATE /W4 /WX)
    endif()
    add_test(NAME "graphics-${graphics_case}" COMMAND ${graphics_target})
  endforeach()
endif()

