Simulates and compares different page replacement algorithms
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
	- Once inside the correct directory with the files, use these commands (in order):
	
		- % make clean
		
		- % make
		
		- % a2

Description / user instructions: 

	This program simulates the OPT, LRU, and Clock page replacement algorithms.  Upon executing the program, the user will be prompted to enter a number to represent the number of frames used in the simulation of each algorithm.  The sequence of pages used in the simulation is found in pages.txt, and this sequence will be displayed on the console upon execution.  The user will only need to enter the number of desired frames, and then press ‘Enter’ twice.  Then (after pressing the ‘Enter’ key twice) the results of each algorithm after processing the same sequence of pages is displayed.
	
	The results are displayed as follows:
	
  - Columns represent the contents of the frames, in order from left to right
  
  - The number of columns(frames) is chosen by the user
  
  - An empty frame is represented by -1
  
  - Each row represents an incoming page from the sequence in ‘pages.txt’
  
  - There is one extra column that displays when a page in the sequence results in a page fault
  
  - Finally, the total number of faults is displayed after the last row.
  
  - This complete display is repeated for each algorithm for a total of 3 times
  
  - The user may need to scroll up and/or down to see the entire display
  - 
The ‘sequences’ file contains three separate page sequences of varying lengths.  Prior to the execution of the program, the user can choose to switch the sequence currently in the ‘pages.txt’ file with any of the three sequences in the ‘sequences’ file.  At the time of submission, ‘pages.txt’ is already loaded with the shortest sequence from the ‘sequences’ file.  

Analysis of results:

	The author chose to use three separate sets of page sequence data in various patterns - with counts of 12, 20, and 50 pages respectively.  Each sequence was processed with frame sizes of three and six, for a total of six result data sets.  Below is the number of faults generated for each algorithm, grouped by the number of pages in the sequence.

 	# of Faults
12 Page Sequence	
 	OPT	LRU	Clock
3 Frames	6	7	6
6 Frames	5	5	6

	# of Faults, 20 Page Sequence	 
 	        OPT	LRU	Clock
3 Frames	9	  12	11
6 Frames	9	  9	  9

	# of Faults
50 Page Sequence	 
 	OPT	LRU	Clock
3 Frames	24	32	32
6 Frames	14	17	21

Analysis cont. 
	The OPT algorithms performs at least as good as or better than the other two algorithms in every case - which is to be expected.  However, the results of the LRU and Clock algorithms are somewhat mixed.  The following is a comparison of the LRU and Clock algorithm results:
•	For the 12 page sequence, the LRU algorithm generated one more fault than Clock when there were three frames – but, LRU generated one less than Clock with six frames.  This could be thought of as a tie.
•	For the 20 page sequence, LRU and Clock performed very similar with Clock generating one less fault when there were three frames.  Slight edge to Clock here – but not much.    
•	For the 50 page sequence, the results are the same for three frames.  However, the biggest difference is here when there are six frames – LRU has 4 fewer faults than Clock.  LRU is the clear winner here.
Below is a graph that reflects the findings above with average page faults per algorithm when combining every data set.  OPT is clearly better, with LRU and Clock somewhat close when there are fewer frames, and then LRU clearly outperforming Clock when there are more frames and more pages in the sequence.  

	 

Notes on design:
	A simple design was used with a function for each page replacement algorithm.  A function to open the ‘pages.txt’ file and copy each page to an array was also implemented.  



