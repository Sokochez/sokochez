#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

/// type defining a line
typedef string CVLine;

/// type defining a matrix
typedef vector <string> CMatrix;

/// type defining a position
typedef pair <unsigned, unsigned> CPosition;

/// type defining a map of game items
typedef map <char, CPosition> GameObjects;

//Objects
const char KTokenPlayer1 ('1');
const char KTokenPlayer2 ('2');

/* Special blocks will be comprised between these values
 * and their destination if they have one will be the
 * char of the block in lowercase */

const char KTokenBlockMin ('A');
const char KTokenBlockMax ('H');

//Not Objects
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
 * @brief Returns a map of the objects in the game map assuming they are unique
 * @param Map the map to parse
 * @return A map of the objects
 */

GameObjects ParseMap (const CMatrix & Map);

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
