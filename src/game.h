#ifndef GAME_H
#define GAME_H

#include <map.h>
#include <display.h>
#include <gameplay.h>
#include <istream>
#include "input.h"
#include <cstdlib>

using namespace std;

/**
 * @brief The main game function
 * @param FileName The name of the file containing the map of the game
 */

void Game (const string & FileName);

/**
 * @brief Displays the menu
 */

void DispMenu ();

#endif // GAME_H
