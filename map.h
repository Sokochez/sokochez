#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

typedef string CVLine; /// type defining a line
typedef vector <string> CMatrix; /// type defining a matrix
typedef pair <unsigned, unsigned> CPosition; /// type defining a position
const char KTokenPlayer1 = '1';
const char KTokenPlayer2 = '2';

CMatrix LoadMap (const string & FileName);
CPosition FindPlayer (const CMatrix & Map, const char & Token);

#endif // MAP_H
