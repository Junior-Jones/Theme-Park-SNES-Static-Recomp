/* Headless regression checks: no windows, ROM files or host devices opened. */
#include "theme_park_launch_options.h"

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <shellapi.h>
#endif

static unsigned checks, failures;
#define COUNT(a) (sizeof(a) / sizeof((a)[0]))
#define CHECK(condition) do { \
    ++checks; if (!(condition)) { \
        ++failures; fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #condition); \
    } \
} while (0)

static void rejected(int argc, const wchar_t *const *argv,
                      const wchar_t *message_part) {
    ThemeParkLaunchOptions options;
    wchar_t error[256];
    CHECK(!theme_park_launch_options_parse(argc, argv, &options,
                                           error, COUNT(error)));
    CHECK(wcsstr(error, message_part) != NULL);
    CHECK(!options.game && options.fullscreen_override == -1 &&
           options.rom_path[0] == L'\0');
}

static void argument_tests(void) {
    ThemeParkLaunchOptions options;
    wchar_t error[256], path[THEME_PARK_LAUNCH_PATH_CAPACITY];
    const wchar_t *bare[] = {L"--game"};
    const wchar_t *explicit_path[] = {L"--game", L"C:\\Games\\Theme Park.sfc",
                                     L"--fullscreen"};
    const wchar_t *combined[] = {L"--windowed", L"--game=C:\\Roms\\\u30c6\u30fc\u30de.sfc"};
    const wchar_t *presentation_only[] = {L"--fullscreen"};
    const wchar_t *duplicate[] = {L"--game", L"--game"};
    const wchar_t *duplicate_path[] = {L"--game=one.sfc", L"--game=two.sfc"};
    const wchar_t *conflict[] = {L"--game", L"--fullscreen", L"--windowed"};
    const wchar_t *repeat[] = {L"--fullscreen", L"--fullscreen"};
    const wchar_t *unknown[] = {L"--game", L"--unrecognized"};
    const wchar_t *extra[] = {L"--game", L"one.sfc", L"two.sfc"};
    const wchar_t *empty[] = {L"--game="};
    const wchar_t *empty_separate[] = {L"--game", L""};
    const wchar_t *blank[] = {L"--game= \t"};
    const wchar_t *widescreen[] = {L"--port-widescreen"};
    const wchar_t *widescreen_value[] = {L"--game", L"--port-widescreen=0"};
    const wchar_t *malformed[] = {L"--fullscreen=true"};
    const wchar_t *null_argument[] = {NULL};

    CHECK(theme_park_launch_options_parse(0, NULL, &options, error, COUNT(error)));
    CHECK(!options.game && options.fullscreen_override == -1 && !options.rom_path[0]);
    CHECK(theme_park_launch_rom_path(&options, NULL, path, COUNT(path),
                                     error, COUNT(error)) && !path[0]);
    CHECK(theme_park_launch_options_parse(1, bare, &options, error, COUNT(error)));
    CHECK(options.game && !options.rom_path[0]);
    CHECK(!theme_park_launch_rom_path(&options, L"", path, COUNT(path),
                                      error, COUNT(error)));
    CHECK(wcsstr(error, L"configured ROM") != NULL);
    CHECK(theme_park_launch_rom_path(&options, L"D:\\Saved ROM\\PAL.sfc",
                                     path, COUNT(path), error, COUNT(error)));
    CHECK(!wcscmp(path, L"D:\\Saved ROM\\PAL.sfc"));

    CHECK(theme_park_launch_options_parse(3, explicit_path, &options,
                                           error, COUNT(error)));
    CHECK(options.game && options.fullscreen_override == 1);
    CHECK(theme_park_launch_rom_path(&options, L"other.sfc", path, COUNT(path),
                                     error, COUNT(error)));
    CHECK(!wcscmp(path, explicit_path[1]));
    CHECK(!theme_park_launch_rom_path(&options, NULL, path, 4u,
                                      error, COUNT(error)) && !path[0]);
    CHECK(theme_park_launch_options_parse(2, combined, &options,
                                           error, COUNT(error)));
    CHECK(options.game && options.fullscreen_override == 0);
    CHECK(!wcscmp(options.rom_path, L"C:\\Roms\\\u30c6\u30fc\u30de.sfc"));
    CHECK(theme_park_launch_options_parse(1, presentation_only, &options,
                                           error, COUNT(error)));
    CHECK(!options.game && options.fullscreen_override == 1);
    CHECK(theme_park_launch_rom_path(&options, L"ignored.sfc", path, COUNT(path),
                                     error, COUNT(error)) && !path[0]);

    rejected(2, duplicate, L"only once");
    rejected(2, duplicate_path, L"only once");
    rejected(3, conflict, L"only one");
    rejected(2, repeat, L"only one");
    rejected(2, unknown, L"Unknown");
    rejected(3, extra, L"Unknown");
    rejected(1, empty, L"empty");
    rejected(2, empty_separate, L"empty");
    rejected(1, blank, L"empty");
    rejected(1, widescreen, L"4:3");
    rejected(2, widescreen_value, L"4:3");
    rejected(1, malformed, L"Unknown");
    rejected(1, null_argument, L"Invalid");
    rejected(-1, NULL, L"Invalid");
    rejected(1, NULL, L"Invalid");
    CHECK(!theme_park_launch_options_parse(0, NULL, NULL, NULL, 0u));
    {
        wchar_t long_path[THEME_PARK_LAUNCH_PATH_CAPACITY + 1u];
        const wchar_t *args[] = {L"--game", long_path};
        size_t i;
        for (i = 0; i < COUNT(long_path) - 1u; ++i) long_path[i] = L'x';
        long_path[COUNT(long_path) - 1u] = L'\0';
        rejected(2, args, L"too long");
        long_path[THEME_PARK_LAUNCH_PATH_CAPACITY - 1u] = L'\0';
        CHECK(theme_park_launch_options_parse(2, args, &options, NULL, 0u));
        CHECK(wcslen(options.rom_path) == THEME_PARK_LAUNCH_PATH_CAPACITY - 1u);
    }
}

