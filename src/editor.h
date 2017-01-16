#ifndef EDITOR_H
#define EDITOR_H
#include <map.h>
#include <cctype>
#include <string>

using namespace std;

const string KTokenCursor("53");

const unsigned KEditEmpty (1);
const unsigned KEditWall (2);
const unsigned KEditBlock (3);
const unsigned KEditPlayer1 (4);
const unsigned KEditPlayer2 (5);
const unsigned KEditSpecialBlocks (6);
const unsigned KEditSpecialLocations (7);




/**
 * @brief Editor Starts the editor
 * @param FileName The name of the file
 */
void Editor (const string & FileName);

void PlaceToken (CMatrix & Mat, const CPosition & Pos,
                 const char & TokenKey, vector <char> & AvailableTokens);
void EditorAction (CMatrix & Mat, CPosition & Cursor, char & Key, vector<char> &AvailableTokens);

void MoveCursor (CMatrix & Mat, CPosition & Pos,
                 const int & DistX, const int & DistY);

void DispEditor (CMatrix & Mat, CPosition & Cursor,
                 const vector <char> & Tokens);

#endif // EDITOR_H
