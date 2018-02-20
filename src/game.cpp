#include "game.h"
#include <istream>
#include "input.h"
#include <cstdlib>
#include <string>

using namespace std;

void Game (const string & FileName)
{
    string solution;
    CMatrix map (LoadMap (FileName));
    if (!CheckMapLoaded (map))
    {
        cerr << "Error : Map not loaded correctly" << endl;
        return;
    }
    GameObjects obj (ParseMap(map));
    int gamemode (GetGamemode(obj));
    if (gamemode == KGMNone)
    {
        cerr << "Error : Gamemode could not be determined" << endl;
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
	#ifdef KB_ARROWS
	cout << "P1: tab; P2: backspace; Menu: enter;\n";
	#endif
        ShowMatrix (map);
        read (STDIN_FILENO, &key, 1);
	#ifdef KB_ARROWS
	if (isGarbage(key)) {
	    key = 0;
	    continue;
	}
	key = arrowsToKey(key);
	#endif
        if (KMenu == key)
        {
            do
            {
                DispMenu ();
                read (STDIN_FILENO, &key, 1);
#ifdef KB_ARROWS
		if (isGarbage(key)) {
		    key = 0;
		    continue;
		}
		key = arrowsToKey(key);
#endif
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
            continue;
        }
        if (Action(map, obj, key))
        {
            solution.push_back (key);
            ++nbmoves;
        }
    }
    ClearScreen ();
    cout << "Victory ! You won in " << nbmoves << " moves !" << endl;
    cout  << "your solution is" << endl << solution << endl;

    getchar ();
} // Game

void DispMenu ()
{
    ClearScreen ();
    Color (KBold);
    cout << "--[MENU]--" << endl;
    Color (KReset);
    #ifdef KB_ARROWS
    cout << "^) Reset"   << endl
         << "<) Skip this map" << endl
         << "v) Exit" << endl;
    #else 
    cout << KKeyReset << ") Reset"   << endl
         << KSkip << ") Skip this map" << endl
         << KExit << ") Exit" << endl;
    #endif
}
