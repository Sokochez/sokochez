#include <iostream>
#include <string>
#include <vector>
#include <game.h>
#include "input.h"
#include "editor.h"

using namespace std;

int main (int argc, char *argv[])
{
    set_input_mode ();
    if ((argc < 2) || (("-e" == (string) argv[1]) && (argc < 3)))
    {
        cout << "Argument(s) missing : At least one map file name required" << endl;
        return 0;
    }
    if ("-e" == (string) argv[1])
    {
        cout << "EDITOR !" << endl;
        for (int i (2); i < argc; ++i)
        {
            cout << i << endl;
            Editor (argv[i]);
        }
    }
    else
    {
        for (int i (1); i < argc; ++i)
        {
            Game (argv[i]);
        }
    }
    return 0;
}
