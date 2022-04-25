/*********************************************************************/
/* Chess Assignment, for EECS 22L, Spring 22                         */
/*                                                                   */
/* Initial author: Jose Diaz                                         */
/*                                                                   */
/* Logfile.c  notation file reader and writer for UNOPTIMIZED CHESS  */
/*                                                                   */
/*********************************************************************/
#include "LogFile.h"
#include "chess.h"
char justMovedPieceColor = 'h';
char justMovedPieceType = 'h';


//function to write to log. returns an integer for error purposes.
int WriteToLog(char MovePart1[],char MovePart2[],char justMovedPieceColor, char justMovedPieceType){

char colorAndType[2];
char *filename = "LogFile.log";


colorAndType[0] = justMovedPieceColor;
colorAndType[1] = justMovedPieceType;

 /*This portion opens the file corresponding to pointer 'filename'*/
    FILE *fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("File 'LogFile.log' could not be opened. %s", filename);
        return 0;
	}
   
   MOVENUMBER = MOVENUMBER + MOVEUPDATER;

   if (MOVEUPDATER == 1)
   MOVEUPDATER == 0;
   if (MOVEUPDATER == 0)
   MOVEUPDATER == 1; 

	fprintf(fp,"%d. ,%s,%s,%s\n", MOVENUMBER,MovePart1,MovePart2,colorAndType); 

/** WARNING. DO NOT DELETE THIS COMMENT. Use variables
 * justMovedPieceColor	and
 * justMovedPieceType
 * to print the piece type of the piece that has just been moved.
 * These are global variables from chess.h that are updated on the
 * front end everytime the human user or computer makes a move.
 */

   fclose(fp);

}



void DeleteMove(void){
FILE *pointer1, *pointer2;


}

void ConvertToPDF(void){
   int CONVERT;

   CONVERT = rename("LogFile.log", "LogFile.pdf");
                                                   }

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
