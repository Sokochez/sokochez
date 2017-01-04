#include <game.h>
#include <istream>
#include "input.h"
#include <cstdlib>

using namespace std;

void Game (const string & FileName)
{
    CMatrix map (LoadMap (FileName));
    if (!CheckMapLoaded (map))
    {
        cout << "Error : Map not loaded correctly" << endl;
        return;
    }
    GameObjects obj (ParseMap(map));
    int gamemode (GetGamemode(obj));
    if (gamemode == KGMNone)
    {
        cout << "Error : Gamemode could not be determined" << endl;
        return;
    }

    ClearScreen ();
    char key;
    unsigned nbmoves (0);
    cout << "Loaded map " << FileName << endl;

    WriteRules (gamemode);
    cout << "Press a key to begin" << endl;
    getchar();

    while (!CheckWin (obj, gamemode))
    {
        ClearScreen ();
        ShowMatrix (map);
        read (STDIN_FILENO, &key, 1);
        if (KMenu == key)
        {
            do
            {
                DispMenu ();
                read (STDIN_FILENO, &key, 1);
                switch (key)
                {
                case KKeyReset:
                    Game (FileName);
                    return;
                    break;
                case KSkip:
                    return;
                    break;
                case KExit:
                    exit(0);
                    break;
                default:
                    break;
                }

            } while (key != KMenu);
            ClearScreen ();
            ShowMatrix (map);
            read (STDIN_FILENO, &key, 1);
        }
        Action (map, obj, key);
        ++nbmoves;
    }
    ClearScreen ();
    cout << "Victory ! You won in " << nbmoves << " moves !" << endl;
    getchar ();
} // Game

void DispMenu ()
{
    ClearScreen ();
    cout << "1) Reset"   << endl
         << "2) Skip this map" << endl
         << "3) Exit" << endl;

}
