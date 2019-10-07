/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c file> 
 * @brief <priints various statistics and is a part of week1 assignment>
 *
 * <Add Extended Description Here>
 *
 * @author <Aradhya Bhatia>
 * @date <Sept 13th, 2019>
 *
 */

#include "stats.h"
#include <stdint.h>

/* Size of the Data Set */
#define SIZE (40)

void stats()
{

	uint8_t test[SIZE] = {   34, 201, 190, 154,   8, 194,   2,   6,
  	                              114, 88,   45,  76, 123,  87,  25,  23,
	                              200, 122, 150, 90,   92,  87, 177, 244,
          	                      201,   6,  12,  60,   8,   2,   5,  67,
                  	              7,  87, 250, 230,  99,   3, 100,  90};

	/* Other Variable Declarations Go Here*/ 

	/* Statistics and Printing Functions Go Here */
	sort_array (test,SIZE);
#ifdef VERBOSE 
	print_array (test,SIZE);
#endif
	print_statistics (test,SIZE);

}

/* Add other Implementation File Code Here */
void print_statistics(uint8_t *ptr, int size)
{
	int max, min, mean, median;
	max = find_maximum (ptr,size);
	min = find_minimum (ptr,size);
	mean = find_mean (ptr,size);
	median = find_median (ptr,size);
	PRINTF("\nThe max value of the array is: %d",max);
	PRINTF("\nThe min value of the array is: %d",min);
	PRINTF("\nThe mean of the array is: %d",mean);
	PRINTF("\nThe median of the array is: %d\n",median);
}

int find_maximum(uint8_t *ptr, int size) 
{
	int i;
	int max;
	max=0;
	for(i=0; i<size; ++i)
		if (max < (ptr)[i])
			max = (ptr)[i];
	return max;
}
int find_minimum(uint8_t *ptr, int size) 
{
	int i;
	int min;
	min=100;
	for(i=0; i<size; ++i)
		if (min > (ptr)[i])
			min=(ptr)[i];
	return min;
}
int find_mean(uint8_t *ptr, int size) 
{
	int i, sum, mean;
	float mean_float;	
	mean = 0;
	sum = 0;
	for(i=0; i<size; ++i)
		sum+=((ptr)[i]);
	mean_float = (float) sum / size;
	mean = (int) mean_float;
	return mean;
}
int find_median(uint8_t *ptr, int size) 
{
	int median;
	//sort_array (ptr,size);
	if (size%2==0)
	{
		median=(ptr)[(size/2)];
		median=(median+(ptr)[(size/2)+1]);
		median=(median/2);
	}
	else
	{
		median=(ptr)[(size/2)+1];
	}
	return median;
}
void sort_array(uint8_t *ptr, int size)
{
	int i,j;
	int temp;
	for(i=0; i<size; ++i)
	{
		for(j=0; j<size; ++j)
		{
			if((ptr)[j] < (ptr)[j+1])
			{
				temp=(ptr)[j];
				(ptr)[j]=(ptr)[j+1];
				(ptr)[j+1]=temp;
			}
		}
	}
}

void print_array(uint8_t *ptr, int size)
{
	int i;
	for(i=0; i<size; ++i)
		PRINTF("\nElement number: %d --> Data: %d",i+1,(ptr)[i]);
}
