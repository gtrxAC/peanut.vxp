# peanut.vxp
Game Boy emulator based on [Peanut-GB](https://github.com/deltabeard/Peanut-GB) for [MediaTek MRE](https://lpcwiki.miraheze.org/wiki/MAUI_Runtime_Environment) feature phones

![](img/marioland_215.jpg)
*<div style="text-align:center;">Nokia 215 • Alcatel 3040g (thanks RedillGMV) • MyPhone T29 TV Duo (thanks aubykddi)</div>*

## Status
* Currently the emulator can run any Game Boy (not Color) ROM that we've tested. The emulator core itself should support at least [these games](https://github.com/deltabeard/Peanut-GB/issues/31).
* Input is supported, but only one key can be pressed at a time.
* Sound emulation is not implemented and not planned due to MRE limitations.

## Compatibility
peanut.vxp currently works on any phone with MRE 2.5 or above, those mostly being Nokia and Alcatel phones released since around 2014. Support for older devices is planned but currently not possible.
| Phone | Status |
| ----------- | ----------- |
| Alcatel 2005x | Works
| Alcatel 3040 | Works
| MyPhone T29 TV Duo | Works
| Nokia 215<br>Likely other S30+ phones | Works
| Starmobile B506 | Works
| Alcatel A392CC | Crash
| Doro PhoneEasy 530X<br>Likely other Doro phones | Crash
| Logic M5 | Crash
| Mobiwire Dakota | Crash
| MyPhone my16 | Unsupported (not enough RAM)
| Alcatel OT-871a | Failed to start (botched MRE implementation)
| Motorola Gleam+ | Failed to start (too old?)

## How to build
1. Install the dependencies outlined in the [MRE Makefile](https://github.com/gtrxAC/mre-makefile#dependencies) project.
2. Run `make setup` and `make`.

## How to use
1. Download the VXP file from Releases, or compile it yourself by following the above steps.
2. **Skip this step if you're not using Series 30+.** You'll need to sign the VXP file to your SIM card's IMSI. There are many ways to find your IMSI, [here](https://github.com/raspiduino/mre-sdk/discussions/1#discussioncomment-3571276) is one. Insert the IMSI and VXP into [this tool](https://vxpatch.luxferre.top/).
3. Put ROM files on your phone's SD card in `E:\peanutvxp`. Note that the actual path may differ based on the phone's MRE implementation - usually it's the `peanutvxp` folder in the root of your SD card, but if not, you can follow step 4 and you'll find a config and log file in the correct directory.
5. Send the VXP file to your phone and open it from the file manager.

## Key bindings
Key bindings can be configured in the Options menu. While playing, the menu can be accessed with the `0` key, or with the `Menu` virtual button when using a touchscreen. Here are the default key bindings:
| Game Boy | Keypad |
| ----------- | ----------- |
| Up | D-pad up
| Down | D-pad down
| Left | D-pad left
| Right | D-pad right
| A | Right softkey
| B | Left softkey
| Start | `#`
| Select | `*`

## License
`src/`, `Makefile`, and `sdk/build.py` are MIT licensed, other files may have their own licensing terms (such as headers and link libraries taken from the MRE SDK).
