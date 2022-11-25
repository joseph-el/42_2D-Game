<h1 align="center">
	42 SO_LONG 
</h1>

<p align="center">
	<b><i> 2D game, Get familiar with the minilibix_42 library and UI in general🌒 </i></b><br>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/joseph-el/42_2D-Game?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/joseph-el/42_2D-Game?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/joseph-el/42_2D-Game?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/joseph-el/42_2D-Game?color=green" />

</p>
  <p align="center">
    <a href="https://github.com/anuraghazra/github-readme-stats/actions">
      <img alt="Tests Passing" src="https://github.com/anuraghazra/github-readme-stats/workflows/Test/badge.svg" />
    </a>
    <a href="https://github.com/anuraghazra/github-readme-stats/graphs/contributors">
      <img alt="GitHub Contributors" src="https://img.shields.io/github/contributors/anuraghazra/github-readme-stats" />
    </a>
    <a href="https://codecov.io/gh/anuraghazra/github-readme-stats">
      <img src="https://codecov.io/gh/anuraghazra/github-readme-stats/branch/master/graph/badge.svg" />
    </a>
    <a href="https://github.com/anuraghazra/github-readme-stats/issues">
      <img alt="Issues" src="https://img.shields.io/github/issues/joseph-el/42_2D-Game?color=0088ff" />
    </a>
    <a href="https://github.com/anuraghazra/github-readme-stats/pulls">
      <img alt="GitHub pull requests" src="https://img.shields.io/github/issues-pr/joseph-el/42_2D-Game?color=0088ff" />
    </a>
  </p>
 
<h3 align="center">

