# cub3D - 42 Heilbronn (May 2022)
## RayCasting with miniLibX.
This project is inspired by the world-famous Wolfenstein 3D game.<br>
It will enable you to explore ray-casting.<br>
Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.<br>

This project was done as a group project with [Esra Lenz](https://github.com/42elenz) <br>
![result](https://github.com/xhazm/cub3d/blob/master/resources/screen.png)
## Contents
- [Short description](https://github.com/xhazm/cub3d#short-description-of-the-project)
- [Our cub3D](https://github.com/xhazm/cub3d#our-cub3d)
  - [Requirements to run the game](https://github.com/xhazm/cub3d#requirements-to-run-the-game)
  - [How to cub3D](https://github.com/xhazm/cub3d#how-to-cub3d)
  - [Map requirements](https://github.com/xhazm/cub3d#map-requirements)
  - [Texture requirements](https://github.com/xhazm/cub3d#texture-requirements)

## Short description of the project

This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.<br><br>
As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.<br><br>
To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.<br><br>
With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.<br><br>

## Here you can see the result:
![Animated GIF](https://github.com/xhazm/cub3d/blob/master/resources/example.gif)

## Our cub3D
### Requirements to run the game
only tested on **macOS**<br>
For all other OS it is not guaranteed to work.<br>
OpenGL and AppKit is required to run it.<br>
If you want to run it on Linux [here](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux) is a tutorial that might help and [here](https://github.com/42Paris/minilibx-linux) is the required version of miniLibX, this is **not tested** with our cub3D.<br>
### How to cub3D
1. run `make` in the root of the directory
2. run `./cub3D maps/map` in the root of the directory
3. move the character with `WASD`
4. interact with the environment with f or g

Things to enjoy
- wall collition
- moving hands while walking
- fully customizable

[back to **Our cub3D**](https://github.com/xhazm/cub3d#our-cub3d)<br>
[back to **Contents**](https://github.com/xhazm/cub3d#contents)<br>

### Map requirements
- decide which texture is displayed on which side
- `0` define walkable spaces
- `1` define walls
- `T` define doors
- the players position is displayed by:
  - `N` player is facing north (top of the 2D map)
  - `E` player is facing east (right side of the 2D map)
  - `S` player is facing south (bottom of the 2D map)
  - `W` player us facing west (left side of the 2D map)
  - `R` defines where the rabbit is
- the map has to be enclosed by walls on all sides
- doors have to have walls on two opposite sides
- any other characters other than the ones above are forbidden
- if there is a ` `(space)&nbsp;inside the map it has to be enclosed by walls
- you have to set all the textures that should be used as wall texture i.e.
  - `WE images/1.xpm`
  - `EA images/2.xpm`
  - `SO images/3.xpm`
  - `NO images/4.xpm`
- you have to set the ceiling color, i.e.:
  - `C 0, 183, 183`
- you have to set the floor color, i.e.:
  - `F 141, 1, 126`

[back to **Our cub3D**](https://github.com/xhazm/cub3d#our-cub3d)<br>
[back to **Contents**](https://github.com/xhazm/cub3d#contents)<br>

### Texture requirements
The wall textures as well as the door texture is interchangeable, as long as:<br>
- the texture is 64 by 64 pixels
- the texture is a .xpm file

If you want to change the windowsize, this can be done in the [cub3d_define.h](https://github.com/xhazm/cub3d/blob/master/include/cub3d.h) file.<br>


[back to **Our cub3D**](https://github.com/xhazm/cub3d#our-cub3d)<br>
[back to **Contents**](https://github.com/xhazm/cub3d#contents)<br>

