#ifndef LOGFILEHEADER
#define LOGFILEHEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MOVENUMBER;
int MOVEUPDATER; 

int WriteToLog(char MovePart1[],char MovePart2[]);          //Write to log takes whatever is in 'move' array and Writes it to the LogFile

                 //Should delete the indicated move. Useful for situations where we allow user to redo their move.

#endif
