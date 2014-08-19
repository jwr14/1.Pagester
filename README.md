Simulate and compare different page replacement algorithms
========
Author:  Jason Ronquillo

summer 2014

This Filename:  README.docx

Files included:
	- main.c
	
	- functions.c
	
	- functions.h
	
	- pages.txt
	
	- sequences
	
	- Makefile

Compilation instructions:

	Once inside the correct directory with the files, use these commands (in order):
	
		- % make clean
		
		- % make
		
		- % a2

Description / user instructions: 

	This program simulates the OPT, LRU, and Clock page replacement algorithms.  Upon executing the 
	program, the user will be prompted to enter a number to represent the number of frames used in the 
	simulation of each algorithm.  The sequence of pages used in the simulation is found in pages.txt, 
	and this sequence will be displayed on the console upon execution.  The user will only need to 
	enter the number of desired frames, and then press ‘Enter’ twice.  Then (after pressing the ‘Enter’ 
	key twice) the results of each algorithm after processing the same sequence of pages is displayed.
	
	The results are displayed as follows:
	
  - Columns represent the contents of the frames, in order from left to right
  
  - The number of columns(frames) is chosen by the user
  
  - An empty frame is represented by -1
  
  - Each row represents an incoming page from the sequence in ‘pages.txt’
  
  - There is one extra column that displays when a page in the sequence results in a page fault
  
  - Finally, the total number of faults is displayed after the last row.
  
  - This complete display is repeated for each algorithm for a total of 3 times
  
  - The user may need to scroll up and/or down to see the entire display
  

	The ‘sequences’ file contains three separate page sequences of varying lengths.  Prior to the 
	execution of the program, the user can choose to switch the sequence currently in the ‘pages.txt’ 
	file with any of the three sequences in the ‘sequences’ file.  At the time of submission, ‘pages.txt’
	is already loaded with the shortest sequence from the ‘sequences’ file.  

	 

Notes on design:

	A simple design was used with a function for each page replacement algorithm.  A function to open the
	‘pages.txt’ file and copy each page to an array was also implemented.  



