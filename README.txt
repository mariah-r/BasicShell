Note about Project 1:
	*The project was coded in C++. It's been a while since I coded using C++.
	*References used: https://www.geeksforgeeks.org/making-linux-shell-c/, Project1 Hints (on Blackboard), Project 1 instructions (guish.l and guish.cpp files for initial code),
		   https://www.geeksforgeeks.org/basic-shell-commands-in-linux/, C++ book
Files and How to Compile Project in PUTTY
	*These files were compiled in PUTTY (used at the school) and were also debugged
	*To compile:
		1. Type make
		2. Type ./mroberts4_proj1

	*guish2.cpp:
		*The file that contains the main function
		*The do while loop reads, executes, and compares each command throughout the program.
		*The use of class objects (TheHistoryQueue class AKA the History class) is used to store the history of the commands that were executed in the shell.	
		*The use of tokens, parent and child functions, arrays, and pointers were used throughout the program.
		*The temporary arrays and variables store the built in commands' values.
	*historyFile.cpp:
		*TheHistoryQueue is the class that is used to keep track of the most and least recent commands in the shell.
		*It includes a constructor asnd destructior. 
		*The getFromQueue(int index_val) gets the commands that were entered in the shell and checks to make sure the number of commands werenot exceeded.
		*the getCommandLength (int index_val) checks to make sure that the number of commands is less than 10.
	*guish.l
		*The initial code that was provided for the project.
	
	*guish.cpp
		*The initial code that was provided for the project for getting tokens and implementing the parent and child processes.
		*Uses te gettoks function to store the tokens (input frim the user)
	
	*makefile
		*the makefile was provided for us, but I made an alteration so the history class can be implemented in the shell to make it easier.
Modifications:
	* I added the guish2.cpp file so the main function and tokens functions can be seperated. Mainly to keep it more organized.
	* I added the historyFile.cpp file to store the History class and so it can be implemented in the shell and hold the commands the user types. 
	* In the guish2.cpp file, I added a help function to print out what the built-in commands are so the user can refer to them if they forget.