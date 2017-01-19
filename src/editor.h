/**
 * \file editor.h
 * \authors Baptiste Pouget, Dorian Tachet
 * \brief Functions and constants related to the editor mode
 */

#ifndef EDITOR_H
#define EDITOR_H
#include <map.h>
#include <cctype>
#include <string>

using namespace std;

const string KCursor = "7";

const unsigned KEditEmpty = 1;
const unsigned KEditWall = 2;
const unsigned KEditBlock = 3;
const unsigned KEditPlayer1 = 4;
const unsigned KEditPlayer2 = 5;
const unsigned KEditSpecialBlocks = 6;
const unsigned KEditSpecialLocations = 7;




/**
 * @brief Editor Starts the editor
 * @param FileName The name of the file
 */
void Editor (const string & FileName);

/**
 * @brief Places a token in the matrix
 * @param Mat the matrix the token will be placed on
 * @param Pos the position where to place the token
 * @param TokenKey the key corresponding to the token that will be placed
 * @param AvailableTokens the vector containing the tokens that can be placed
 */

void PlaceToken (CMatrix & Mat, const CPosition & Pos,
                 const char & TokenKey, vector <char> & AvailableTokens);

/**
 * @brief Does something in the editor
 * @param Mat the matrix to do something on
 * @param Cursor the cursor
 * @param Key the key pressed
 * @param AvailableTokens the vector containing available tokens
 * @param FileName the name of the file in use
 */

void EditorAction (CMatrix & Mat,CPosition & Cursor, const char & Key,
                   vector <char> & AvailableTokens, const string & FileName);

/**
 * @brief Moves the cursor and resizes the matrix if needed
 * @param Mat the matrix on which the cursor moves
 * @param Pos the position of the cursor
 * @param DistX the distance the cursor will move on the X axis
 * @param DistY the distance the cursor will move on the Y axis
 */

void MoveCursor (CMatrix &Mat, CPosition & Pos,
                 const int & DistX, const int & DistY);

/**
 * @brief Saves the matrix to a file
 * @param Mat the matrix to save
 * @param FileName the file where to save the matrix
 */

void SaveMatrix (const CMatrix & Mat, const string & FileName);

/**
 * @brief Displays the editor
 * @param Mat the matrix in use
 * @param Cursor the editor cursors
 * @param Tokens the available tokens
 */

void DispEditor (CMatrix & Mat, const CPosition &Cursor,
                 const vector <char> & Tokens);

/**
 * @brief Deletes empty lines and columns on right and bottom borders
 * @param Mat the matrix to optimize
 * @param Cursor the cursor
 */

void OptimizeMatrix (CMatrix & Mat, CPosition & Cursor);

/**
 * @brief Parses the matrix to fill the vector of available tokens correctly
 * @param Mat the matrix to parse
 * @param Tokens the vector of available tokens to fill
 */
void ParseMapEditor (const CMatrix & Mat, vector<char> & Tokens);

/**
 * @brief Returns if the character can be easily removed / is a common token
 * @param Ch the character to check
 * @return true if the character can be easily removed / is a common token else false
 */
bool IsCommonToken (const char & Ch);

/**
 * @brief Transforms a char into a digit (0-9)
 * @param Ch the char
 * @return a digit from 0 to 9 if the conversion was successfull else 10
 */

unsigned ChToDigit (const char & Ch);

#endif // EDITOR_H
