# 3D Maze using RayCasting in C

![Game Image](https://i.imgur.com/x8fbLiL.png)

Maze3D is a simple 3D maze game made entirely in C, inspired by the raycasting techniques used in early games like *Wolfenstein 3D*. The project features a custom map system and player movement.

## How Raycasting Works

Raycasting is a technique used to render 3D projections based on a 2D map. In Maze3D, rays are cast from the player's position in a straight line, one for each vertical slice of the screen. These rays move through the grid and calculate the distance to the first wall they intersect. Based on the distance, the height of the wall is scaled proportionally, creating the illusion of depth. More information [here](https://lodev.org/cgtutor/raycasting.html).

## Custom Map System
  
- **Wall Textures**: You can customize the textures for the north, south, east, and west walls. Each texture should be a 512x512 png file.
- **Map Creation**: Create your own maps using a simple grid where:
  - `1` represents a wall.
  - `0` represents empty space (walkable area).
- **Player Start**: Set the player's starting position and direction by placing one of the following characters on the map:
  - `N` (North)
  - `S` (South)
  - `E` (East)
  - `W` (West)
- **F and C colors**: Choose the color of the floor and ceiling using RGB values for added visual customization.
  - `F` or `C` followed by r,g,b values. (exemple below)

## Map Format

Your custom map file must have a `.cub` extension and should look something like this:

![Map Image](https://i.imgur.com/SApI7Rd.png)

There is two maps already provided `backroom.cub` and `wolfenstein.cub`

## Usage

After compiling with `make`, launch the game by running `./cub3d <map_path>`.

## Controls

- **Movement**:
  - `W` - Move forward
  - `A` - Move left
  - `S` - Move backward
  - `D` - Move right
- **Look Around**:
  - `Left Arrow` - Turn left
  - `Right Arrow` - Turn right

