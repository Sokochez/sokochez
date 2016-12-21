#include <game.h>

using namespace std;

void Game (const string & FileName)
{
    CMatrix map (LoadMap(FileName));
    if (!CheckMapLoaded(map))
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

    ClearScreen();
    char key;
    unsigned nbmoves (0);
    cout << "Loaded map " << FileName << endl;

    WriteRules(gamemode);
    cout << "Press a key to begin" << endl;
    getchar();

    while (!CheckWin(obj, gamemode))
    {
        ClearScreen();
        ShowMatrix(map);
        cin >> key;
        Action(map, obj, key);
        ++nbmoves;
    }
    ClearScreen();
    cout << "Victory ! You won in "<< nbmoves << " moves !" << endl;
    getchar();
    getchar();
} // Game
