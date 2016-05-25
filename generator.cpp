#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 
#include <time.h> 
#include "process.h"
using namespace std; 

// This program will generate processes.

int main(int argc, char* argv[]) 
{ 
	srand(time(NULL)); 
	int timeLapse;
	int burst; 
	int prevTime = 0; 
	int n = atoi(argv[3]);  


	if (argc != 4) 
	{ 
		cout << "Incorrect arguments in generator" << endl;
		exit(0); 
	} 


	Process proc; 
	for (int i = 0; i < n; ++i) 
	{ 
		// time lapse is [0,49] inclusive
		timeLapse = rand() % 50; 
		
		// burst is [1,1000] inclusive
		burst = rand() % 1000 + 1; 

		proc.arrivalTime = timeLapse + prevTime; 
		proc.burst = burst; 
		proc.waitTime = 0; 


		prevTime = proc.arrivalTime; 
		proc.procNumber = i+1; 

		int len = write(*argv[2], &proc, sizeof(proc)); 
		if(len != sizeof(proc)) 
		{ 
			cout << "Error writing to pipe." << endl;
		} 
	} 

	close(*argv[2]); 

	return 0; 
} 
