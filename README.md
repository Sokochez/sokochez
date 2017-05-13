![Sokochez Logo](https://raw.githubusercontent.com/Sokochez/sokochez/master/logo.png)
[![Build Status](https://travis-ci.org/Sokochez/sokochez.svg?branch=master)](https://travis-ci.org/Sokochez/sokochez)

# sokochez
The Sokochez game

Sokochez is a multiplayer clone of sokoban.
The game is written in C++

## Building

To build Sokochez run `make`.
If you want to build Sokochez for an azerty keyboard :
`make DEF=-DKB_AZERTY`

## Playing

The arguments must be the names of the maps you want to load.

To start in editor mode, the first argument must be `-e`

Example:

`./sokochez map1.txt map2.txt`

The keys are `zqsd` and `oklm`, to open the menu, press `v`
