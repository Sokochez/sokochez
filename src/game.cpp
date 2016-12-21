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
    char key;
    unsigned nbmoves (0);
    ClearScreen();
    cout << "Loaded map " << FileName << endl
         << "Win by joining the other player" << endl
         << "Press a key to begin" << endl;
    getchar();

    while (!CheckWin(obj[KTokenPlayer1], obj[KTokenPlayer2]))
    {
        ClearScreen();
        ShowMatrix(map);
        cin >> key;
        Action(map, key, obj[KTokenPlayer1], obj[KTokenPlayer2]);
        ++nbmoves;
    }
    ClearScreen();
    cout << "Victory ! You won in "<< nbmoves << " moves !" << endl;
    getchar();
    getchar();
} // Game
