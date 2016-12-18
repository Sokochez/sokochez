#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

/// type defining a line
typedef string CVLine;
/// type defining a matrix
typedef vector <string> CMatrix;
/// type defining a position
typedef pair <int, int> CPosition;
/// token (char) of player 1
const char KTokenPlayer1 = '1';
/// token (char) of player 1
const char KTokenPlayer2 = '2';

const char KTokenWall ('#');
const char KTokenBlock ('O');
const char KTokenEmpty (' ');

/**
 * @brief Loads the map from a file
 * @param FileName The name of the file
 * @return A vector of string containing the map
 */

CMatrix LoadMap (const string & FileName);

/**
 * @brief Finds the position of the player of same token in map
 * @param Map The map to parse
 * @param Token The token to find
 * @return A pair containing the x and y position in that order.
 * the pair contains the size of the map if the player is not found
 */

CPosition FindPlayer (const CMatrix & Map, const char & Token);

/**
 * @brief Checks if a map was loaded
 * @param Map The map to check
 * @return Returns true if the map has been correctly loaded
 */

bool CheckMapLoaded (const CMatrix & Map);

/**
 * @brief Checks if Map can be played (Have 2 Players)
 * @param Map The map to check
 * @return true if the map can be played
 */

bool IsMapValid (const CMatrix & Map);

#endif // MAP_H
