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
int movecounter;
int WriteToLog(char MovePart1[2],char MovePart2[2],char MovePiece[2]){
char *filename = "LogFile.log";

 /*This portion opens the file corresponding to pointer 'filename'*/
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("File 'LogFile.log' could not be opened. %s", filename);
        return 0;
	}
	fprintf(fp,"%d,%s,%s,%s\n",movecounter,MovePart1,MovePart2,MovePiece);  /*we might have to change fp to filename, not sure yet*/


   fclose(fp);

}



void DeleteMove(void){
FILE *pointer1, *pointer2;


}

void ConvertToPDF(void){
   int hello;