#ifdef _WIN32
static void windows_quoted_case(const wchar_t *command_line,
                                const wchar_t *expected_rom, int fullscreen,
                                int success) {
    int argc = 0;
    wchar_t **argv = CommandLineToArgvW(command_line, &argc);
    ThemeParkLaunchOptions options;
    wchar_t error[256];
    CHECK(argv != NULL && argc >= 1);
    if (!argv || argc < 1) { if (argv) LocalFree(argv); return; }
    CHECK(theme_park_launch_options_parse(argc - 1,
          (const wchar_t *const *)(argv + 1), &options,
          error, COUNT(error)) == success);
    if (success) {
        CHECK(options.game && options.fullscreen_override == fullscreen);
        CHECK(!wcscmp(options.rom_path, expected_rom));
    }
    LocalFree(argv);
}

static void windows_quote_tests(void) {
    windows_quoted_case(
        L"Launcher.exe --game \"C:\\Games\\Theme Park (Europe).sfc\" --fullscreen",
        L"C:\\Games\\Theme Park (Europe).sfc", 1, 1);
    windows_quoted_case(
        L"\"C:\\Program Files\\Theme Park\\Launcher.exe\" --windowed --game=\"C:\\Roms\\\u30c6\u30fc\u30de \u516c\u5712.sfc\"",
        L"C:\\Roms\\\u30c6\u30fc\u30de \u516c\u5712.sfc", 0, 1);
    windows_quoted_case(L"Launcher.exe --game --fullscreen", L"", 1, 1);
    /* Native Windows quoting: two backslashes before a closing quote become
       one trailing slash in the path; no custom tokenizer guesses required. */
    windows_quoted_case(L"Launcher.exe --game \"C:\\Roms\\\\\"",
                        L"C:\\Roms\\", -1, 1);
    windows_quoted_case(L"Launcher.exe --game \"\"", L"", -1, 0);
    windows_quoted_case(L"Launcher.exe --game=\"\"", L"", -1, 0);
}
#endif

int main(void) {
    argument_tests();
#ifdef _WIN32
    windows_quote_tests();
#endif
    printf("%s %u launch-option checks; failures=%u\n",
           failures ? "FAIL" : "PASS", checks, failures);
    return failures ? 1 : 0;
}
