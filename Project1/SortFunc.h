#pragma 
#include <iostream>
#ifndef SORTFUNC_H
#define SORTFUNC_H
int binarySearch(int* arr, int l, int r, int x);
void quickSort(int* arr, int l, int r);
void insertionSort(int* arr, int size);
void bogoSort(int* arr, int size);
void countingSort(char* arr, int size);
void printArray(int* arr, int size);
void printArray(char* arr, int size);
bool isSorted(int arr[], int n);
#endif