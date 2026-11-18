# Theme Park 1.0.1 portable package

This package uses the non-widescreen 1.0.1 baseline. The experimental widescreen build is excluded and remains on hold. Full gameplay and release certification are not claimed by this packaging audit.

On Windows, extract release.zip into a writable folder and run Launcher.exe. Select your own supported Europe PAL ROM using the launcher. No ROM, saved ROM path, settings, snapshots or screenshots are distributed. Settings and user data are stored beside the executable; do not install into a read-only folder.

To compile the source, install Visual Studio 2022 with Desktop development with C++, the Windows SDK, and CMake 3.20 or newer. From this source folder:

```powershell
cmake -S frontend/frontend/windows -B build -A x64
cmake --build build --config Release --target theme-park-launcher
```

The output is build/release/Launcher.exe. CMake downloads the pinned SDL source for gamepad support; internet access is required for the initial build unless that dependency is supplied through CMake's FetchContent override. Paths are relative to the source tree, not a developer's installation. SDL and the MSVC runtime are linked statically; the executable otherwise uses Windows system libraries.

ROM-free launcher and renderer regression sources are included for CI. Development gameplay probes and scripted ROM routes remain outside this release source. Historical development evidence is preserved separately in the working project, not packaged as release functionality.

ROM-free regression tests
-------------------------
```powershell
cmake -S frontend/frontend/windows -B build -A x64 -DTHEME_PARK_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

CMake copies recomplauncher.json and the release documents beside Launcher.exe.
Release ZIP creation uses an explicit allowlist; test executables, ROMs and user
settings are excluded. CI also validates the profile against the official
RecompLauncher schema and checks all source-manifest hashes.
