# peanut.vxp
Game Boy emulator based on [Peanut-GB](https://github.com/deltabeard/Peanut-GB) for [MediaTek MRE](https://lpcwiki.miraheze.org/wiki/MAUI_Runtime_Environment) feature phones

![](img/marioland_215.jpg)

## Status
* Currently the emulator can run any Game Boy (not Color) ROM that we've tested. Some games like Pokémon Red/Blue may have graphical issues.
* Input is supported, but only one key can be pressed at a time.
* In-game saving is supported, though it's a bit slow.
* Save states are not supported.

## Compatibility
| Phone | Status |
| ----------- | ----------- |
| Alcatel 2005x | Works, full speed? |
| Nokia 215<br>Likely other S30+ phones | Works, full speed |
| Alcatel A392CC | Crash |
| Doro PhoneEasy 530X<br>Likely other Doro phones | Crash |
| Logic M5 | Crash |
| Mobiwire Dakota | Crash |
| Motorola Gleam+ | Failed to start application |

## How to build
1. Install the dependencies outlined in the [MRE Makefile](https://github.com/gtrxAC/mre-makefile#dependencies) project.
2. Run `make setup` and `make`.

## How to use
1. Download the VXP file from Releases, or compile it yourself by following the above steps.
2. **Skip this step if you're not using Series 30+.** You'll need to sign the VXP file to your SIM card's IMSI. There are many ways to find your IMSI, [here](https://github.com/raspiduino/mre-sdk/discussions/1#discussioncomment-3571276) is one. Insert the IMSI and VXP into [this tool](https://vxpatch.luxferre.top/).
3. Put a ROM file on your phone's SD card in `E:\peanutvxp\rom.gb`. Note that this path may differ based on the phone's MRE implementation - for example on Series 30+, it's based on the location of the VXP file, so if you send the VXP via Bluetooth, it will go in `Received files`, and the ROM will go in `Memory card/Received files/peanut/e/peanutvxp/rom.gb`. If you can't find it, run peanut.vxp without a ROM - it will crash your phone, but it will create a log file in the correct directory.
4. Send the VXP file to your phone and open it from the file manager.

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