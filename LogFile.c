    	                                //Declaration of an array of unknown size containing the move
void WriteToLog(char move[]){}          //Write to log takes whatever is in 'move' array and Writes it to the LogFile
const char *ReturnCurrentMove();      //Returns a pointer to the current move. Might be applicable for GUI purposes, easy enough to implement.
const char *ReturnLastMove();        //Similar to ReturnCurrentMove, except returns the last move. 
void DeleteMove()                   //Should delete the indicated move. Useful for situations where we allow user to redo their move.
void CloseLog();                   //Closes the LogFile, should be called when the game is complete or someone has forfeitted.
