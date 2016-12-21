#include <gameplay.h>

using namespace std;


bool Move (CMatrix & Mat, CPosition & Pos, const int & DistX, const int & DistY)
{
    if (    (-DistY > int (Pos.second))
            ||(-DistX > int (Pos.first))
            ||(DistY + Pos.second >= Mat.size())
            ||(DistX + Pos.first >= Mat[Pos.second].size())
            ||(Mat[Pos.second + DistY][Pos.first + DistX] == KTokenWall))
    {
        return false;
    }

    char Token (Mat[Pos.second][Pos.first]);
    CPosition NewPos (Pos.first + DistX, Pos.second + DistY);

    if ((Mat[NewPos.second][NewPos.first] == KTokenEmpty)
        || (IsPlayer(Mat, Pos) && IsPlayer(Mat, NewPos)))
    {
        Mat[NewPos.second][NewPos.first] = Token;
        Mat[Pos.second][Pos.first] = KTokenEmpty;
        Pos = NewPos;
        return true;
    }
    /* If there is a block
     * if block moves
     * move player
     */
    if (    IsPlayer(Mat, Pos)
            && (Mat[NewPos.second][NewPos.first] == KTokenBlock))
    {
        if (Move (Mat, NewPos, DistX, DistY))
        {
            return Move (Mat, Pos, DistX, DistY);
        }
    }
    return false;
} //Move


void Action (CMatrix & Mat, const char & Key, CPosition & Player1, CPosition & Player2)
{
    switch (Key) {
    case KP1MoveUp:
        Move (Mat, Player1, 0, -1);
        break;
    case KP1MoveDown:
        Move (Mat, Player1, 0, 1);
        break;
    case KP1MoveLeft:
        Move (Mat, Player1, -1, 0);
        break;
    case KP1MoveRight:
        Move (Mat, Player1, 1, 0);
        break;
    case KP2MoveUp:
        Move (Mat, Player2, 0, -1);
        break;
    case KP2MoveDown:
        Move (Mat, Player2, 0, 1);
        break;
    case KP2MoveLeft:
        Move (Mat, Player2, -1, 0);
        break;
    case KP2MoveRight:
        Move (Mat, Player2, 1, 0);
        break;
    default:
        cout << "Invalid key" << endl;
        break;
    }
} // Action

bool IsPlayer (const CMatrix & Mat, const CPosition & Pos)
{
    return ((Mat[Pos.second][Pos.first] == KTokenPlayer1)
            || (Mat[Pos.second][Pos.first] == KTokenPlayer2));
} // IsPlayer

bool CheckWin (const CPosition & Pos1, const CPosition & Pos2)
{
    return (Pos1 == Pos2);
} // CheckWin

int GetGamemode (const GameObjects & Objects)
{
    int GM (KGMNone);
    if (    ObjectExists(Objects, KTokenPlayer1)
            && ObjectExists(Objects, KTokenPlayer2))
    {
        GM = KGMPlayersMeet;
    }
    return GM;
} // GetGamemode

bool ObjectExists (const GameObjects & Objects, const char & Key)
{
    return !(Objects.find(Key) == Objects.end());
}
