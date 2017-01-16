#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "map.h"
#include "display.h"
#include "editor.h"
#include "gameplay.h"

unsigned ChToDigit (const char & Ch)
{
    if ((Ch >= '0') || (Ch <= '9'))
        return Ch - '0';
    else
        return 0;
}

void PlaceToken (CMatrix & Mat, const CPosition & Pos,
                   const char & TokenKey, vector <char> & AvailableTokens)
{
    if (AvailableTokens[ChToDigit(TokenKey)] == KTokenPlayer1)
        AvailableTokens[ChToDigit(TokenKey)] = KTokenEmpty;
    else if (AvailableTokens[ChToDigit(TokenKey)] == KTokenPlayer2)
        AvailableTokens[ChToDigit(TokenKey)] = KTokenEmpty;
    else if ((AvailableTokens[ChToDigit(TokenKey)] < KTokenBlockMax )
        && (AvailableTokens[ChToDigit(TokenKey)] >= KTokenBlockMin))
    {
        ++AvailableTokens[ChToDigit(TokenKey)];
    }
    else if ((AvailableTokens[ChToDigit(TokenKey)] < tolower(KTokenBlockMax) )
        && (AvailableTokens[ChToDigit(TokenKey)] >= tolower(KTokenBlockMin)))
    {
        ++AvailableTokens[ChToDigit(TokenKey)];
    }
    else if ((AvailableTokens[ChToDigit(TokenKey)] < KTokenBlockMax )
        && (AvailableTokens[ChToDigit(TokenKey)] >= KTokenBlockMin))
    {
        ++AvailableTokens[ChToDigit(TokenKey)];
    }
    else if (AvailableTokens[ChToDigit(TokenKey)] == KTokenEmpty)
    {
        if (Mat[Pos.second][Pos.first] == KTokenPlayer1)
            AvailableTokens[KEditPlayer1] = KTokenPlayer1;
        else if (Mat[Pos.second][Pos.first] == KTokenPlayer2)
            AvailableTokens[KEditPlayer2] = KTokenPlayer2;
        else if (Mat[Pos.second][Pos.first] == AvailableTokens[KEditSpecialBlocks] - 1)
            --AvailableTokens[KEditSpecialBlocks];
        else if (Mat[Pos.second][Pos.first] == AvailableTokens[KEditSpecialLocations] - 1)
            --AvailableTokens[KEditSpecialLocations];
        else return;
    }
    else if ((AvailableTokens[ChToDigit(TokenKey)] == KTokenBlock)
        || (AvailableTokens[ChToDigit(TokenKey)] == KTokenWall)){}
    else return;
    Mat[Pos.second][Pos.first] = AvailableTokens[ChToDigit(TokenKey)];
}

void EditorAction (CMatrix & Mat,CPosition & Cursor,const char & Key, vector <char> & AvailableTokens)
{
    switch (Key) {
    case KP1MoveUp:
        MoveCursor(Mat, Cursor, 0, -1);
        break;
    case KP1MoveDown:
        MoveCursor(Mat, Cursor, 0, 1);
        break;
    case KP1MoveLeft:
        MoveCursor(Mat, Cursor, -1, 0);
        break;
    case KP1MoveRight:
        MoveCursor(Mat, Cursor, 1, 0);
        break;
    }
    if (ChToDigit(Key) >= 1)
        PlaceToken(Mat, Cursor, Key, AvailableTokens);
}

void MoveCursor (CMatrix & Mat, CPosition & Pos,
                 const int & DistX, const int & DistY)
{
    if (((int) Pos.first + DistX < 0) || ((int) Pos.second + DistY < 0)) return;
    if ((int) Pos.first + DistX >= (int) Mat[Pos.second].size())
    {
        for (string line : Mat)
            line.push_back(KTokenEmpty);
    }
    if ((int) Pos.second + DistY >= (int) Mat[Pos.first].size())
    {
        string newline (Pos.first + 1, KTokenEmpty);
        Mat.push_back(newline);
    }

}

/*void DispEditor (CMatrix & Mat, CPosition & Cursor,
                 const vector <char> & Tokens)
{

}*/


void Editor (const string & FileName)
{
    CMatrix map (LoadMap (FileName));
    char key;
    cout << "map loaded" << endl;
    ofstream ofs (FileName);
    if (!ofs.is_open ())
    {
        cout << "Cannot open this file" << endl;
        return;
    }

    while (true)
    {
        ClearScreen ();
        ShowMatrix (map);
        read (STDIN_FILENO, &key, 1);
    }


}

