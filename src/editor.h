#ifndef EDITOR_H
#define EDITOR_H
#include <map.h>
#include <cctype>
#include <string>

using namespace std;

const string KCursor ("7");

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
void EditorAction (CMatrix & Mat,CPosition & Cursor, const char & Key,
                   vector <char> & AvailableTokens, const string & FileName);

void MoveCursor (CMatrix &Mat, CPosition & Pos,
                 const int & DistX, const int & DistY);
void SaveMatrix (const CMatrix & Mat, const string & FileName);

void DispEditor (CMatrix & Mat, const CPosition &Cursor,
                 const vector <char> & Tokens);
void OptimizeMatrix (CMatrix & Mat, CPosition & Cursor);


#endif // EDITOR_H
