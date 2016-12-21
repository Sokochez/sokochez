#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <map.h>

using namespace std;

const char KP1MoveUp = 'z';
const char KP1MoveDown = 's';
const char KP1MoveLeft = 'q';
const char KP1MoveRight = 'd';
const char KP2MoveUp = 'o';
const char KP2MoveDown = 'l';
const char KP2MoveLeft = 'k';
const char KP2MoveRight = 'm';
const char KMenu = 'y';

//Gamemodes
const int KGMNone (0);
const int KGMPlayersMeet (1);
const int KGMBlocksMeet (2);
const int KGMClear (3);

/**
 * @brief Moves a token located at some position at another position
 * @param Mat The matrix the token is on
 * @param Pos The position of the token
 * @param DistX The distance on the X axis
 * @param DistY The distance on the Y axis
 * @return If the move was successful
 */

bool Move(CMatrix & Mat, CPosition & Pos, const int & DistX, const int & DistY);

/**
 * @brief Does something depending on the key passed
 * @param Mat The matrix to do something on
 * @param Key The key that defines the action
 * @param Player1 The Player 1
 * @param Player2 The Player 2
 */

void Action(CMatrix & Mat, const char & Key, CPosition & Player1, CPosition & Player2);

/**
 * @brief Returns wether the token at Pos on the matrix Mat is a player token
 * @param Mat The matrix
 * @param Pos The position to check
 * @return true if token at position Pos is a player's token
 */

bool IsPlayer (const CMatrix & Mat, const CPosition & Pos);

/**
 * @brief Checks if the player 1 reached player 2
 * @param Pos1 Position of player 1
 * @param Pos2 Position of player 2
 * @return True if player 1 is at the same pos as player 2
 */

bool CheckWin (const CPosition & Pos1, const CPosition & Pos2);

#endif // GAMEPLAY_H
