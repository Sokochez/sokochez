#include <display.h>

using namespace std;

void ClearScreen ()
{
    cout << "\033[H\033[2J";
} // ClearScreen

void Color (const string & Col)
{
    cout << "\033[" << Col <<"m";
} // Color

void ShowMatrix (const CMatrix & Mat)
{
    for (unsigned i (0); i < Mat.size(); ++i)
    {
        for (unsigned j (0); j < Mat[i].size(); ++j)
        {
            if (    (0 == j) || (Mat[i][j] != Mat[i][j-1]))
                switch (Mat[i][j])
                {
                case KTokenEmpty :
                    Color (KColEmpty);
                    break;
                case KTokenPlayer1 :
                    Color (KColP1);
                    break;
                case KTokenPlayer2 :
                    Color (KColP2);
                    break;
                case KTokenWall :
                    Color (KColWall);
                    break;
                }
            if (IsBlockObjChar(Mat[i][j]))
                Color (KColObj);
            cout << Mat[i][j];
        }
        cout << endl;
    }
    Color(KReset);
} // ShowMatrix
