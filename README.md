# ATmega32 Interface: 3x4 Keypad & LCD Display

This project demonstrates a functional interface using an **ATmega32** microcontroller, featuring a **3x4 Matrix Keypad** and a **16x2 LCD** screen.

## Technical Features
- **3x4 Matrix Keypad Scanning:** Implemented logic to detect button presses from a 3-column, 4-row matrix.
- **4-bit LCD Communication:** Configured to use only 4 data lines to save microcontroller I/O pins.
- **Hardware Simulation:** Fully designed and verified within the **Proteus** environment.

## Tools Used
- **CodeVisionAVR:** Used for C programming and generating the HEX file.
- **Proteus:** Used for circuit design and real-time hardware simulation.

##Environment
-CodeVisionAVR v3.12
-Proteus 8 Professional
-ATmega32 Microcontroller

## How to use
The repository includes:
- `Code/`: Source code (`.c`) and CodeVision project files (`.prj`).
- `Simulation/`: Proteus schematic (`.pdsprj`) and the compiled `.hex` file.

To run, simply open the Proteus file and load the HEX file onto the ATmega32.

