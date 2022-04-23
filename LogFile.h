#ifndef LOGFILEHEADER
#define LOGFILEHEADER

#include <stdio.h>


int WriteToLog(int movenumber,char MovePart1[],char MovePart2[],char MovePiece[]);          //Write to log takes whatever is in 'move' array and Writes it to the LogFile

void DeleteMove(void);                   //Should delete the indicated move. Useful for situations where we allow user to redo their move.

void ConvertToPDF(void);

#endif
