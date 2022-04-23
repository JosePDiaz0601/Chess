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
int WriteToLog(int movenumber,char MovePart1[],char MovePart2[],char MovePiece[]){
char *filename = "LogFile.log";

 /*This portion opens the file corresponding to pointer 'filename'*/
    FILE *fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("File 'LogFile.log' could not be opened. %s", filename);
        return 0;
	}
	fprintf(fp,"%d. ,%s,%s,%s\n",movenumber,MovePart1,MovePart2,MovePiece); 


   fclose(fp);

}



void DeleteMove(void){
FILE *pointer1, *pointer2;


}

void ConvertToPDF(void){
   int hello;

/*Before calling WriteToLog, we need to remove the current LogFile. 'remove("LogFile.txt")'
void WriteToLog(int movenumber,char MOVE1[],char MOVE2[],char MOVEP[]) {
char *filename = "LogFile.txt";

 This portion opens the file corresponding to pointer 'filename'

    FILE *fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("File 'LogFile.txt' could not be opened. %s", filename);

	}

	fprintf(fp,"%d. ,%s,%s,%s\n",movenumber,MOVE1,MOVE2,MOVEP); 


   fclose(fp);

}*/