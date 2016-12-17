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
}


CPosition FindPlayer (const CMatrix & Map, const char & Token)
{
    CPosition pos;
    for (unsigned i (0); i < Map.size(); ++i)
    {
        for (unsigned j (0); j < Map[0].size(); ++j)
        {
            if (Map[i][j] == Token)
            {
                pos.first = j;
                pos.second = i;
                return pos;
            }
        }
    }
    pos.first = Map[0].size();
    pos.second = Map.size();
    return pos;
}

bool CheckMapLoaded (const CMatrix & Map)
{
    return (Map.size() > 0);
}

bool IsMapValid (const CMatrix & Map)
{
    CPosition P1 (FindPlayer(Map, KTokenPlayer1));
    CPosition P2 (FindPlayer(Map, KTokenPlayer2));
    return ((P1.first < Map[0].size())
            && (P1.second < Map.size())
            && (P2.first < Map[0].size())
            && (P2.second < Map.size())
                );
}