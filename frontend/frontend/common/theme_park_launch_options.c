#include "theme_park_launch_options.h"

#include <string.h>

static int fail(wchar_t *error, size_t capacity, const wchar_t *message) {
    size_t i = 0u;
    if (error && capacity) {
        while (i + 1u < capacity && message[i]) {
            error[i] = message[i];
            ++i;
        }
        error[i] = L'\0';
    }
    return 0;
}

static int nonblank_path(const wchar_t *path) {
    if (!path) return 0;
    while (*path) {
        if (*path != L' ' && *path != L'\t' &&
            *path != L'\r' && *path != L'\n') return 1;
        ++path;
    }
    return 0;
}

static int copy_path(wchar_t *destination, size_t capacity,
                     const wchar_t *path, wchar_t *error, size_t error_capacity) {
    size_t length;
    if (!nonblank_path(path))
        return fail(error, error_capacity, L"The ROM path must not be empty.");
    length = wcslen(path);
    if (length >= capacity)
        return fail(error, error_capacity, L"The ROM path is too long.");
    memcpy(destination, path, (length + 1u) * sizeof(*destination));
    return 1;
}

int theme_park_launch_options_parse(int argc, const wchar_t *const *argv,
                                    ThemeParkLaunchOptions *options,
                                    wchar_t *error, size_t error_capacity) {
    ThemeParkLaunchOptions parsed;
    int i;
    memset(&parsed, 0, sizeof(parsed));
    parsed.fullscreen_override = -1;
    if (error && error_capacity) error[0] = L'\0';
    if (!options)
        return fail(error, error_capacity, L"Missing launch options output.");
    *options = parsed;
    if (argc < 0 || (argc && !argv))
        return fail(error, error_capacity, L"Invalid command-line arguments.");
    for (i = 0; i < argc; ++i) {
        const wchar_t *argument = argv[i];
        const wchar_t *path = NULL;
        if (!argument)
            return fail(error, error_capacity, L"Invalid command-line argument.");
        if (!wcscmp(argument, L"--game") ||
            !wcsncmp(argument, L"--game=", 7u)) {
            if (parsed.game)
                return fail(error, error_capacity, L"--game may be specified only once.");
            parsed.game = 1;
            if (argument[6] == L'=') path = argument + 7u;
            else if (i + 1 < argc && argv[i + 1] && argv[i + 1][0] != L'-')
                path = argv[++i];
            if (path && !copy_path(parsed.rom_path,
                                  THEME_PARK_LAUNCH_PATH_CAPACITY,
                                  path, error, error_capacity)) return 0;
        } else if (!wcscmp(argument, L"--fullscreen") ||
                   !wcscmp(argument, L"--windowed")) {
            if (parsed.fullscreen_override != -1)
                return fail(error, error_capacity,
                            L"Specify only one of --fullscreen and --windowed.");
            parsed.fullscreen_override = !wcscmp(argument, L"--fullscreen");
        } else if (!wcscmp(argument, L"--port-widescreen") ||
                   !wcsncmp(argument, L"--port-widescreen=", 18u)) {
            return fail(error, error_capacity,
                        L"--port-widescreen is unavailable in this 4:3 Theme Park build.");
        } else {
            return fail(error, error_capacity,
                        L"Unknown argument. Use --game [ROM path], --fullscreen or --windowed.");
        }
    }
    *options = parsed;
    return 1;
}

int theme_park_launch_rom_path(const ThemeParkLaunchOptions *options,
                               const wchar_t *configured_rom,
                               wchar_t *path, size_t path_capacity,
                               wchar_t *error, size_t error_capacity) {
    if (error && error_capacity) error[0] = L'\0';
    if (!path || !path_capacity || !options)
        return fail(error, error_capacity, L"Missing startup path output.");
    path[0] = L'\0';
    if (!options->game) return 1;
    if (options->rom_path[0])
        return copy_path(path, path_capacity, options->rom_path,
                         error, error_capacity);
    if (!nonblank_path(configured_rom))
        return fail(error, error_capacity,
                    L"--game needs a configured ROM or an explicit ROM path.");
    return copy_path(path, path_capacity, configured_rom, error, error_capacity);
}
