#ifndef EDITOR_H
#define EDITOR_H
#include <map.h>
#include <cctype>

using namespace std;
const char KEditorUp = 'z';
const char KEditorDown = 's';
const char KEditorLeft = 'q';
const char KEditorRight = 'd';
const char KValid= '4';


const char KTokenEditor('X');
const char KEditEmptyToken('1');
const char KEditWallToken('2');
const char KEditBlockToken('3');
const char KEditPLayersToken('4');
const char KEditSpecialBlocks('5');
const char KEditSpecialLocations('6');




/**
 * @brief Editor Lauch the editor mod
 * @param FileName The name of the input file
 */
void Editor (const string & FileName);
#endif // EDITOR_H
