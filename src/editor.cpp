#include "map.h"
#include <iostream>
#include <fstream>
#include <string>
#include "display.h"
#include "editor.h"
#include <unistd.h>

void PlaceToken (CMatrix & Mat, const CPosition & Pos, const char & Token)
{
    Mat[Pos.second][Pos.first] = Token;
}

void MoveCursor (CMatrix & Mat, CPosition & Pos, const int & DistX, const int & DistY)
{

}

/*
char MenuEditor (char & Key)
{
    switch (Key)
    {
    case KEditEmptyToken:
        TokenSelected = KTokenEmpty;
        return TokenSelected;
    case KEditWallToken:
        TokenSelected = KTokenWall;
        return TokenSelected;
    case KEditBlockToken:
        TokenSelected = KTokenBlock;
        return TokenSelected;
    case KEditPLayersToken:
        return TokenSelected;
    case KEditSpecialBlocks:
        TokenSelected = ' ' ;
        return TokenSelected;
    case KEditSpecialLocations:
        TokenSelected = ' ' ;
        return TokenSelected;

    }
}

*/


void Editor (const string & FileName)
{
    char key;
    CMatrix map (LoadMap (FileName));
    cout << "map loaded" << endl;
    ofstream ofs (FileName);
    if (!ofs.is_open ())
    {
        cout << "Cannot open this file" << endl;
        return;
    }
    while (true)
    {
        char TokenSelected;
        read (STDIN_FILENO, &key, 1);
        ClearScreen ();
        ShowMatrix (map);
        MenuEditor (key);


    }


}

