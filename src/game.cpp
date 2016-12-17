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
    CPosition P1 (FindPlayer(map,KTokenPlayer1));
    CPosition P2 (FindPlayer(map, KTokenPlayer2));
    cout << P1.first << " " << P1.second << endl;
    cout << P2.first << " " << P2.second << endl;

}
