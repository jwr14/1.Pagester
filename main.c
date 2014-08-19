/* 
Author:  Jason Ronquillo
CS570, summer '14
Assignment #2
*/

#include<stdio.h>
#include "functions.h"

int pagesArray[100]; /* array of pages */
int fr[100]; /* array for frames */
int frameSize;
FILE *pages;

void opt();
void lru();
void clock();

int main(int argc, char *argv[])
{
	
	printf("\nThis program will simulate the OPT, LRU, and Clock page replacement algorithms.\n");
	
	/* prompts the user to enter a frame size */
	printf("\nEnter frame size: ");
	scanf("%d",&frameSize);
	
	/* reads the pages from "pages.txt" to an array */
	pagesFromTxt();
	
	/* simulates the OPT page replacement algorithm */    
	opt();	
	
	/* simulates the LRU page replacement algorithm */ 
	lru();
	
	/* simulates the Clock page replacement algorithm */ 
	clock();
	
	fclose(pages);
	return 0;
	
} /* end of main */

