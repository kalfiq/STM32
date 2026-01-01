# STM32
This is not a product-oriented repository. It is purely for exploration purposes.
Main objectives:
1. How can I structure a project to make it as portable as possible for various platforms?
2. What can I measure to put some metrics on program performance during development?
3. How can I measure those metrics?
4. What workflow should I adopt to minimize my reliance on hardware to develop the code?

## My machine
- Ubuntu 22.04
- Arch Linux 6.18.2-arch2-1

## Dependencies
```
sudo apt install cmake                                          # For generating cross-platform build systems
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi       # ARM toolchain to compile code for ARM architecture
sudo apt install openocd                                        # For flashing binaries to the MCU
```

## Project structure
Below shows the structure of the main components in my code architecture.
```
├── App
    ├── CMakeLists.txt
    ├── Logger
    ├── Main.c
    ├── Tests
    └── Utilities
├── Platform
    ├── CMake
    ├── CMakeLists.txt
    └── STM32F722
```
### App
Stores code that contain higher level logic that should be independent from the platform interfaces.

### Platform
Stores code that contain lower level logic where the program needs to interact with the hardware interfaces. Targeted platforms:
- STM32F722 (Not yet implemented)
- ATMel328P (Not yet implemented)
