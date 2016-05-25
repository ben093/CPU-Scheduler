Implement a CPU scheduler with the non-preemptive SJF scheduling algorithm in C++.  Use FCFS as the tie breaker among multiple processes with the same CPU burst time if there are any.  You will simulate an arrival sequence of n (entered through a command line argument) processes and find the waiting time of each process under the non-preemptive SJF scheduler.  

To simulate the arrival process sequence, the scheduler generates a non-duplicated child process, called generator.  The generator pretends to generate n processes (no need to actually generate a process).  Each time, using a random number generator, the generator 1) generates a time lapse in the inclusive range [0, 49] and a CPU burst time in the inclusive range [1, 1000] for the next arriving process (assume both measures are in units of “quantum”); 2) packs the arrival time (i.e., the time lapse + the arrival time of the previous process) and the CPU burst of the process into a “PCB” (can be implemented with a data item of type struct or class) and sends the PCB to the scheduler through a pipe.  

The scheduler maintains a pseudo timer starting with t=0 and a ready queue.  When a process “arrives”, the scheduler queues its PCB at the end of the ready queue.  When the scheduler selects a process for CPU, it 1) computes the waiting time for the process; 2) removes its PCB from the ready queue; 3) advances the timer by the amount of the CPU burst for the process (for simplicity, we ignore the time consumed by the scheduler).  If a process terminates at the same time as a process arrives, the scheduler should first select a process from the ready queue, and then add the arriving process into the ready queue.  Finally, the scheduler writes to the current working directory (i.e., the default file location) the scheduling results with the header line in a pure text file “record.txt” in order of the process arrival times in the following format (important: do not write any other non-required info into the file):  


    Arrival time	Process	CPU burst	Waiting time  
      5	            1	        2	          ?  
     17	            2	        8	          ?  
      ?	            ?	        ?	          ?  
      ?	            n	        ?	          ?  

The program must be implemented with multiple source files.
