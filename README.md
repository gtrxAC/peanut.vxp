# peanut.vxp
Game Boy emulator based on [Peanut-GB](https://github.com/deltabeard/Peanut-GB) for [MediaTek MRE](https://lpcwiki.miraheze.org/wiki/MediaTek_MRE) feature phones

![](img/marioland_215.jpg)
*<div style="text-align:center;">Nokia 215 • Alcatel 3040g (thanks RedillGMV) • MyPhone T29 TV Duo (thanks aubykddi)</div>*

## Status
* Currently the emulator can run any Game Boy ROM that we've tested. The emulator core itself should support at least [these games](https://github.com/deltabeard/Peanut-GB/issues/31).
* Sound emulation is highly experimental and disabled by default.

## Compatibility
peanut.vxp currently works on any phone with MRE 2.5 or above, those mostly being Nokia and Alcatel phones released since around 2014. Support for older devices is planned but currently not possible.
| Phone | Status |
| ----------- | ----------- |
| Alcatel 2005x | Works
| Alcatel 3040 | Works
| Explay T285 | Works
| MyPhone T29 TV Duo | Works
| Nokia 215<br>Nokia 230<br>Nokia 3310 2G (2017)<br>Likely other S30+ phones | Works
| Starmobile B506 | Works
| LG C299 | Stuck on MRE logo
| Alcatel A392CC | Crash
| Doro PhoneEasy 530X<br>Likely other Doro phones | Crash
| Logic M5 | Crash
| Mobiwire Dakota | Crash
| MyPhone my16 | Unsupported (not enough RAM)
| Alcatel OT-871a | Failed to start (botched MRE implementation)
| Fly DS125 | Failed to start
| Motorola Gleam+ | Failed to start (too old?)

## How to build
1. Install the dependencies outlined in the [MRE Makefile](https://github.com/gtrxAC/mre-makefile#dependencies) project.
2. Run `make`.

## How to use
1. Download the VXP file from [Releases](https://github.com/gtrxAC/peanut.vxp/releases), or compile it yourself by following the above steps.
2. **Skip this step if you're not using Series 30+.** You'll need to sign the VXP file to your SIM card's IMSI. There are many ways to find your IMSI, [here](https://github.com/raspiduino/mre-sdk/discussions/1#discussioncomment-3571276) is one. Insert the IMSI and VXP into [this tool](https://vxpatch.luxferre.top/).
3. Put ROM files on your phone's SD card in `E:\peanutvxp`. Note that the actual path may differ based on the phone's MRE implementation - usually it's the `peanutvxp` folder in the root of your SD card, but if not, you can follow step 4 and you'll find a config and log file in the correct directory.
4. Send the VXP file to your phone and open it from the file manager.

## Key bindings
Key bindings can be configured in the Options menu. Here are the default key bindings:
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
| Menu | `0`
| Fast forward | `1`

## License
`src/`, `Makefile`, and `sdk/build.py` are MIT licensed, other files may have their own licensing terms (such as headers and link libraries taken from the MRE SDK).

## Thanks
* RedillGMV, aubykddi, and others in the [ROMphonix community](https://discord.gg/2GKuJjQagp) and [4PDA thread](https://4pda.to/forum/index.php?showtopic=501783&st=2280) for testing and feedback
* Peanut-GB contributors for making it easy to port Game Boy emulators to just about any platform
* [Ximik_Boda](https://github.com/XimikBoda) for helping with MRE development
* GrafxKid, the BGB emulator team, and [Lospec](https://lospec.com/) members Space Sandwich and WildLeoKnight for creating some awesome color palettes (see [config.c](https://github.com/gtrxAC/peanut.vxp/blob/main/src/config.c#L10))
