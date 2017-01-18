#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <cctype>

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
const char KTokenPlayer1 = '1';
const char KTokenPlayer2 = '2';

/* Special blocks will be comprised between these values
 * and their destination if they have one will be the
 * char of the block in lowercase */

const char KTokenBlockMin = 'A';
const char KTokenBlockMax = 'H';

//Not Objects
const char KTokenWall = '#';
const char KTokenBlock = '&';
const char KTokenEmpty = ' ';


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


/**
 * @brief Returns wether the token at Pos on the matrix Mat is a player token or not
 * @param Mat The matrix
 * @param Pos The position to check
 * @return true if token at position Pos is a player token
 */

bool IsPlayer (const CMatrix & Mat, const CPosition & Pos);

/**
 * @brief Checks if char is a block object char
 * @param Ch the char to check
 * @return true if the char is a block char
 */

bool IsBlock (const char & Ch);

/**
 * @brief Checks if char is a special block object char
 * @param Ch the char to check
 * @return true if the char is a special block char
 */

bool IsSpecBlock (const char & Ch);

/**
 * @brief Checks if char is a special position char
 * @param Ch the char to check
 * @return true if the char is a special position char
 */

bool IsSpecPos (const char & Ch);


#endif // MAP_H
