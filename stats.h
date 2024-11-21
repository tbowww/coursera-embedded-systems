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
 * @file stats.h
 * 
 * Set of functions that can analyze an array of unsigned char data items, report analytics on the maximum, 
 * minimum, mean, and median of the data set, and reorder this data set from large to small.
 *
 * @author Thibault Etienne
 * @date 20/11/2024
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param unsigned char arr[]: Array
 * @param int size: Size of the array
 */
void print_statistics(unsigned char arr[], unsigned int size);

/**
 * Given an array of data and a length, prints the array to the screen
 *
 * @param unsigned char arr[]: Array
 * @param int size: Size of the array
 */
void print_array(unsigned char arr[], unsigned int size);

/**
 * Given an array of data and a length, returns the median value
 *
 * @param unsigned char arr[]: Array
 * @param int size: Size of the array
 *
 * @return Median of the array elements, rounded to the nearest integer
 */
unsigned char find_median(unsigned char arr[], unsigned int size);

/**
 * Given an array of data and a length, returns the mean
 *
 * @param unsigned char arr[]: Array
 * @param int size: Size of the array
 *
 * @return Mean of the array elements, rounded to the nearest integer
 */
unsigned char find_mean(unsigned char arr[], unsigned int size);

/**
 * Given an array of data and a length, returns the maximum
 *
 * @param unsigned char arr[]: Array
 * @param int size: Size of the array
 *
 * @return Maximum of the array elements
 */
unsigned char find_maximum(unsigned char arr[], unsigned int size);

/**
 * Given an array of data and a length, returns the minimum
 *
 * @param unsigned char arr[]: Array
 * @param int size: Size of the array
 *
 * @return Minimum of the array elements
 */
unsigned char find_minimum(unsigned char arr[], unsigned int size);
 
/**
 * Given an array of data and a length, sorts the array from largest to smallest.  
 *
 * @param unsigned char arr[]: Array
 * @param int size: Size of the array
 */
void sort_array(unsigned char arr[], unsigned int size);

#endif /* __STATS_H__ */
