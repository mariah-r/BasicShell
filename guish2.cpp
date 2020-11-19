//******************************************************************************************************************************************
//
// Mariah Roberts
// Operating Systems (COSC 3346)
// Professor: Dr. Kar
// Project #1: New Island Shell - Writing Your Own Shell
// Purpose: To learn how linux commands work in the shell along with implementing pointers, tokens, and parent and child variables.
//
// References: https://www.geeksforgeeks.org/making-linux-shell-c/, Project1 Hints (on Blackboard), Project 1 instructions (guish.l and guish.cpp files for initial code),
//			   https://www.geeksforgeeks.org/basic-shell-commands-in-linux/ , C++ Book
// 
//******************************************************************************************************************************************


//*********************************************************
//
// Includes and Defines for the Island Shell
//
//*********************************************************

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include "historyFile.cpp"

  
using namespace std;

//********************************************************
//
// The Declarations
//
//********************************************************

using namespace std; 
extern "C"
{
	extern char **gettoks();
}


//*********************************************************
//
// Main Function
//
//*********************************************************
int main( int argc, char *argv[] )
{
  // local variables that are used throughout the program.
  int ii;
  
  //Pointer for the tokens.
  char **toks;	
  
  //The return value declaration.
  int retval;
  
  //TheHistoryQueue class that stores the command's history.
  TheHistoryQueue myQueue(10);		

  //The parent id variable to be used throughout the program's runtime
  pid_t pid;
  int status;
  
  //Folder character array.
  char folder[90];
  
  //The return value for the program
  retval = 0;
  
  //This iterator is used for toks into the history commands. It resets to 0 after each loop iteration
  int a = 0;
  
  //Tracks the number of commands that are beign executed.
  int b = 0;
  
  //This char* array has an array size of 11. This array is utilized in the r n command to pass the arguments in the program.  There are 11 elements so that there is a spot for the NULL element.
  char ** repeat = new char*[11];
  
  //Temporary string[] for storing the cstring elements in the history class.
  string strtemps[10];
  
  //temporary integer to store the values of the functions used throughout the program.
  int valuetemps;
  
  //Stores the command's length.
  int command_length;
  
  
  //Temporary array characters that store the built in commands in the program.
  char** tempchars = new char*[6]; 
  tempchars[0] = new char[100];
  strcpy(tempchars[0], "ls");
  tempchars[1] = new char[100];
  strcpy(tempchars[1], "-l");
  tempchars[2] = new char[100];
  strcpy(tempchars[2], "mroberts4_proj1");
  tempchars[3] = new char[100];
  strcpy(tempchars[3], "help");
  tempchars[4] = new char[100];
  strcpy(tempchars[4], "cat");
  tempchars[5] = new char[100];
  tempchars[5] = NULL;
  
  //The Greeting for the Shell that lists the built in commands and their descriptions.
  cout << "***************************************************************************************************" <<endl;
  cout<<"(OωO) Welcome to the Island Shell (OωO) " <<"\nUse at your own risk!\n" << endl;
  cout << "***************************************************************************************************" <<endl;
  cout<<"Built in commands for the shell are: " <<endl;
  cout << "help" <<endl;
  cout << "hist: "<< "displays a history of commands from the most to least recently executed commands." <<endl;
  cout << "r n : " << "repeats the nth command after the hist command is executed." <<endl;
  cout << "exit:" << " exits the shell\n";
  cout << "cat : " << "prints out the contents of what the file says. Just type cat and the name of your file with it's extention. Reccomended after using the ls command :D" <<endl;

 
 //Program Loop that gets the tokens and calls the function.
  do{
	// shows the shell prompt
	printf("%s", "guish $");
	printf("%i", b++);
	printf("%s", ": ");

    //Calls the gettoks() function to get the tokens for the commands in the shell.
	toks = gettoks();
	
	
	//Ignores the empty lines if there are no tokens to be stored.
	if(toks[0] == NULL)
	{
		continue;
	}
	
	//Program commands for the built-in commands in the Island shell.
	//outputs name of the program then runs "ls -l mroberts4_proj1 and shows the names of the files and types of action each file does and is stored in that folder."
	//This if statement checks if the string that was entered was for the folder with the ls -l command.
	if(strcmp(toks[0], "mroberts4_proj1") == 0)
	{
		cout << "Project1: ls -l\n";
		
		
		pid = fork();
		if(pid == 0)     // In child process 
		{
			//Checks the /bin file for the project folder.
			strcpy(folder,"/bin/");
			strcat(folder,tempchars[0]);
		
			cout << "executing " << folder << "\n";
			//cout << toks;
			execv(folder, tempchars);
			cout << "no command: " << '\"' << tempchars << '\"' << " found\n";  //Prints out if there was no command executed.
			exit(1);
		}
		else            // In parent process
		{
			wait(&status);
		}
		continue;
	}
	
//loads the command into the history queue to be sorted to the most recent commands.
	a = 0;
	if(strcmp(toks[0], "r") != 0) 
	{
		//while toks[a] has something other than null, load toks into strtemps[a] array.
		do
		{
		strtemps[a] = toks[a];
		}while(toks[++a] != NULL && a < 10);
		//passes the strtemps array and the number of tokens to myQueue object for the history class.
		myQueue.addQueue(strtemps, a);
	}
	
//exit command exits the shell. If the token compares and matches the exit string, the program will exit the shell
	if(strcmp(toks[0], "exit") == 0)
	{
		cout << " Program exited with return value: " << retval << "\n";
	    cout<<"Thank you for using the Island Shell! Come Again! :D"<< endl; 
		return retval;
	}
	
//history command to compare if th ecommand was the history command and displays the commands that were entered into the shell.
	if(strcmp(toks[0], "hist") == 0)
	{
		cout << "executing internal command \"history\"" << "\n";
		cout << "Command History: \n";
		for(int i = 0; i < 10; i++)
		{
			cout << "	command #" << i+1 << "	: " << myQueue.getFromQueue(i) << "\n";
		}
		continue;
	}
	//This command displays the help portion to remind the user of the built in commands for the shell.
	if(strcmp(toks[0], "help") ==0)
	{
		 cout<<"Built in commands for the shell are: " <<endl;
         cout << "help" <<endl;
         cout << "\nhistory: "<< "displays a history of commands from the most recent to least recently used." <<endl;
         cout << "r n : " << "repeats the nth command in history" <<endl;
         cout << "exit:" << " exits the shell\n";
         cout << "cat : " << "prints out the contents of what the file says. Just type cat and the name of your file with it's extention. Reccomended after using the ls command :D" <<endl;
		 continue;

	}

	//"r n" command which stores the most to least recent command that was executed.
	if(strcmp(toks[0], "r") == 0)
	{
		//allocates inside the repeat[i] array.
		for(int i = 0; i < 11; i++)
		{
			repeat[i] = new char[100];
		}
		
		//repeat the most recent if there are not any tokens.
		if(toks[1] == NULL)
		{
			//This used to be needed before i transfers over to the for loop.
			strcpy(repeat[0], myQueue.getWordFromQueue(0,0).c_str());
		
			//Load each token from the myQueue object with index i
			for(int i = 0; i < myQueue.getCommandLength(0); i++)
			{
				strcpy(repeat[i], myQueue.getWordFromQueue(0,i).c_str());
			}
			//Last element is NULL in the array.
			repeat[myQueue.getCommandLength(0)] = NULL;
		}
	
		//else repeats the command to the most recent command in the history.
		else
		{
			//the "n" part of "r n"
			valuetemps = atoi(toks[1]);
			valuetemps -= 1;
			//prevents segmentation faults by counting the character tokens in the valuetemps variable.
			if(valuetemps < 0)
			{
				valuetemps = 0;
			}
			else if(valuetemps >= 10)
			{
				valuetemps = 10;
			}
			
			//num of tokens at the valuetemps index.
			command_length = myQueue.getCommandLength(valuetemps);
			cout << "commandHistoryLength: " << command_length << "\n";
			
			//if no command at index of itemp, continue
			if(myQueue.getCommandLength(valuetemps) == 0)
			{
				
				continue;
			}
			
	
			for(int i = 0; i < myQueue.getCommandLength(valuetemps); i++)
			{
				strcpy(repeat[i], myQueue.getWordFromQueue(valuetemps,i).c_str());
			}
			repeat[command_length] = NULL;
			
		}
		
		//copy of the segment that is added to the queue.
		a = 0;
		if(strcmp(repeat[0], "r") != 0)
		{
			do
			{
				strtemps[a] = repeat[a];
				
			}while(repeat[++a] != NULL && a < 10);
		myQueue.addQueue(strtemps, a);
		}
		
       //copy of the history segment that prints out the history's  output.
		if(repeat[0] != NULL)
		{
			if(strcmp(repeat[0], "hist") == 0)
			{
				cout << "executing internal command \"history\"" << "\n";
				cout << "Command History: \n";
				for(int i = 0; i < 10; i++)
				{
					cout << "	command #" << i+1 << "	: " << myQueue.getFromQueue(i) << "\n";  //The function call for the TheHistoryQueue class.
				}
				continue;
			}
		//copy of the command that prints out that the folder directory is being executed.
		pid = fork();
		if(pid == 0)     // In child process 
		{
			strcpy(folder,"/bin/");
			strcat(folder,repeat[0]);
		
			cout << "executing " << folder << "\n";
			cout << toks;
			execv(folder, repeat);
			cout << "no command: " << '\"' << repeat[0] << '\"' << " found\n";
			exit(1);
		}
        else            // In parent process
		{
			//deallocates the repeat array.
			for(int i = 0; i < 10; i++)
			{
				delete[] repeat[i];
			}
			wait(&status);
		}
		
		
	 }

		continue;
	}
		
   //all other shell commands are implemented here.
  if(toks[0] != NULL)
  {

     pid = fork();
     if(pid == 0)     // In child process 
     {
	
        strcpy(folder,"/bin/");
        strcat(folder,toks[0]);
		
		cout << "executing " << folder << "\n";
		
        execv(folder, toks);
		cout << "no command: " << '\"' << toks[0] << '\"' << " found\n";
		exit(1);
      }
      else            // In parent process
      {
        wait(&status);
     }
  }
  
 
   }while(1);
    return (retval );
}




  
  



