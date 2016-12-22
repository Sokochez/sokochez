#include <map.h>

using namespace std;


CMatrix LoadMap (const string & FileName)
{
    CVLine line;
    CMatrix map;
    ifstream file (FileName);
    if (file.is_open())
    {
        for (;getline(file,line);)
        {
            map.push_back(line);
        }
    }
    return map;
} // LoadMap

GameObjects ParseMap (const CMatrix & Map)
{
    GameObjects Objects;
    for (unsigned i (0); i < Map.size(); ++i)
    {
        for (unsigned j (0); j < Map[i].size(); ++j)
        {
            if (    (Map[i][j] != KTokenWall)
                    && (Map[i][j] != KTokenEmpty)
                    && (Map[i][j] != KTokenBlock))
            {
                CPosition pos (j,i);
                Objects [Map[i][j]] = pos;
            }
        }
    }
    return Objects;
} // ParseMap

bool CheckMapLoaded (const CMatrix & Map)
{
    return (Map.size() > 0);
} // CheckMapLoaded

bool IsPlayer (const CMatrix & Mat, const CPosition & Pos)
{
    return ((Mat[Pos.second][Pos.first] == KTokenPlayer1)
            || (Mat[Pos.second][Pos.first] == KTokenPlayer2));
} // IsPlayer

bool IsSpecBlock (const char & Ch)
{
    return (((Ch <= KTokenBlockMax)
            && (Ch >= KTokenBlockMin))
            || (Ch == KTokenBlock));
}

bool IsSpecPos (const char & Ch)
{
    return (((Ch <= tolower(KTokenBlockMax))
            && (Ch >= tolower(KTokenBlockMin)))
            || (Ch == tolower(KTokenBlock)));
}
