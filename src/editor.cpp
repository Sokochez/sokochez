#include "map.h"
#include <iostream>
#include <fstream>
#include <string>
#include "display.h"
#include "editor.h"
#include <unistd.h>
#include "gameplay.h"

bool ActionEditor (CMatrix & Mat, GameObjects & Objects, const char & Key)
{
    switch (Key) {
    case KEditorUp:
        Move (Mat, Objects, Objects[KTokenEditor], 0, -1);
        break;
    case KEditorDown:
        Move (Mat, Objects,  Objects[KTokenEditor], 0, 1);
        break;
    case KEditorLeft:
        Move (Mat, Objects,  Objects[KTokenEditor], -1, 0);
        break;
    case KEditorRight:
        Move (Mat, Objects,  Objects[KTokenEditor], 1, 0);
        break;
    default:
        return false;
    }
    return true;
}


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
        ClearScreen ();
        ShowMatrix (map);
        read (STDIN_FILENO, &key, 1);
        ActionEditor(map, obj, key);



    }


}

