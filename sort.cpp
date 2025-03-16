#include <iostream>
#include "sort.h"

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int arr[], int n, long long& countCmp)
{
    for (int i = 0; i < n; i++)
    {
        countCmp++;
        int min = arr[i];
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            countCmp++;
            if (min > arr[j])
            {
                min = arr[j];
                idx = j;
            }
            countCmp++;
        }
        countCmp++;
        swap(arr[i], arr[idx]);
    }
    countCmp++;
}

void bubbleSort(int arr[], int n, long long& countCmp)
{
    for (int i = 0; i < n - 1; i++)
    {
        countCmp++;
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            countCmp++;
            if (arr[j] > arr[j+1]) 
            {
                swap(arr[j], arr[j+1]);
                swapped = true; 
            }
            countCmp++;
        }
        countCmp++;
        //If not swap any element -> array is sorted -> skip the rest steps 
        if (!swapped) break;
        countCmp++;
    }
    countCmp++;
}

void merge (int arr[], int left, int mid, int right, long long& countCmp)
{
    int n = mid - left + 1;
    int m = right - mid;

    int first = left;
    int second = mid + 1;
    int idx = 0;

    int* tmp = new int[n + m];
    //Compare sub_array 1 with sub_array 2 then put element that meet the conditioncondition into the temp array
    while (first < left + n && second <= right)
    {
        countCmp += 2;
        if (arr[first] < arr[second])
        {
            tmp[idx++] = arr[first++];
        }
        else
        {
            tmp[idx++] = arr[second++];
        }
        countCmp++;
    }
    countCmp++; //?????

    //Copy the remaining elements
    while (first < left + n) {
        countCmp++;
        tmp[idx++] = arr[first++];
    }
    countCmp++;

    while (second <= right) {
        countCmp++;
        tmp[idx++] = arr[second++];
    }
    countCmp++;
    
    //Copy elements from temp array to the original array
    for (int i = 0; i < m + n; i++)
    {
        countCmp++;
        arr[left+i] = tmp[i];
    }
    countCmp++;
    
    delete[] tmp;
}

void mergeSort (int arr[], int left, int right, long long& countCmp)
{
    if (left >= right) return;
    countCmp++;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, countCmp);
    mergeSort(arr, mid+1, right, countCmp);
    merge(arr, left, mid, right, countCmp);
}

int binarySearch(int a[], int item, int left, int right, long long& countCmp)
{
    if (right <= left) 
    {
        countCmp++;
        if (item > a[left])
            return left + 1;
        else
            return left;
    }
    countCmp++;

    int mid = (left + right) / 2;

    if (item == a[mid]) return mid + 1;
    countCmp++;

    if (item > a[mid])
    {
        return binarySearch(a, item, mid + 1, right, countCmp);
    }
    countCmp++;

    return binarySearch(a, item, left, mid - 1, countCmp);
}

void binaryInsertionSort(int a[], int n, long long& countCmp)
{
    int i, pos, j, key;

    for (i = 1; i < n; ++i)
    {
        countCmp++;
        j = i - 1;
        key = a[i];

        // Find correct position of the key 
        pos = binarySearch(a, key, 0, j, countCmp);

        // Move all elements after key's position to create space to put key 
        while (j >= pos)
        {
            countCmp++;
            a[j + 1] = a[j];
            j--;
        }
        countCmp++;
        a[j + 1] = key;
    }
    countCmp++;
}

int maxArray(int arr[], int n, long long& countCmp) {            //Find Max Element in Array
    int Max = 0;
    for (int i = 0; countCmp++, i < n; i++) {
        if (countCmp++,arr[i] > arr[Max]) {
            Max = i;
        }
    }
    return Max;
}

int minArray(int arr[], int n, long long& countCmp) {            //Find Min Element in Array
    int Min = arr[0];
    for (int i = 0; countCmp++, i < n; i++) {
        if (countCmp++,arr[i] < Min) {
            Min = arr[i];
        }
    }
    return Min;
}


