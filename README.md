# mre-makefile
Cross-platform build script for developing apps for [MediaTek MRE](https://lpcwiki.miraheze.org/wiki/MAUI_Runtime_Environment) feature phones; replacement for the proprietary Windows-only MRE SDK.

## Status
### What works
- Compiling a VXP file under Linux
- VXP file runs on Nokia Series 30+

### What is untested
- Compiling a VXP file under Windows

### What doesn't work
- Compiling a VXP file under macOS
- VXP file runs on Doro PhoneEasy devices (included tags file declares incompatible APIs)
- Editing app metadata (tags)
- Editing app resources - not planned unless absolutely required

## Dependencies
On Windows, you can download and run [w64devkit](https://github.com/skeeto/w64devkit/releases), which provides make and binutils. On Linux, you should install these with your package manager. On macOS, good luck.
* GNU Make
* Python
* Binutils
* ARM GCC

## How to use
* `make setup` - sets up directory structure
* `make` - compiles project and creates VXP in the project root folder
* `make clean` - deletes any compilation data

## License
The Makefile and build.py script are MIT licensed, other files may have their own licensing terms.

## Thanks
I would like to thank @XimikBoda for helping me understand the VXP file format.