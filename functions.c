/*
Author:  Jason Ronquillo
These functions are used to simulate the OPT, LRU, and Clock page replacement algorithms.
*/

#include<stdio.h> 
#include "functions.h"

int n = 100; /* max number of pages in sequence */
int pagesArray[100]; /* array of pages */
int fr[100]; /* array for frames */
int frameSize;
FILE *pages;

/* opens "pages.txt" and scans each page in the sequence
   to an array - pagesArray[] */
int pagesFromTxt()
{
	pages = fopen("pages.txt", "r");
	
	int i;
	
	for (i = 0; i < n; i++)
		pagesArray[i] = -1;
	
	/* scans pages.txt and copies each page to an array */	
	for (i = 0; i < n; i++)
		fscanf(pages, "%d,", &pagesArray[i] );
		
	printf("\nThe page sequence from pages.txt is:  ");
	
	/* prints the sequence of pages in pages.txt */
	for (i = 0; i < n; i++)
	{
		if(pagesArray[i] != -1)
		printf("%d ", pagesArray[i]);
	}
	printf("\n");
}

void opt()
{
	int i, j, k, fault, flag, temp, current, c, max, m, cnt, p, x;
	fault = 0;
	k = 0; /* the # of filled frames */
	printf("\n**  Now testing the OPT algorithm  **\n");
	int distanceCount[frameSize]; /* an array the same size as the # of frames */
	
	/*initilizing distance and frame array*/
	for(i = 0; i < frameSize; i++)
	{
		distanceCount[i] = 0; 
		fr[i] = -1;
	}
	
	/* loops for the number of pages in sequence */
	for(i = 0; i < n; i++)
	{  	
		if(pagesArray[i] == -1) break; /* end of pages sequence */
	
		/* resets the distance counter for each frame */
		for(cnt = 0; cnt < frameSize; cnt++)
			distanceCount[cnt] = 0;
	
		flag = 0; /* 0 == page fault, 1 == no page fault */
		temp = pagesArray[i]; /* temp is now the current page in sequence */
		
		/* loops for the number of frames */
		for(j = 0; j < frameSize; j++)			
		{
			/* if the current page already exists in a frame */
			if(temp == fr[j])
			{
				flag = 1; /* no page fault */
				break;
			}
		}
		
		/* if a page fault occurs and empty frames exist */
		if((flag == 0) && (k < frameSize))
		{
			fault++;
			fr[k] = temp; /* k is the index of the empty frame */
			k++;
		}
		
		/* choosing which frame to replace a page with */
		else if((flag == 0) && (k == frameSize))
		{
			fault++;
			/* loops for the number of frames */			
			for(cnt = 0; cnt < frameSize; cnt++)			
			{		
				current = fr[cnt]; /* current is the page in the frame to check */
				
				/* loops for the remaining number of pages in the sequence */
				for(c = i; c < n; c++)
				{
					/* checks how long until a page is used again */
					if(current != pagesArray[c])
						distanceCount[cnt]++;
					else
						break;
				}
			}
			
			max=0;
			/* loops for the number of frames */
			for(m = 0; m < frameSize; m++)
			{
				if(distanceCount[m] > max)
				{
					/* max is the distance for the page that 
					will not be used for the longest time */
					max = distanceCount[m];
					p = m;
				}
			}
			/* p is the index for the frame with the page to be replaced */
			fr[p] = temp;
		}
		
		printf("\n");			
		for(x = 0; x < frameSize; x++)
		{
			printf("%d\t", fr[x]);
		}
		
		if(flag == 0) printf("Fault, page sequence %d", i);
	}
	printf("\nTotal number of faults with OPT algorithm = %d\n\n",fault);
	getchar();
} /* end of opt() */

