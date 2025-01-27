1.Shell Scripting 
We will simulate a situation where, during a ship evacuation drill, it is desirable to manage and analyze the data of the participants involved in the exercise. Write a shell script to process a file containing passenger information and generate reports. The name of the shell script will be:
processes_ipc.sh

The script will perform the following tasks:

[1] Data Entry into the Application
The program will prompt for data entry. If no filename is provided (including its path), it will request data input via the keyboard. A sample file is passengers.csv (available on eClass). This file stores the passenger details, with each line containing information in the following format:
[code],[fullname],[age],[country],[status (Passenger/Crew)],[rescued (Yes/No)]
If the data is entered via the keyboard, it should be saved to passengers.csv.

[2] Display Passenger Information
The program will accept a passenger’s first or last name, search for their details, and display them on the screen.

[3] Update Passenger Information
The program will request the passenger’s code, name, or last name, along with the field that needs updating. The user can select either a specific field for correction or the entire record. The field selection should be done by providing the field name and its new value as an argument. For example:

bash
./processes_ipc <code or first/last name of passenger> fullname:<new value>
./processes_ipc <code or first/last name of passenger> record:<new record>
The program will update/correct the data and display the old and updated details of the passenger.

[4] File Display
The program will display all records and their details on the screen. It should pause when the screen is full, waiting for the user to press <space> to show more entries.

[5] Report Generation
The program will generate reports with the following characteristics:

Identification and display of passenger age groups (e.g., 0–18, 19–35, 36–50, 51+).
Calculation of the rescue percentage for each age group.
Calculation of the average age for each passenger category (age group/passenger category).
Filtering the data to create a new file containing only the "rescued" passengers.
Reports should be generated by executing:

bash
./processes_ipc reports
The reports should be exported to the following files:

ages.txt
percentages.txt
avg.txt
rescued.txt
Requirements:

Use AWK for analytical processing and statistical calculations.
Use SED to update records in the data files and GREP for filtering.
Create the following functions:
insert_data
search_passenger
update_passenger
display_file
generate_reports


2.Process Synchronization and Semaphores
We will simulate a situation during a ship evacuation exercise where there is an effort to find an effective way to rescue passengers. On the ship, the available lifeboats are limited and much fewer than the total number of passengers, and each lifeboat has a limited number of seats. Since the shore is nearby, if proper coordination is achieved, everyone will be rescued in a real-life scenario. Passengers try to board the lifeboats in a safe and synchronized manner. The number of passengers allowed to board is determined by a numeric semaphore restriction.

The goal is to allow processes to board up to the lifeboat's maximum capacity and wait if it is full. Passengers queue up for the lifeboats and begin boarding. However, if a passenger changes their mind and decides not to board, they move to the end of the queue, leaving a spot available for someone else to board. Once a lifeboat is full, it departs. Additionally, when a lifeboat returns from disembarking passengers onshore, it joins the queue to serve more passengers.

Write a program to synchronize the above evacuation process. The solution should include the following files:

ipc_utils.h for semaphore setup and basic helper functions.
passenger.c for processes representing passengers trying to board the lifeboat.
launch.c as the main program, which reads the number of passengers, lifeboats, and available seats and configures the lifeboat capacities.


3.Process Scheduling and Memory Management
In a computing system with 512 KB of total memory for user processes, five processes arrive with varying arrival times, durations, and memory requirements. The data should be read from the keyboard. Memory is managed with variable partitions, and the scheduling algorithm is Round Robin with a time quantum of 3 ms. Memory allocation uses the First Fit algorithm. At each moment, provide the CPU and memory state for servicing the processes.

Example:
Each process has:

Process ID (pid)
Arrival time (arrival_time)
Duration (duration)
Remaining execution time (remaining_time)
Required memory (memory_needed)
Indication if it is in memory (in_memory)
The memory is modeled as an array MemoryBlock, where each element represents 1 KB. Each block has:

Starting position (start)
Size (size)
Whether it is free (free)
The pid of the process owning it
All memory starts as free.

4.Process Scheduling 
Consider six (6) processes with arrival times (AT) and execution durations (ED) as follows:

Process	Arrival Time (AT)	Execution Duration (ED)	PID
A	0	6	3
B	2	4	1
C	3	1	2
D	4	3	5
E	5	5	4
F	6	7	1
(a) Draw Gantt charts for the following scheduling algorithms:

FCFS (First Come First Serve)
SJF (Shortest Job First)
SRTF (Shortest Remaining Time First)
RR (Round Robin) with a time quantum of 2 units.
Assume that if a process leaves the CPU and a new process arrives at the same time, the process leaving the CPU enters the queue first.
(b) For each algorithm, calculate:

Average wait time 
Average response time 
Average completion time 
Number of context switches 
(c) Design a preemptive scheduling algorithm called Longest Remaining Time First Preemptive (LRTFP). This algorithm serves processes with the longest remaining time first. In case of ties, use PID priority, favoring processes with the smallest PID. Provide:

Gantt chart for LRTFP 
Average wait time 
Average response time 
Average completion time 
Number of context switches 
