#include "gameplay.h"

using namespace std;


bool Move (CMatrix & Mat, GameObjects & Objects, CPosition & Pos, const int & DistX, const int & DistY)
{
    if (    (-DistY > (int) Pos.second)
            ||(-DistX > (int) Pos.first)
            ||(DistY + Pos.second >= Mat.size ())
            ||(DistX + Pos.first >= Mat[Pos.second].size ())
            ||(Mat[Pos.second + DistY][Pos.first + DistX] == KTokenWall))
    {
        return false;
    }

    char Token (Mat[Pos.second][Pos.first]);
    CPosition NewPos (Pos.first + DistX, Pos.second + DistY);

    if (Mat[NewPos.second][NewPos.first] == KTokenEmpty)
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
    if (    IsPlayer (Mat, Pos)
            && (Mat[NewPos.second][NewPos.first] == KTokenBlock))
    {
        if (Move (Mat, Objects, NewPos, DistX, DistY))
        {
            return Move (Mat, Objects, Pos, DistX, DistY);
        }
    }
    else if (IsPlayer (Mat, Pos)
             && (IsBlock (Mat[NewPos.second][NewPos.first])))
    {
        if (Move (Mat, Objects, Objects[Mat[NewPos.second][NewPos.first]], DistX, DistY))
        {
            return Move (Mat, Objects, Pos, DistX, DistY);
        }
    }
    return false;
} //Move


bool Action (CMatrix & Mat, GameObjects & Objects, const char & Key)
{
    switch (Key) {
    case KP1MoveUp:
        Move (Mat, Objects, Objects[KTokenPlayer1], 0, -1);
        break;
    case KP1MoveDown:
        Move (Mat, Objects,  Objects[KTokenPlayer1], 0, 1);
        break;
    case KP1MoveLeft:
        Move (Mat, Objects,  Objects[KTokenPlayer1], -1, 0);
        break;
    case KP1MoveRight:
        Move (Mat, Objects,  Objects[KTokenPlayer1], 1, 0);
        break;
    case KP2MoveUp:
        Move (Mat, Objects,  Objects[KTokenPlayer2], 0, -1);
        break;
    case KP2MoveDown:
        Move (Mat, Objects,  Objects[KTokenPlayer2], 0, 1);
        break;
    case KP2MoveLeft:
        Move (Mat, Objects,  Objects[KTokenPlayer2], -1, 0);
        break;
    case KP2MoveRight:
        Move (Mat, Objects,  Objects[KTokenPlayer2], 1, 0);
        break;
    default:
        return false;
    }
    return true;
} // Action

bool CheckWin (GameObjects & Objects, const int & GameMode)
{
    if (GameMode == KGMPlayersMeet)
    {
        return AreInContact(Objects[KTokenPlayer1],Objects[KTokenPlayer2]);
    }
    if (GameMode == KGMBlocksMeet)
    {
        return AreInContact(Objects[KTokenBlockMin], Objects[KTokenBlockMin+1]);
    }
    if (GameMode == KGMClear)
    {
        char i (KTokenBlockMin);
        while (ObjectExists (Objects, i) && ObjectExists (Objects, tolower(i)))
        {
            if (!AreInContact (Objects[i], Objects[tolower(i)]))
            {
                return false;
            }
            ++i;
        }
        return true;
    }
    return false;
} // CheckWin

int GetGamemode (const GameObjects & Objects)
{
    int GM (KGMNone);
    if (    ObjectExists (Objects, KTokenPlayer1)
            && ObjectExists (Objects, KTokenPlayer2))
    {
        GM = KGMPlayersMeet;

        if (ObjectExists (Objects, KTokenBlockMin)
                && (ObjectExists (Objects, KTokenBlockMin + 1)))
        {
            GM = KGMBlocksMeet;
        }
        if (ObjectExists (Objects, KTokenBlockMin)
                 && ObjectExists (Objects, tolower(KTokenBlockMin)))
        {
            GM = KGMClear;
        }
    }
    return GM;
} // GetGamemode

bool ObjectExists (const GameObjects & Objects, const char & Key)
{
    return !(Objects.find (Key) == Objects.end ());
} // ObjectExists

void WriteRules (const char & GameMode)
{
    cout << "Game mode: ";
    switch (GameMode)
    {
    case KGMPlayersMeet:
        cout << "Meet \nThe players must meet each other" << endl;
        break;
    case KGMBlocksMeet:
        cout << "Block Meet \nThe two special blocks must meet" << endl;
        break;
    case KGMClear:
        cout << "Clear \nPush the blocks at their respective position" << endl;
        break;
    }
} // WriteRules

bool AreInContact (const CPosition & Pos1, const CPosition & Pos2)
{
    return ((( (int) Pos1.second == (int) Pos2.second)
            && ((int) Pos1.first >= (int) Pos2.first - 1)
            && ((int) Pos1.first <= (int) Pos2.first + 1))
            ||(((int) Pos1.first == (int) Pos2.first)
            && ((int) Pos1.second >= (int) Pos2.second - 1)
            && ((int) Pos1.second <= (int) Pos2.second + 1)));

} // AreInContact

#ifdef KB_ARROWS
bool isGarbage(char key) {
    return (key == 27) || (key == 91);
}

char arrowsToKey(char key) {
    static char mode = M_P1;
    switch (key) {
    case KuseP1:
	mode = M_P1;
	break;
    case KuseP2:
	mode = M_P2;
	break;
    case KuseMenu:
	if (mode != M_MENU) {
	    mode = M_MENU;
	} else {
	    mode = M_P1;
	}
	return KMenu;
	break;
    case KarrowUp:
	if (mode == M_P1) return KP1MoveUp;
	if (mode == M_P2) return KP2MoveUp;
	if (mode == M_MENU) {
       	    mode = M_P1;
	    return KKeyReset;
	}
		    
	break;
    case KarrowDown:
	if (mode == M_P1) return KP1MoveDown;
	if (mode == M_P2) return KP2MoveDown;
	if (mode == M_MENU) {
	    return KExit;
	}
	break;
    case KarrowLeft:
	if (mode == M_P1) return KP1MoveLeft;
	if (mode == M_P2) return KP2MoveLeft;
	if (mode == M_MENU) {
	    mode = M_P1;
	    return KSkip;
	}
	break;
    case KarrowRight:
	return (mode == M_P1 ? KP1MoveRight :
		(mode == M_P2 ? KP2MoveRight : 0));
	break;
    }
    return 0;
}
#endif
