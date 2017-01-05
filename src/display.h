#ifndef DISPLAY_H
#define DISPLAY_H

#include <map.h>

using namespace std;

const string KReset   ("0");
const string KNoir    ("30");
const string KRouge   ("31");
const string KVert    ("32");
const string KJaune   ("33");
const string KBleu    ("34");
const string KMagenta ("35");
const string KCyan    ("36");
const string KUnderLine ("4");
const string KBold  ("1");


const string KColWall (KReset);
const string KColP1 (KRouge);
const string KColP2 (KBleu);
const string KColBlock (KJaune);
const string KColEmpty (KReset);
const string KColObj (KVert);
const string KColPos (KMagenta);
/**
 * @brief Clears the screen
 */

void ClearScreen ();

/**
 * @brief Changes the color of the screen
 * @param coul The color to set
 */

void Color (const string & Col);

/**
 * @brief Displays the matrix
 * @param Mat The matrix to display
 */

void ShowMatrix (const CMatrix & Mat);

#endif // DISPLAY_H
