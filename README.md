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

To start in editor mode use the `-e` argument.

Example:

`./sokochez map1.txt map2.txt`

The keys are `zqsd` and `oklm` if compiled for azerty, if compiled for qwerty, the keys are `wsad` and `okl;`. To open the menu, press `v`.

## Other

Ignore sokochez-story, it is only used if you run `make install` and allows you to run all the default levels.  