void insertionSort(int arr[], int n, long long& countCmp) {
    for (int i = 1; countCmp++, i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (countCmp++, j >= 0 && countCmp++, arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high, long long& countCmp) {
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];                  // Middle Element
    swap(arr[mid], arr[high]);             // Move pivot to end for partitioning
    int i = low - 1;
    for (int j = low; countCmp++, j < high; j++) {
        if (countCmp++, arr[j] <= pivot) {              // if the number with idx j is smaller than pivot 
            i++;                            // it will be swapped with the number that is larger than pivot (idx i)
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;                           // Return the pivot index to get 2 arrays on 2 sides of the pivot
}

void quickSort(int arr[], int low, int high, long long& countCmp) {
    if (countCmp++, low < high) {
        int pivotIndex = partition(arr, low, high, countCmp);    // get the pivot index
        quickSort(arr, low, pivotIndex - 1, countCmp);            // Partition the Array on the left of the Pivot
        quickSort(arr, pivotIndex + 1, high, countCmp);           // Partition the Array on the right of the Pivot
    }
    return;
}

void countingSort(int arr[], int n, long long& countCmp) {
    int Max = arr[maxArray(arr, n, countCmp)] + 1;
    int* countArray = new int[Max]();           //Create new array to count how many time does a element appear
    for (int i = 0; countCmp++, i < n; i++) {
        countArray[arr[i]]++;
    }

    for (int i = 1; countCmp++, i < Max; i++) {             //Store Prefix Sum of the elements in countArray
        countArray[i] += countArray[i - 1];
    }

    int* outputArray = new int[n]();                //Store sorted Array in outputArray
    for (int i = n - 1; countCmp++, i >= 0; i--) {
        outputArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]] = countArray[arr[i]]--;
    }
    
    for (int i = 0; countCmp++, i < n; i++) {                   //Copy to original Array
        arr[i] = outputArray[i];
    }
    delete[]countArray;
    delete[]outputArray;
}

void flashSort(int arr[], int n,long long& countCmp) {
    int max = maxArray(arr, n, countCmp);
    int minVal = minArray(arr, n, countCmp);
    int groupindex = int(n * 0.45);              //Calculating the number of groups to divide the array
    int* group = new int[groupindex]();
    double c = ((groupindex - 1) / (arr[max]-minVal));
    for (int i = 0; countCmp++, i < n; i++) {
        int m = int(c * (arr[i] - minVal));                                    //Calculating how many elements each group has
        group[m]++;
    }
    for (int i = 1; countCmp++, i < groupindex; i++) {          //Calculating the starting index of each group
        group[i] += group[i - 1];
    }
    //Hoan vi
    int count = 0;
    int i = 0;
    while (countCmp++,count < n) {
        int m = int(c * (arr[i] - minVal));
        while (countCmp++,i >= group[m]) {
            m = int(c * (arr[++i] - minVal));
        }
        int value = arr[i];
        while (countCmp++,i != group[m]) {
            m = int(c * (value - minVal));
            swap(value, arr[group[m] - 1]);
            group[m]--;
            count++;
        }
    }
    //Insertion Sort again
    for (int i = 1; countCmp++, i < n; i++) {
        int j = 0;
        while (countCmp++,j < i) {
            if (countCmp++,arr[j] > arr[i]) {
                swap(arr[j], arr[i]);
            }
            j++;
        }
    }
}

void shellSort(int a[], int n, long long& countCmp) {
    countCmp = 0;
    for (int gap = n / 2; countCmp++, gap > 0; gap /= 2) {
        for (int i = gap; countCmp++, i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; countCmp++, j >= gap && countCmp++, (j - gap) >= 0 && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

void shakerSort(int a[], int n, long long& countCmp) {
    countCmp = 0;
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; countCmp++, i < end; i++) {
            if (countCmp++, a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (countCmp++, !swapped) {
            break;
        }
        swapped = false;
        end--;
        for (int i = end - 1; countCmp++, i >= start; i--) {
            if (countCmp++, a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        start++;
    }
}

void heapRebuild(int i, int a[], int n, long long& countCmp) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (countCmp++, left < n && (countCmp++, a[left] > a[largest])) {
        largest = left;
    }

    if (countCmp++, right < n && (countCmp++, a[right] > a[largest])) {
        largest = right;
    }
    if (countCmp++, largest != i) {
        swap(a[i], a[largest]);
        heapRebuild(largest, a, n, countCmp);
    }
}

void heapConstruct(int a[], int n, long long& countCmp) {
    for (int i = n / 2 - 1; countCmp++, i >= 0; i--) {
        heapRebuild(i, a, n, countCmp);
    }
}

void heapSort(int a[], int n, long long& countCmp) {
    countCmp = 0;
    heapConstruct(a, n, countCmp);
    int r = n - 1;
    while (countCmp++, r > 0) {
        swap(a[0], a[r]);
        heapRebuild(0, a, r, countCmp);
        r--;
    }
}

void radixSort(int a[], int n, long long& countCmp) {
    countCmp = 0;
    int minn = minArray(a, n, countCmp);

    int* shiftedArr = new int[n];
    for (int i = 0; countCmp++, i < n; i++) {
        shiftedArr[i] = a[i] - minn;
    }

    int maxx = a[maxArray(shiftedArr, n, countCmp)];
    for (int exp = 1; countCmp++, maxx / exp > 0; exp *= 10) {
        countingSort(shiftedArr, n, countCmp);
    }

    for (int i = 0; countCmp++, i < n; i++) {
        a[i] = shiftedArr[i] + minn;
    }

    delete[] shiftedArr;
}


