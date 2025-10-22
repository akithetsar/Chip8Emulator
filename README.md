# Chip-8 Emulator

A fully functional Chip-8 emulator written in C/C++ with SDL3 for graphics and input handling. This emulator accurately implements the complete Chip-8 instruction set and provides a customizable display interface.

## Features

- **Complete Chip-8 Instruction Set**: All 35 opcodes implemented
- **SDL3 Graphics**: Modern rendering with SDL3 library
- **Configurable Display**: Adjustable screen scaling and cycle delay
- **Keyboard Input**: Full 16-key hexadecimal keypad support
- **ROM Loading**: Load and run any Chip-8 ROM file

## Examples

#### Brick.ch8
https://github.com/user-attachments/assets/32af07bc-8ae4-46f8-89b1-bc5935785a85


#### Airplane.ch8
https://github.com/user-attachments/assets/b6002edd-623b-4221-84a3-99f056ae827b



## Technical Specifications

- **Memory**: 4KB RAM (4096 bytes)
- **Display**: 64x32 monochrome pixels
- **Registers**: 16 8-bit general purpose registers (V0-VF)
- **Stack**: 16 levels for subroutine calls
- **Timers**: Delay and sound timers at 60Hz

## Building

### Prerequisites

- C/C++ compiler with C++11 support
- CMake (version 3.x or higher)
- SDL3 library

### Compilation

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

```bash
./Chip8Emulator <Scale> <Delay> <ROM>
```

### Parameters

- **Scale**: Display scaling factor (e.g., 10 for 640x320 window)
- **Delay**: Cycle delay in milliseconds (controls emulation speed)
- **ROM**: Path to the Chip-8 ROM file

### Example

```bash
./Chip8Emulator 10 2 roms/PONG.ch8
```

## Keyboard Layout

The Chip-8 hexadecimal keypad is mapped to the following keyboard keys:

```
Chip-8 Key   Keyboard
---------    --------
1 2 3 C      1 2 3 4
4 5 6 D      Q W E R
7 8 9 E      A S D F
A 0 B F      Z X C V
```

**ESC** - Exit emulator

## Project Structure

```
├── h/
│   ├── Chip8.hpp          # Chip-8 emulator class definition
│   └── Platform.hpp       # SDL3 platform wrapper
├── src/
│   ├── Chip8.cpp          # Chip-8 implementation
│   ├── Platform.cpp       # Platform implementation
│   └── main.cpp           # Entry point
├── libs/                  # SDL3 libraries
└── CMakeLists.txt         # Build configuration
```

## Implemented Opcodes

The emulator implements all standard Chip-8 opcodes including:

- Display operations (clear, draw sprites)
- Flow control (jump, call, return)
- Arithmetic and logic operations
- Memory operations
- Timers and sound
- Input handling

## Architecture

### Core Components

1. **Chip8 Class**: Main emulator logic
   - Fetch-decode-execute cycle
   - Opcode function pointer tables
   - Memory and register management

2. **Platform Class**: Graphics and input abstraction
   - SDL3 window and renderer management
   - Keyboard input processing
   - Display buffer updates

## Resources

- [Chip-8 Technical Reference](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)
- [Chip-8 Wikipedia](https://en.wikipedia.org/wiki/CHIP-8)

## License

This project is open source. Feel free to use, modify, and distribute.

## Acknowledgments

- Original Chip-8 specification by Joseph Weisbecker
- SDL3 library for cross-platform graphics
