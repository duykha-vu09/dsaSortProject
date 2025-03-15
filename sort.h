#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>  

using namespace std;

void selectionSort(int arr[], int n, long long& countCmp);

void bubbleSort(int arr[], int n, long long& countCmp);

void merge (int arr[], int left, int mid, int right, long long& countCmp);
void mergeSort (int arr[], int left, int right, long long& countCmp);

int binarySearch(int a[], int item, int left, int right, long long& countCmp);
void binaryInsertionSort(int a[], int n, long long& countCmp);

void insertionSort(int arr[], int n, long long& countCmp);

int partition(int arr[], int low, int high, long long& countCmp);
void quickSort(int arr[], int low, int high,long long& countCmp);

void countingSort(int arr[], int n, long long& countCmp);

void flashSort(int arr[], int n,long long& countCmp);

void shellSort(int a[], int n, long long& countCmp);

void shakerSort(int a[], int n, long long& countCmp);

void heapRebuild(int i, int a[], int n, long long& countCmp);
void heapConstruct(int a[], int n, long long& countCmp);
void heapSort(int a[], int n, long long& countCmp);

void radixSort(int a[], int n, long long& countCmp);

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);

void GenerateData(int a[], int n, int dataType);

double measureSortingTime(string algorithm, int arr[], int n, long long& countCmp);
void writeResults(string algorithm, string order, int size, double time, long long countCmp);
void runExperiments();

#endif
