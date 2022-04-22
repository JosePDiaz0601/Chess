/*********************************************************************/
/* Chess Assignment, for EECS 22L, Spring 22                     */
/*                                                                   */
/* Initial author: Jose Diaz                                       */
/*                                                                   */
/* Logfile.c  notation file reader and writer for UNOPTIMIZED CHESS  */
/*                                                                   */
/*********************************************************************/
#include "LogFile.h"
#include <stdlib.h>


//function to write to log. returns an integer for error purposes.
int WriteToLog(char MovePart1[2],char MovePart2[2],char MovePiece[2]){
char *filename = "LogFile.log";

 /*This portion opens the file corresponding to pointer 'filename'*/
    FILE *fp;
    fp = fopen("/users/ugrad/akatare/testSubmission/SourceCodePackage/bin/LogFile.log", "w");
    if (fp == NULL)
    {
        printf("File 'LogFile.log' could not be opened. %s", filename);
        return -1;
	}
	fprintf(fp,"%s",MovePart1);  /*we might have to change fp to filename, not sure yet*/
	fprintf(fp,"%s",MovePart2);
	fprintf(fp,"%s",MovePiece);

   fclose(fp);
   return 0;

}
const char *ReturnCurrentMove(void){
	 return NULL; //change this later

 }
const char *ReturnLastMove(void){

	return NULL; //change this later
}
void DeleteMove(void){


}
void CloseLog(void){


}
