# Brick Breaker GBA

A classic Brick Breaker game implementation for Game Boy Advance written in C.

## Overview

Brick Breaker is an arcade-style game where players control a paddle to bounce a ball and break bricks. This implementation is designed specifically for the Game Boy Advance handheld console.

## Game Objective

Your goal is simple: break all the bricks on the screen without letting the ball fall below your paddle. Each time the ball hits a brick, the brick breaks. Break all bricks to win the game!

## Controls

- **START Button**: Start the game
- **A Button**: Launch the ball from the paddle
- **LEFT Button**: Move the paddle left
- **RIGHT Button**: Move the paddle right
- **SELECT Button**: Return to the start screen at any time

## Gameplay Mechanics

- The ball will bounce off walls, bricks, and the paddle
- Position your paddle to prevent the ball from falling off the bottom of the screen
- The game is won when all bricks are broken
- The game is lost when the ball falls below the paddle

## Installation

### Prerequisites
- Game Boy Advance emulator (such as mGBA, VisualBoyAdvance, or a physical GBA with a flash cart)
- GBA ROM file (`brickbreaker.gba`)

### Running the Game
1. Download the ROM file from the releases section
2. Open your GBA emulator
3. Load the ROM file
4. Enjoy the game!

## Building from Source

### Prerequisites
- devkitPro with devkitARM
- libgba

### Build Instructions
1. Clone this repository:
   ```
   git clone https://github.com/yourusername/brickbreaker_gba.git
   cd brickbreaker_gba
   ```
2. Compile the source:
   ```
   make
   ```
3. The ROM file will be generated in the project directory

## Development Notes

This project is written in C and uses the GBA hardware capabilities including:
- Custom sprite handling for the paddle and ball
- Collision detection systems
- Simple physics for ball movement and bouncing

## Contributions

Contributions are welcome! If you'd like to improve the game, fix bugs, or add features, please:
1. Fork the repository
2. Create your feature branch
3. Submit a pull request

## Author

- Andrew Alvarez

## License

This project is open source and available under the [MIT License](LICENSE).

## Acknowledgments

- Thanks to the GBA development community for resources and support
- Inspired by classic brick breaking games

---

HAVE FUN! :D
