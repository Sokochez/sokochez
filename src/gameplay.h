/**
 * \file gameplay.h
 * \authors Baptiste Pouget
 * \brief Functions and constants related to gameplay
 */

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "map.h"
#include <cctype>

using namespace std;

#if defined(KB_AZERTY) || defined(KB_ARROWS)
const char KP1MoveUp = 'z';
const char KP1MoveDown = 's';
const char KP1MoveLeft = 'q';
const char KP1MoveRight = 'd';
const char KP2MoveUp = 'o';
const char KP2MoveDown = 'l';
const char KP2MoveLeft = 'k';
const char KP2MoveRight = 'm';

#else
const char KP1MoveUp = 'w';
const char KP1MoveDown = 's';
const char KP1MoveLeft = 'a';
const char KP1MoveRight = 'd';
const char KP2MoveUp = 'o';
const char KP2MoveDown = 'l';
const char KP2MoveLeft = 'k';
const char KP2MoveRight = ';';
#endif //KB

const char KMenu = 'v';
const char KKeyReset = '1';
const char KSkip = '2';
const char KExit = '3';

#if defined(KB_ARROWS)
char arrowsToKey(char key);
bool isGarbage(char key);
//arrows
const char KuseP1 = 9; //tab
const char KuseP2 = 127; //backspace
const char KuseMenu = 10; //space
const char KarrowUp = 'A';
const char KarrowDown = 'B';
const char KarrowLeft = 'D';
const char KarrowRight = 'C';
#define M_MENU 0
#define M_P1 1
#define M_P2 2
#endif

//Gamemodes
const int KGMNone = 0;
const int KGMPlayersMeet = 1;
const int KGMBlocksMeet = 2;
const int KGMClear = 3;

/**
 * @brief Moves a token located at some position at another position
 * @param Mat The matrix the token is on
 * @param Objects The Special objects of the map
 * @param Pos The position of the token
 * @param DistX The distance on the X axis
 * @param DistY The distance on the Y axis
 * @return If the move was successful
 */


bool Move (CMatrix & Mat, GameObjects & Objects, CPosition & Pos, const int & DistX, const int & DistY);

/**
 * @brief Does something depending on the key
 * @param Mat The matrix
 * @param Objects The Objects
 * @param Key The Key
 */
/**
 * @brief Does something depending on the key
 * @param Mat The matrix
 * @param Objects The Objects
 * @param Key The Key
 * @return true if the action is successful
 */

bool Action (CMatrix & Mat, GameObjects & Objects, const char & Key);

/**
 * @brief Checks if there is a win
 * @param Objects The game objects
 * @param GameMode The game mode
 * @return true if there is a victory
 */

bool CheckWin (GameObjects & Objects, const int & GameMode);

/**
 * @brief Determines the game mode depending on the objects in GameObjects
 * @param Objects The GameObjects map
 * @return The gamemode found depending on the objects
 */

int GetGamemode (const GameObjects & Objects);

/**
 * @brief Checks if the object exists or not
 * @param Objects The objects that will be checked
 * @param Key The key of the object that is being looked for
 * @return true if the object exists in the Map
 */

bool ObjectExists (const GameObjects & Objects, const char & Key);

/**
 * @brief Writes the rules of a gamemode
 * @param GameMode The gamemode
 */

void WriteRules (const char & GameMode);

/**
 * @brief Determines if two positions are in contact
 * @param Pos1 The first position
 * @param Pos2 The second position
 * @return true if the positions are in contact
 */

bool AreInContact (const CPosition & Pos1, const CPosition & Pos2);



#endif // GAMEPLAY_H