![2D](https://user-images.githubusercontent.com/80905157/203984552-3c06c0ef-e930-441a-82ee-d8b8c4c3a4b6.jpeg)
 
</h3>
 
---
### Table of Contents

* [About](#about-project)
* [Game rules](#game-rules)
* [How it works](#how-it-works)
* [Controls](#control)
* [Installation](#cloning-the-repositories)
* [Source](#source)
* [Screenshot ](#screenshot)
* [Summary](#summary)

 ## About project
this project, we'll code a simple 2D game to get familiar with the minilibix_42 library and UI in general. In my case it will be ninja.

### Game Rules
The game we choose must follow a set of rules. The executable ``so_long`` and ``so_long_bonus`` for bonus part, They will receive a map as the only argument, and the map file name should be a ``.ber`` filetype.

To run the game, we must write a valid map according to the following rules :
- Only ``P`` *(ninja)*, ``1`` *(wall)*, ``0`` *(free space)*, ``C`` *(key 🔑)*, and ``E`` *(exit)* will be accepted ``Z`` *(enemy)* in our map (except if you add enemies as bonus)
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

### The player has to reach all keys to finish the game
- in this one you need to know [flood fill](https://www.youtube.com/results?search_query=flood+fill+algorithm+in+c) algorithm

If any of these checks fail, the game must end with ``Error\n`` followed by a error type.
 
## How it Works
For the graphics part of the project we used a library called ``minilibx`` by :
   ```C
 #include <mlx.h>
```
#### Part 1: read map from file

In this step after validating the map then continued by reading the file  line by line with [get_next_line](https://github.com/joseph-el/42_get_next_line).
Once that was done I filled a struct ``t_data`` with some basic map attributes like number of players, exits, key, number of rows and columns, etc. whcih was later useful when creating a matrix with [ft_split](https://github.com/joseph-el/42_libft_project/blob/master/ft_split.c). with ``\n`` as the separator.

#### Part 2: installation 

### Cloning the repositories
```shell
git clone https://github.com/joseph-el/42_so_long_2Dgame.git
cd so_long
make
```

### Installing the MLX library

* ``Linux``

If you're not using a MacOS computer from 42, you'll need to install the libraries manually. Please refer to the [official github](https://github.com/42Paris/minilibx-linux) for more details. To install it, do the following (requires root access):

```shell
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
sudo cp mlx.h /usr/include
sudo cp libmlx.a /usr/lib
```

* ``MacOS``

To install the library, you will need to first install a package manager like homebrew (check [here](https://brew.sh/)) to then install the X11 package with ``brew install Xquartz``. After that you must extract the minilibx file called ``minilibx_opengl.tgz``. Then install it to your system with the following commands (requires sudo as well):

```shell
cd minilibx_opengl
make
sudo cp mlx.h /usr/local/include
sudo cp libmlx.a /usr/local/lib
sudo reboot
```
Note: A reboot is necessary to ensure that the ``Xquartz`` is working properly. You can test if it is by running a test example with the command ``xeyes``.

### Installing the manuals

If you want quick access to the mlx manuals, it is recommended that you copy the files from the ``man`` folder in [minilibx-linux](https://github.com/42Paris/minilibx-linux) to your system manuals:

* ``Linux``
```shell
sudo cp man/man3/* /usr/share/man/man3/
```
Note: Depending on your Linux configuration, to get the manuals working (e.g. ``man mlx``) you will need to individually gzip all the manual files you just copied, e.g. ``sudo gzip /usr/share/man/man3/mlx.3``.

* ``MacOS``
```shell
sudo cp man/man3/* /usr/X11/share/man/man3
```


#### Part 3: How to play
---
###### Maps
* the map can only contain some of the following characters:

| Character | Object |
| - | - |
| 1 | Wall. |
| 0 | free space. |
| C | key. |
| E | Exit. |
| P | Player position. |
| Z | Enemy (bonus part)|

###### Control
- Use 'WASD' to move. You move the player every time, in the bonus part when you add some enemies (fire), you will die when you move in the fire.
- After picking up all the keys, the exits open and you can leave to see how many moves you used to solve the map.
- You can close it with ``esc``.

###### Execute the game
for start play you can use some of the makefile rules, or execute the file ``so_long/so_long_bonus`` if it's been generated, passing the map you want to play as parameter (``./so_long "path of your map"``). The make file has the following rules:

| Rule | Function |
| - | - |
| ``make`` | Generates tools.a liberty and so_long executable |
| ``make bonus`` | Generates tools.a liberty and so_long_bonus executable |
| ``make clean`` | Deletes all object files of tools.a and so_long/so_long_bonus|
| ``make fclean`` | Deletes tools.a and the object files of tools.a and the so_long/so_long_bonus|
| ``make re`` | makes ``fclean`` and ``make`` again. |


## Gameplay

<h1 align="center">
	
https://user-images.githubusercontent.com/80905157/203806808-a1c92f60-c556-488f-8b65-5a0f9e4a82ed.mp4
	
</h1>

## Screenshot 
<h1 align="center">
	screen 1 
</h1>
<img width="1236" alt="screen1" src="https://user-images.githubusercontent.com/80905157/203793326-1bb17850-9624-43ae-a643-efb66dfb1910.png">
<h1 align="center">
	screen 2 
</h1>
<img width="574" alt="Screen2" src="https://user-images.githubusercontent.com/80905157/203793580-4f65d96d-769d-4204-b8d8-977537f8e6b5.png">
<h1 align="center">
	screen 3 
</h1>
<img width="1005" alt="screen4" src="https://user-images.githubusercontent.com/80905157/203793646-e80d3d7e-572c-4415-8ff5-6eb98f0d5cd5.png">
<h1 align="center">
	screen 4 
</h1>
<img width="1236" alt="screen5" src="https://user-images.githubusercontent.com/80905157/203793713-036189d3-6671-452b-8da5-1c55300fc74c.png">
<h1 align="center">
	screen 5 
</h1>
<img width="1005" alt="screen3" src="https://user-images.githubusercontent.com/80905157/203793611-129f2c7c-4f70-4af1-81d5-2fc2c6c09bea.png">

## Source
##### 42 mlx

- [42 mlx docs](https://harm-smits.github.io/42docs/libs/minilibx)
- [42 mlx blog](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx)
- [Basic introduction, tutorials, tips & tricks](https://gontjarow.github.io/MiniLibX/)

## Summary

> This has been my favorite project so far, coding my own 2d game was so much fun :)
	
November  24th, 2022
