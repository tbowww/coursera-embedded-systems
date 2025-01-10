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
 * @file stats.c
 * 
 * Set of functions that can analyze an array of unsigned char data items, report analytics on the maximum, 
 * minimum, mean, and median of the data set, and reorder this data set from large to small.
 *
 * @author Thibault Etienne
 * @date 20/11/2024
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  
  sort_array(test, SIZE);
  print_statistics(test, SIZE);  
  print_array(test, SIZE);
}

void sort_array(unsigned char arr[], unsigned int size) {
  int temp;
  for(int i=0; i<size; i++) {
    for(int j=i+1; j<size; j++) { 
      if(arr[i]<arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void print_statistics(unsigned char arr[], unsigned int size) {
  printf("Median = %d\n",find_median(arr, size));
  printf("Mean = %d\n",find_mean(arr, size));
  printf("Maximum = %d\n",find_maximum(arr, size));
  printf("Minimum = %d\n",find_minimum(arr, size));
}

unsigned char find_median(unsigned char arr[], unsigned int size) { 
  return arr[size / 2];
}


unsigned char find_mean(unsigned char arr[], unsigned int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum / size;
}

unsigned char find_maximum(unsigned char arr[], unsigned int size) {
  return arr[0];
}

unsigned char find_minimum(unsigned char arr[], unsigned int size) {
  return arr[size-1];
}


void print_array(unsigned char arr[], unsigned int size) {
  for (int i = 0; i < size; i++) {
    printf("Element %d : %d\n",i,arr[i]);
  }
}


