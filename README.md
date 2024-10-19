# 3D Maze using RayCasting in C

![Game Image](https://i.imgur.com/x8fbLiL.png)

Maze3D is a simple 3D maze game made entirely in C, inspired by the raycasting techniques used in early games like *Wolfenstein 3D*. The project features a custom map system, wall texture customization, and basic 3D rendering through a raycasting engine.

## Features

- **Raycasting Engine**: Maze3D uses a raycasting engine similar to *Wolfenstein 3D* to simulate a 3D environment. Rays are cast from the player's point of view, checking for intersections with walls in a 2D grid. The distance to these walls determines the height of vertical slices, creating a pseudo-3D effect.
  
- **Custom Map System**:
  - **Wall Textures**: You can customize the textures for the north, south, east, and west walls. Each texture should be a 512x512 png file.
  - **Map Creation**: Create your own maps using a simple grid where:
    - `1` represents a wall.
    - `0` represents empty space (walkable area).
  - **Player Start**: Set the player's starting position and direction by placing one of the following characters on the map:
    - `N` (North)
    - `S` (South)
    - `E` (East)
    - `W` (West)
  
- **Customizable Colors**:
  - Choose the color of the floor and ceiling using RGB values for added visual customization.

## How Raycasting Works

Raycasting is a technique used to render 3D projections based on a 2D map. In Maze3D, rays are cast from the player's position in a straight line, one for each vertical slice of the screen. These rays move through the grid and calculate the distance to the first wall they intersect. Based on the distance, the height of the wall is scaled proportionally, creating the illusion of depth.

## Map Format

Your custom map file must have a `.cub` extension and should look something like this:

![Map Image](https://i.imgur.com/SApI7Rd.png)

There is two maps already provided `backroom.cub` and `wolfenstein.cub`

## Usage

After compiling with `make`, launch the game by running `./cub3d <map_path>`.
