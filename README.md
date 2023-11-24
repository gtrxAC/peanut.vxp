# peanut.vxp
Game Boy emulator based on [Peanut-GB](https://github.com/deltabeard/Peanut-GB) for [MediaTek MRE](https://lpcwiki.miraheze.org/wiki/MAUI_Runtime_Environment) feature phones

## Status
* Currently the emulator can run any Game Boy (not Color) ROM at about half speed with 1 frameskip. Some games like Pokémon Red/Blue may have graphical issues.
* The app was tested on the Nokia 215, and is currently not supported on Doro phones.
* Input is supported, but only one key can be pressed at a time.
* The ROM is embedded into the .vxp file (i.e. no file system support)
* Key bindings for reset, savestate, etc. are not available.
* Saving is not supported.

## How to build
1. Write your own ROM file into the `src/rom.h` file. You can use the `xxd` command for this: `xxd -i /path/to/rom.gb src/rom.h`. Check that the array variable in the output file is named `rom_data`.
2. Install the dependencies outlined in the [MRE Makefile](https://github.com/gtrxAC/mre-makefile) project.
3. Run `make setup` and `make`.

## License
`src/`, `Makefile`, and `sdk/build.py` are MIT licensed, other files may have their own licensing terms (such as headers and link libraries taken from the MRE SDK).