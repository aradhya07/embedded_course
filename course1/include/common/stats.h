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
 * @file <stats.h> 
 * @brief <Header file for stats.h and a part of week1 assignment >
 *
 * <Add Extended Description Here>
 *
 * @author <Aradhya Bhatia>
 * @date <Sept 13th, 2019>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
#include <stdint.h>
#include <platform.h>
/* Add Your Declarations and Function Comments here */ 
void stats();

void print_statistics (uint8_t *, int);
/**
 * @brief Prints the maximum, minimum, mean and median of the data array
 *
 * This function takes in 2 parameters, the pointer for the array and the length of 
 * the data array and prints on stdout, the maximum, the minimum value from the data  
 * alongwith the mean and median.
 *
 * @param ptr --> the pointer to the first element of the array passed
 * @param size --> the length of the array 
 */

int find_maximum (uint8_t *, int);
/**
 * @brief Finds the maximum value of the data array
 *
 * This function takes in 2 parameters, the pointer for the array and the length of 
 * the data array and returns the maximum value
 *
 * @param ptr --> the pointer to the first element of the array passed
 * @param size --> the length of the array 
 *
 * @return Returns the max value of the data array
 */

int find_minimum (uint8_t *, int);
/**
 * @brief Finds the minimum value of the data array
 *
 * This function takes in 2 parameters, the pointer for the array and the length of 
 * the data array and returns the minimum value
 *
 * @param ptr --> the pointer to the first element of the array passed
 * @param size --> the length of the array 
 *
 * @return Returns the min value of the data array
 */

int find_mean (uint8_t *, int);
/**
 * @brief Finds the mean value of the data array
 *
 * This function takes in 2 parameters, the pointer for the array and the length of 
 * the data array and returns the mean value
 *
 * @param ptr --> the pointer to the first element of the array passed
 * @param size --> the length of the array 
 *
 * @return Returns the mean value of the data array
 */

int find_median (uint8_t *, int);
/**
 * @brief Finds the median of the data array
 *
 * This function takes in 2 parameters, the pointer for the array and the length of 
 * the data array and returns the median value
 *
 * @param ptr --> the pointer to the first element of the array passed
 * @param size --> the length of the array 
 *
 * @return Returns the median value of the data array
 */

void print_array (uint8_t *, int);
/**
 * @brief Prints the data array
 *
 * This function takes in 2 parameters, the pointer for the array and the length of 
 * the data array and prints on stdout, all the elements of the array
 *
 * @param ptr --> the pointer to the first element of the array passed
 * @param size --> the length of the array 
 */

void sort_array (uint8_t *, int);
/**
 * @brief Sorts all the elements of the array in descending order
 *
 * This function takes in 2 parameters, the pointer for the array and the length of 
 * the data array and sorts the array itself in descending order. It does not make a copy
 * of the array but makes all the changes in the original one
 
 * @param ptr --> the pointer to the first element of the array passed
 * @param size --> the length of the array 
 */

#endif /* __STATS_H__ */
