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
    ShowMatrix(map);
    CPosition P1 (FindPlayer(map,KTokenPlayer1));
    CPosition P2 (FindPlayer(map, KTokenPlayer2));
    char key;
    while (!CheckWin(P1, P2))
    {
        ClearScreen();
        ShowMatrix(map);
        cin >> key;
        Action(map, key, P1, P2);
    }
}
