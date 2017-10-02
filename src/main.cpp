/**
 * \file main.cpp
 * \authors Baptiste Pouget, Dorian Tachet
 * \brief Beginning of the project titled "Sokochez"
 *        A Sokoban multiplayer clone
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "game.h"
#include "input.h"
#include "editor.h"

using namespace std;

int main (int argc, char *argv[])
{
    vector <int> flagsPos;
    bool editor = false;
    bool help = false;
    set_input_mode ();

    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
            flagsPos.push_back(i);
        if ((string) argv[i] == "-e")
            editor = true;
        if ((string) argv[i] == "-h")
            help = true;
    }

    if (help)
    {
        cout << "Sokochez Help" << endl
             << "Usage : [flags] level[s]" << endl
             << "-e : editor mode " << endl
             << "-h : print help " << endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
        if (find(flagsPos.begin(), flagsPos.end(), i) != flagsPos.end())
            continue;
        if (editor)
            Editor(argv[i]);
        else 
            Game(argv[i]);
    }

    cout << "No more levels." << endl;
    return 0;
}
