#ifndef LOGFILEHEADER
#define LOGFILEHEADER

#include <stdio.h>


int WriteToLog(char MovePart1[2],char MovePart2[2],char MovePiece[2]);          //Write to log takes whatever is in 'move' array and Writes it to the LogFile

void DeleteMove(void);                   //Should delete the indicated move. Useful for situations where we allow user to redo their move.

void ConvertToPDF(void);

#endif
