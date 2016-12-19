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
    if (!IsMapValid(map))
    {
        cout << "Error : Map not valid" << endl;
        return;
    }
    CPosition P1 (FindToken(map,KTokenPlayer1));
    CPosition P2 (FindToken(map, KTokenPlayer2));
    char key;
    unsigned nbmoves (0);
    ClearScreen();
    cout << "Loaded map " << FileName << endl
         << "Win by joining the other player" << endl
         << "Press a key to begin" << endl;
    getchar();

    while (!CheckWin(P1, P2))
    {
        ClearScreen();
        ShowMatrix(map);
        cin >> key;
        Action(map, key, P1, P2);
        ++nbmoves;
    }
    ClearScreen();
    cout << "Victory ! You won in "<< nbmoves << " moves !" << endl;
    getchar();
    getchar();
} // Game
