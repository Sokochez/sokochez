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
        for (unsigned j (0); j < Map[0].size(); ++j)
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
