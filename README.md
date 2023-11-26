# peanut.vxp
Game Boy emulator based on [Peanut-GB](https://github.com/deltabeard/Peanut-GB) for [MediaTek MRE](https://lpcwiki.miraheze.org/wiki/MAUI_Runtime_Environment) feature phones

![](img/marioland_215.jpg)

## Status
* Currently the emulator can run any Game Boy (not Color) ROM that we've tested. Some games like Pokémon Red/Blue may have graphical issues.
* Input is supported, but only one key can be pressed at a time.
* The ROM is embedded into the .vxp file (i.e. no file system support)
* In-game saving and save states are not supported.

## Compatibility
| Phone | Status |
| ----------- | ----------- |
| Alcatel 2005x | Works, full speed? |
| Nokia 215<br>Likely other S30+ phones | Works, full speed |
| Doro PhoneEasy 530X<br>Likely other Doro phones | Crash |
| Logic M5 | Crash |
| Mobiwire Dakota | Crash |
| Motorola Gleam+ | Failed to start application |

## How to build
1. Write your own ROM file into the `src/rom.h` file. You can use the `xxd` command for this: `xxd -i /path/to/rom.gb src/rom.h`. Check that the array variable in the output file is named `rom_data`.
2. Install the dependencies outlined in the [MRE Makefile](https://github.com/gtrxAC/mre-makefile#dependencies) project.
3. Run `make setup` and `make`.

## Key bindings
These are currently not configurable.
* D-pad is d-pad. You can also use `2`, `4`, `6`, `8`.
* Left softkey: B
* Right softkey or `5`: A
* `*`: Select
* `#`: Start
* `1`: Toggle interlacing
* `7`: Show frame time
* `9`: Toggle frameskip
* `0`: Reset

## License
`src/`, `Makefile`, and `sdk/build.py` are MIT licensed, other files may have their own licensing terms (such as headers and link libraries taken from the MRE SDK).