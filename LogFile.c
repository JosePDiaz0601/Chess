#include "LogFile.h"

//function to write to log. returns an integer for error purposes.
int WriteToLog(char MovePart1[2],char MovePart2[2],char MovePiece[2]){
char *filename = "LogFile.log";

 /*This portion opens the file corresponding to pointer 'filename'*/
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("File 'LogFile.log' could not be opened. %s", filename);
        return 0;
	}
	fprintf(fp,"%s",MovePart1);  /*we might have to change fp to filename, not sure yet*/
	fprintf(fp,"%s",MovePart2);
	fprintf(fp,"%s",MovePiece);

   fclose(filename);

}
 char *ReturnCurrentMove(void){


 }
const char *ReturnLastMove(void){


}
void DeleteMove(void){


}
void CloseLog(void){


}