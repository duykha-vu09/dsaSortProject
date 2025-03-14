#ifndef SORT_H
#define SORT_H

void selectionSort(int arr[], int n, int& countCmp);

void bubbleSort(int arr[], int n, int& countCmp);

void merge (int arr[], int left, int mid, int right, int& countCmp);
void mergeSort (int arr[], int left, int right, int& countCmp);

int binarySearch(int a[], int item, int left, int right, int& countCmp);
void binaryInsertionSort(int a[], int n, int& countCmp);

void insertionSort(int arr[], int n, int& countCmp);

int partition(int arr[], int low, int high, int& countCmp);
void quickSort(int arr[], int low, int high,int& countCmp);

void countingSort(int arr[], int n, int& countCmp);

void flashSort(int arr[], int n,int& countCmp);

#endif