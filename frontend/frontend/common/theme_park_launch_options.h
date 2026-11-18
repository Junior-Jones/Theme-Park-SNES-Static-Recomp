#ifndef THEME_PARK_LAUNCH_OPTIONS_H
#define THEME_PARK_LAUNCH_OPTIONS_H

#include <stddef.h>
#include <wchar.h>

#define THEME_PARK_LAUNCH_PATH_CAPACITY 4096u

typedef struct ThemeParkLaunchOptions {
    int game;
    /* -1: configured presentation, 0: windowed, 1: fullscreen. */
    int fullscreen_override;
    wchar_t rom_path[THEME_PARK_LAUNCH_PATH_CAPACITY];
} ThemeParkLaunchOptions;

/* argv contains options only, excluding the executable name. Windows callers
   use CommandLineToArgvW, preserving native Unicode/quoting semantics. Unknown,
   duplicate and conflicting options fail without publishing partial options. */
int theme_park_launch_options_parse(int argc, const wchar_t *const *argv,
                                    ThemeParkLaunchOptions *options,
                                    wchar_t *error, size_t error_capacity);

/* Resolve a direct launch's explicit path or configured INI path. This neither
   reads files nor validates ROM identity: the existing core loader owns that.
   No --game leaves path empty and succeeds without requiring a configured ROM. */
int theme_park_launch_rom_path(const ThemeParkLaunchOptions *options,
                               const wchar_t *configured_rom,
                               wchar_t *path, size_t path_capacity,
                               wchar_t *error, size_t error_capacity);

#endif
