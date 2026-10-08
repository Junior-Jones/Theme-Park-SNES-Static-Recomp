# 14C — Raster renderer and completed-frame publication

Status: closed at source/static-library level. No executable, target run, screenshot, gameplay, frontend or pixel/oracle-match claim.

The source-domain receipt proves only Modes 2 and 3. The renderer supplies BG1/BG2 tilemap/character decoding, Mode-2 offset-per-tile, Mode-3 depth selection, mosaic, flips, palettes and priorities; ordinary size-selector-zero OBJ with 32-sprite/34-sliver limits; main-screen composition; brightness and forced blank; pixel knownness; and separate work/published BGR555 frames.

Raster sampling is owned by the PAL scheduler. Visible state is consumed as raster time advances and publication occurs once at VBlank. Forced blank and brightness zero select known black before reading otherwise irrelevant memory. Any selected unknown tilemap, character, palette or OAM byte stops instead of fabricating a pixel.

Theme Park has no exact subscreen, window-mask or `$2131` color-math writer, and SETINI remains zero. These are source exclusions, not claims that the hardware lacks the features. `$211B/$211C` traffic is retained as multiply-register behavior and does not promote Mode 7 display code.
