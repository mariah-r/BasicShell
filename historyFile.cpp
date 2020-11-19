//******************************************************************************************************************************************
//
// Mariah Roberts
// Operating Systems (COSC 3346)
// Professor: Dr. Kar
// Project #1: New Island Shell - Writing Your Own Shell
// Purpose: To implement TheHistoryQueue class for the history command in the island shell.
//
// References: https://www.geeksforgeeks.org/making-linux-shell-c/, Project1 Hints (on Blackboard), Project 1 instructions (guish.l and guish.cpp files for initial code),
//			   https://www.geeksforgeeks.org/basic-shell-commands-in-linux/, C++ book
// 
//******************************************************************************************************************************************
#include <string>  //Delcaration
using namespace std;

class TheHistoryQueue
{
	private:
		int QUEUE_SIZE;				//The Size of the QUEUEARRAY [].
		string **QUEUEARRAY;		//The string pointer for the QUEUEARRAY.
	public:
	//***********************************************************************************************************
	// The TheHistoryQueue function takes the queueSize variable and stores it in the QUEUEARRAY for its class.
	//***********************************************************************************************************
		TheHistoryQueue(int queueSize)
		{
			QUEUE_SIZE = queueSize;
			QUEUEARRAY = new string*[QUEUE_SIZE];
			for(int i = 0; i < QUEUE_SIZE; i++)
			{
				QUEUEARRAY[i] = new string[10];
				for(int j = 0; j < QUEUE_SIZE; j++)
				{
					QUEUEARRAY[i][j] = "";
				}
			}
		}
		//***********************************************************************************************************
	    // The TheHistoryQueue ()Deallocates the TheHistoryQueue array and deletes it. (Deconstructor)
	    //***********************************************************************************************************
		~TheHistoryQueue()
		{
			delete[] QUEUEARRAY;
		}
		//***********************************************************************************************************
	    // The addQueue () function takes the QUEUEARRAY's input and size and implements it for the r n command 
	    //***********************************************************************************************************
		void addQueue(string input[], int inputSize)
		{
			
		if(input[0][0] == 'r')
			return;
		if(inputSize > 10)
		{
			inputSize = 10;
		}
			for(int i = 0; i < 10; i++)
			{
			QUEUEARRAY[QUEUE_SIZE-1][i] = "";
			}
			for(int i = QUEUE_SIZE-1; i > 0; i--)
			{
				for(int j = 0; j < 10; j++)
				{
					QUEUEARRAY[i][j] = QUEUEARRAY[i-1][j];
				}
				
			}
			for(int i = 0; i < inputSize; i++)
				{
					QUEUEARRAY[0][i] = input[i];
				}
			for(int i = inputSize; i < 10; i++)
			{
				QUEUEARRAY[0][i] = "";
			}
		}
		//**********************************************************************************************************************************************
	    // The getFromQueue function gets the commands that were entered in the shell and checks to make sure the number of commands was not exceeded
	    //**********************************************************************************************************************************************
		string getFromQueue(int index_val)
		{
			string temp = "";
			if(index_val >= 0 && index_val < QUEUE_SIZE)
			{
				for(int i = 0; i < 9; i++)
				{
					temp += QUEUEARRAY[index_val][i] + " ";
				}
				temp += QUEUEARRAY[index_val][9];
				return temp;
			}
			else
				return "Out Of Bounds";
		}
		
		//***********************************************************************************************************
	    // The getWordFromQueue function gets the word command that was ented in the shell
	    //***********************************************************************************************************
		string getWordFromQueue(int index_val, int word)
		{
			//string temp = "";
			if(index_val >= 0 && index_val < QUEUE_SIZE)
			{
				if(word >= 0 && word < 10)
				{
					return QUEUEARRAY[index_val][word];
				}
			}
			else
				return "Out Of Bounds";
		}
		//***********************************************************************************************************
	    // The getCommandLength returns the length of the command and checks to make sure it is less than 10
	    //***********************************************************************************************************
		int getCommandLength(int index_val)
		{
			if(index_val > 9)
			{
				index_val = 9;
			}
			if(index_val < 0)
			{
				index_val = 0;
			}
			for(int i = 0; i < 10; i++)
			{
				if(QUEUEARRAY[index_val][i] == "")
				{
					return i;
				}
			}
		}
		
};