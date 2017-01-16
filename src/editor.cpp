#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "map.h"
#include "display.h"
#include "editor.h"
#include "gameplay.h"
#include "display.h"

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
    char toplace = AvailableTokens[ChToDigit(TokenKey)];
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
        else if ((AvailableTokens[ChToDigit(TokenKey)] == KTokenBlock)
            || (AvailableTokens[ChToDigit(TokenKey)] == KTokenWall)){}
        else return;
    }
    else if ((AvailableTokens[ChToDigit(TokenKey)] == KTokenBlock)
        || (AvailableTokens[ChToDigit(TokenKey)] == KTokenWall)){}
    else return;
    Mat[Pos.second][Pos.first] = toplace;
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
        for (string & line : Mat)
            line.push_back(KTokenEmpty);
    }
    if ((int) Pos.second + DistY >= (int) Mat.size())
    {
        string newline (Mat[0].size(), KTokenEmpty);
        Mat.push_back(newline);
    }
    Pos.second += DistY;
    Pos.first += DistX;

}

void DispEditor (CMatrix & Mat, const CPosition & Cursor, const vector <char> & Tokens)
{
    for (unsigned i (0); i < Tokens.size()-1; ++i)
        cout << Tokens[i+1] << '|';
    cout << endl;
    for (unsigned i (1); i < Tokens.size(); ++i)
        cout << i << '|';
    cout << endl;
    for (unsigned i (0); i < Mat.size(); ++i)
    {
        cout << '|';
        for (unsigned j (0); j < Mat[i].size() ; ++j)
        {
            if ((i == Cursor.second) && (j == Cursor.first)) Color(KCursor);
            cout << Mat[i][j];
            if ((i == Cursor.second) && (j == Cursor.first)) Color(KReset);
        }
        cout << '|' << endl;
    }
}



void Editor (const string & FileName)
{
    vector <char> tokens {'|', KTokenEmpty, KTokenWall,KTokenBlock,KTokenPlayer1,KTokenPlayer2,
                     KTokenBlockMin, 'a'};
    CMatrix map (LoadMap (FileName));
    if (!CheckMapLoaded(map))
    {
        map.push_back(" ");
    }
    CPosition cursor (0,0);
    char key;
    cout << "map loaded" << endl;
    ofstream ofs (FileName);
    if (!ofs.is_open ())
    {
        cout << "Cannot open this file" << endl;
        return;
    }

    while (key != '0')
    {
        ClearScreen ();
        DispEditor(map, cursor, tokens);
        read (STDIN_FILENO, &key, 1);
        EditorAction(map, cursor, key, tokens);
    }
    for (string line : map)
    {
        ofs << line << endl;
    }

}

