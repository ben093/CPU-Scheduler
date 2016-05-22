/*=============================================================
	COURSE:	CSC460, assignment6
	PROGRAMMERS: 	Ben (bb), Anthony (av)
	MODIFIED BY: Ben, Anthony 
	LAST MODIFIED DATE:	4/28/2016
	DESCRIPTION:	This program will simulate a CPU scheduler.
	NOTE: 50% Ben Borgstede - Steps
		  50% Anthony Van - Steps
	FILES:	makefile, scheduler.cpp
	IDE/COMPILER/INTERPRETER:	GNU g++
	INSTRUCTION FOR COMPILATION AND EXECUTION:
	1. make	to COMPILE
	2. type:	./scheduler [numberOfProcesses] to EXECUTE
=============================================================*/

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <process.h>

#define READ 0
#define WRITE 1

using namespace std;

int childPipe[2];

void writePipe(Process proc)
{
    int len = write(childPipe[WRITE], &proc, sizeof(proc));
    if(len != sizeof(proc))
	{
        cout << "Error in writing to the pipe." << endl;
        exit(0);
    }
}

Process readPipe()
{
    Process proc;
    int len = read(childPipe[READ], &proc, sizeof(proc));
    if(len != sizeof(proc))
	{
        cout << "Error reading from pipe." << endl;
        exit(0);
    }
    return proc;
}

int main(int argc, char* argv[])
{
	int n;
	
	// check for valid arguments
	if (argc != 2) 
	{
		cout << "Incorrect number of arguments" << endl;
		cout << "Correct Usage: ./scheduler [number of processes]" << endl;
		return 0;
	}
	
	char* end;
    double val = strtod(argv[1], &end);
    if (end[0])
    { // end[0] is the first non-numeric argument.
      cout << "Error: Invalid input. The input argument must be numeric." << endl;
      return 0;
    }
    else
    {
		// Convert argument to integer.
		n = atoi(argv[1]);
		
		// make sure n is positive
		if (n < 0) 
		{
			cout << "The number must be positive" << endl;
			return 0;
		}
	}
	
	
	
}