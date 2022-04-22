/*********************************************************************/
/* Chess Assignment, for EECS 22L, Spring 22                     */
/*                                                                   */
/* Initial author: Jose Diaz                                       */
/*                                                                   */
/* Logfile.c  notation file reader and writer for UNOPTIMIZED CHESS  */
/*                                                                   */
/*********************************************************************/
#include "LogFile.h"

//function to write to log. returns an integer for error purposes.
int WriteToLog(char MovePart1[2],char MovePart2[2],char MovePiece[2]){
char *filename = "LogFile.log";
FILE *fp;

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



void DeleteMove(void){
FILE *pointer1, *pointer2;


}

void ConvertToPDF(void){
   int hello;
