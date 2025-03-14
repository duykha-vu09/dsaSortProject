#include "sort.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>  

using namespace std;

void printList (int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {8,7,6,5,4,3,2,1,0,5};
    int n = 10;
    int countCmp = 0;
    cout << "List before sort: ";
    printList(arr, n);
    cout << endl;

    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // mergeSort(arr, 0, 8);
    // binaryInsertionSort (arr, n, countCmp);
    insertionSort (arr, n, countCmp);

    cout << "List after sort: ";
    printList(arr, n);
    cout << endl << "Comparison: " << countCmp;

    return 0;
}