void lru()
{
	int i, j, k, fault, flag, temp, current, c, max, m, cnt, p, x;
	fault = 0;
	k = 0; /* the # of filled frames */
	printf("\n**  Now testing the LRU algorithm  **\n");
	int dist[frameSize]; /* an array the same size as the # of frames */
	
	/* initilizing distance and frame array */	
	for(i = 0; i < frameSize; i++)
	{
		dist[i] = 0;
		fr[i] = -1;
	}
	
	/* loops for the number of pages in sequence */
	for(i = 0; i < n; i++)
	{ 	
		if(pagesArray[i] == -1) break; /* end of pages sequence */
		
		/* resets the distance counter for each frame */
		for(cnt = 0; cnt < frameSize; cnt++)
			dist[cnt] = 0;
				
		flag = 0; /* 0 == page fault, 1 == no page fault */
		temp = pagesArray[i]; /* temp is now the current page in sequence */
		
		/* loops for the number of frames */
		for(j = 0; j < frameSize; j++)
		{ 	
			/* if the current page already exists in a frame */		
			if(temp == fr[j])
			{ 
				flag = 1; /* no page fault */
				break;
			}
		}
		
		/* if a page fault occurs and empty frames exist */
		if((flag == 0) && (k < frameSize))
		{ 
			fault++;
			fr[k] = temp; /* k is the index of the empty frame */
			k++;
			//printf("\n* Fault here at page sequence: %d *", i);
		}
		
		/* choosing which frame to replace a page with */
		else if((flag == 0) && (k >= frameSize))
		{
			//printf("\n* Fault here at page sequence: %d *", i);
			fault++;
			/* loops for the number of frames */			
			for(cnt = 0; cnt < frameSize; cnt++) 		
			{		
				current = fr[cnt]; /* current is the page in the frame to check */
				
				/* loops only for the number of pages processed to this point */
				for(c = i; c > 0; c--) 
				{
					/* checks how long this page has been in the frame */
					if(current != pagesArray[c])
					{ 
						dist[cnt]++;
					}
					else
						break;
				}
			}
			
			max = 0;
			/* loops for the number of frames */
			for(m = 0; m < frameSize; m++)
			{
				if(dist[m] > max) 
				{
					/* max will equal the longest distance */
					max = dist[m]; 
					p = m;
				}
			}
			/* the current page should be assigned to the frame with the least used page */
			fr[p] = temp; 
		}
		
		printf("\n");			
		for(x = 0; x < frameSize; x++)
		{
			printf("%d\t", fr[x]);
		}
		if(flag == 0) printf("Fault, page sequence %d", i);
	}
	printf("\nTotal number of faults with LRU algorithm = %d\n\n",fault);
	getchar();
	
} /* end of lru() */

void clock()
{
	int i, j, flag, temp, x;
	int fault = 0;
	int rBit[frameSize]; /* an array for the R bits */
	int clockHand = 0; /* the clock hand pointer */
	
	printf("\n**  Now testing the Clock algorithm  **\n");
	
	/* initilizing frame and R Bit arrays */	
	for(i = 0; i < frameSize; i++)
	{
		fr[i] = -1;
		rBit[i] = 0;
	}
	
	/* loops for the number of pages in sequence */
	for(i = 0; i < n; i++)
	{ 	
		if(pagesArray[i] == -1) break; /* end of pages sequence */
		
		flag = 0; /* 0 == page fault, 1 == no page fault */
		temp = pagesArray[i]; /* temp is now the current page in sequence */
		
		/* loops for the number of frames */
		for(j = 0; j < frameSize; j++)
		{ 	
			/* if the current page already exists in a frame */		
			if(temp == fr[j])
			{ 
				flag = 1; /* no page fault */
				rBit[j] = 1;
				clockHand = j + 1;
				if(clockHand == frameSize)
					clockHand = 0;
				break;
			}
		}
		
		if(flag == 0)
		{
			/* search for a R bit set to zero*/
			while(rBit[clockHand] == 1)
			{
				rBit[clockHand] = 0;
				clockHand++;
				if(clockHand == frameSize)
					clockHand = 0;
			}
			
			/* at this point, the frame with an R bit 
			   set to zero has been found, and this is
			   the frame used for page replacement */
			fault++;
			fr[clockHand] = temp;
			rBit[clockHand] = 1;
			clockHand++;
			if(clockHand == frameSize)
				clockHand = 0;
		}
		
		printf("\n");			
		for(x = 0; x < frameSize; x++)
		{
			printf("%d\t", fr[x]);
		}
		if(flag == 0) printf("Fault, page sequence %d", i);
	} /* all pages have been looped through */
	
	printf("\nTotal number of faults with Clock algorithm = %d\n\n",fault);
	getchar();
	
} /* end of clock() */
