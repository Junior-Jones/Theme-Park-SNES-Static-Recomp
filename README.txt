Theme Park (SNES) Static Recompilation
Version 1.0.0

Running the application
-----------------------
Extract the complete release into a writable folder and run Launcher.exe.
On first launch, close Welcome to continue to Launcher. Select your own ROM
with Browse ROM, or place it in the Rom folder. No ROM is included.
The launcher title is Launcher; the running game title is Theme Park (SNES).

Supported ROM
-------------
Theme Park (Europe) (En,Fr,De), unheadered .sfc, PAL.
Size: 1,048,576 bytes.
SHA-256: c0a7e27131a7d8c9ef52a5227329e6de5846c045a9da1f3f84845e3be8e4efba
The filename can differ; the application verifies the complete ROM identity.

Controls and saves
------------------
This is a one-player game. Keyboard and SDL3 gamepad input are configurable
through Controller Bindings (F5). Select Gamepad there to use a controller.
SDL3 is statically linked and supplies built-in controller mappings; no
separate SDL DLL or controller database installation is required.

Escape  Switch between gameplay and Launcher / pause or resume
F1      Welcome and shortcut help
F2/F3   Save / Load Snapshot window
F4      Settings
F5      Controller Bindings
F6      Audio Settings
F7      Run the selected ROM
F8      Screenshot
1/2     Save / load the selected snapshot slot

Snapshots preserve the complete machine state and are intended for this
build. Keep a backup before moving saves between different builds.
Settings and user files are stored beside Launcher.exe. The release does
not include personal settings, saved ROM paths, snapshots or captured images.

Static core and audio
---------------------
The game's S-CPU and SPC700 instructions execute through ahead-of-time native
code. There is no runtime CPU interpreter, JIT, target-learning system or
emulator fallback. Graphics and audio are computed live, not prerecorded.
The core owns PAL timing and produces 32,040 Hz signed 16-bit stereo audio.
The frontend streams it to DirectSound, with 48,000 Hz Hermite output by
default. Error reporting and normal audio diagnostics remain available.

Known limitations
-----------------
This release uses the original 4:3 game image. Widescreen support is a work
in progress and is not included. Its main unresolved issue is audio:
experimental widescreen runs produced stuttering/crackling, so that work
is on hold. Some roughness was also heard by the user in the original ROM
under Mesen, particularly the title-screen music loop. That observation
does not prove that every remaining recomp audio artifact comes from the ROM.

Build from source
-----------------
Windows x64; Visual Studio 2022 C++ tools, Windows SDK and CMake 3.20+.
From the Source folder:
  cmake -S frontend/frontend/windows -B build -A x64
  cmake --build build --config Release --target theme-park-launcher
Output: build/release/Launcher.exe. Initial configuration downloads the
pinned SDL3 source unless supplied through CMake's FetchContent override.
SDL3 and the Visual C++ runtime are statically linked. Runtime requires
Windows system components, not the development toolchain.

Feedback
--------
Please report gameplay issues to Junior Jones on X: https://x.com/JJ_Retro
Include what happened and how to reproduce it. Screenshots and a same-build
snapshot can help. Please do not share the game ROM.
