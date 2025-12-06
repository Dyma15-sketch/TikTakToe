# TikTakToe

**TikTakToe** is a C++ implementation of the classic Tic-Tac-Toe (X and O) game. This project provides a complete game engine with a modular architecture, supporting both console-based and graphical (SFML) rendering.

## Project Description

TikTakToe is a strategic two-player game implemented in C++ using modern C++17 features. The project is organized into a library component (`libTikTakToe`) containing the core game logic and an application component (`app`) providing the user interface.

### Architecture

The project follows a modular design with the following components:

- **libTikTakToe**: Core game library containing:
  - `Player`: Represents a player (X, O, or None)
  - `Board`: Manages the 3x3 game board
  - `GameEngine`: Coordinates game state and turn management
  - `Rules`: Handles win condition checking and game rules

- **app**: Application layer containing:
  - `Visual`: Handles display and rendering (console and SFML)
  - `main.cpp`: Application entry point with player vs computer gameplay

The project uses CMake for build configuration and supports both console output and optional SFML-based graphical rendering.

## Game Rules

Tic-Tac-Toe is played on a 3x3 grid by two players who take turns placing their marks (X and O).

### Objective

The goal is to be the first player to get three of their marks in a row:
- **Horizontally** (any row)
- **Vertically** (any column)
- **Diagonally** (main diagonal or anti-diagonal)

### Game Flow

1. The game starts with an empty 3x3 board
2. Player X makes the first move
3. Players alternate turns, placing their mark in an empty cell
4. A player cannot place a mark in an already occupied cell
5. The game ends when:
   - A player achieves three marks in a row (that player wins)
   - All nine cells are filled with no winner (draw/tie)

### Win Conditions

A player wins by having three consecutive marks in:
- Any horizontal row (3 rows possible)
- Any vertical column (3 columns possible)
- The main diagonal (top-left to bottom-right)
- The anti-diagonal (top-right to bottom-left)

If the board is completely filled and no player has achieved three in a row, the game results in a draw.

## Dependencies

### Development Environment

- **Operating System**: Windows, Linux, or macOS
- **Build System**: CMake 3.16 or higher
- **Compiler**: C++17 compatible compiler
  - **Windows**: MinGW-w64 (GCC), MSVC, or Clang
  - **Linux**: GCC 7+ or Clang 5+
  - **macOS**: Xcode Command Line Tools (Clang)

### Required Libraries

- **Standard C++ Library**: C++17 standard library (included with compiler)
- **CMake**: Version 3.16 or higher

### Optional Libraries

- **SFML 2.5** (optional): For graphical rendering
  - Components: `graphics`, `window`, `system`
  - If SFML is found during configuration, the application will support graphical display
  - If SFML is not available, the application will use console output only

### Build Tools

The project uses CMake with Ninja or Make as the underlying build system. CMake will automatically detect and configure the appropriate build tool for your platform.

## Building the Application

### Prerequisites

1. Install CMake 3.16 or higher
2. Install a C++17 compatible compiler
3. (Optional) Install SFML 2.5 if you want graphical support

### Build Steps

#### 1. Clone or Navigate to the Project Directory

```bash
cd TikTakToe
```

#### 2. Create a Build Directory

```bash
mkdir build
cd build
```

#### 3. Configure the Project with CMake

```bash
cmake ..
```

Or if you prefer to use a specific generator:

```bash
# For Ninja (faster, recommended)
cmake -G Ninja ..

# For Visual Studio (Windows)
cmake -G "Visual Studio 17 2022" ..

# For Make (Unix/Linux/macOS)
cmake -G "Unix Makefiles" ..
```

#### 4. Build the Project

```bash
# If using Ninja
cmake --build .

# If using Make
make

# Or use CMake's build command (works with any generator)
cmake --build .
```

#### 5. Run the Application

After building, the executable will be located at:

```bash
# Windows
build\app\TikTakToeApp.exe

# Linux/macOS
build/app/TikTakToeApp
```

Run it from the build directory:

```bash
# Windows
.\app\TikTakToeApp.exe

# Linux/macOS
./app/TikTakToeApp
```

### Building and Running Tests

The project includes a comprehensive test suite. To build and run tests:

```bash
# From the build directory
cmake --build . --target TikTakToeTests

# Run tests
./tests/TikTakToeTests        # Linux/macOS
.\tests\TikTakToeTests.exe    # Windows

# Or use CTest
ctest
```

### Clean Build

To clean the build directory and start fresh:

```bash
# Remove the build directory
rm -rf build  # Linux/macOS
rmdir /s /q build  # Windows

# Or from within the build directory
cmake --build . --target clean
```

### Build Options

The project automatically detects SFML if it's installed. To explicitly disable SFML support or specify its location, you can use CMake variables:

```bash
# Disable SFML (console only)
cmake -DUSE_SFML=OFF ..

# Specify SFML path (if not in standard locations)
cmake -DSFML_ROOT=/path/to/sfml ..

# Disable tests (if needed)
cmake -DBUILD_TESTS=OFF ..
```

### Project Structure

```
TikTakToe/
├── CMakeLists.txt          # Root CMake configuration
├── libTikTakToe/           # Core game library
│   ├── CMakeLists.txt
│   ├── include/            # Header files
│   │   ├── board.hpp
│   │   ├── game_engine.hpp
│   │   ├── player.hpp
│   │   └── rules.hpp
│   └── src/                # Source files
│       ├── board.cpp
│       ├── game_engine.cpp
│       ├── player.cpp
│       └── rules.cpp
├── app/                    # Application layer
│   ├── CMakeLists.txt
│   ├── include/
│   │   └── visual.hpp
│   └── src/
│       ├── main.cpp
│       └── visual.cpp
├── tests/                  # Unit tests
│   ├── CMakeLists.txt
│   ├── test_framework.hpp
│   ├── test_main.cpp
│   ├── test_player.cpp
│   ├── test_board.cpp
│   ├── test_rules.cpp
│   └── test_game_engine.cpp
├── build/                  # Build output (generated)
└── docs/                   # Documentation (generated by Doxygen)
```

### Generating Documentation

To generate API documentation using Doxygen:

```bash
# From the project root
doxygen Doxyfile
```

The documentation will be generated in the `docs/html` directory. Open `docs/html/index.html` in a web browser to view it.

---

## License

Copyright (c) 2025 Ermurachi Dmitri
