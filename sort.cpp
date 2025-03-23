#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int arr[], int n, long long& countCmp)
{
    for (int i = 0; countCmp++, i < n; i++)
    {
        int min = arr[i];
        int idx = i;
        for (int j = i + 1; countCmp++, j < n; j++)
        {
            if (countCmp++, min > arr[j])
            {
                min = arr[j];
                idx = j;
            }
        }
        swap(arr[i], arr[idx]);
    }
}

void bubbleSort(int arr[], int n, long long& countCmp)
{
    for (int i = 0; countCmp++, i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; countCmp++, j < n - i - 1; j++)
        {
            if (countCmp++, arr[j] > arr[j+1]) 
            {
                swap(arr[j], arr[j+1]);
                swapped = true; 
            }
        }
        //If not swap any element -> array is sorted -> skip the rest steps 
        if (countCmp++, !swapped) break;
    }
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
    while ((countCmp++, first < left + n) && (countCmp++, second <= right))
    {
        if (countCmp++, arr[first] < arr[second])
        {
            tmp[idx++] = arr[first++];
        }
        else
        {
            tmp[idx++] = arr[second++];
        }
    }

    //Copy the remaining elements
    while (countCmp++, first < left + n) {
        tmp[idx++] = arr[first++];
    }

    while (second <= right) {
        tmp[idx++] = arr[second++];
    }
    
    //Copy elements from temp array to the original array
    for (int i = 0; countCmp++, i < m + n; i++)
    {
        arr[left+i] = tmp[i];
    }
    
    delete[] tmp;
}

void mergeSort (int arr[], int left, int right, long long& countCmp)
{
    if (countCmp++, left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, countCmp);
    mergeSort(arr, mid+1, right, countCmp);
    merge(arr, left, mid, right, countCmp);
}

int binarySearch(int a[], int item, int left, int right, long long& countCmp)
{
    if (countCmp++, right <= left) 
    {
        if (countCmp++, item > a[left])
            return left + 1;
        else
            return left;
    }

    int mid = (left + right) / 2;

    if (countCmp++, item == a[mid]) return mid + 1;

    if (countCmp++, item > a[mid])
    {
        return binarySearch(a, item, mid + 1, right, countCmp);
    }

    return binarySearch(a, item, left, mid - 1, countCmp);
}

void binaryInsertionSort(int a[], int n, long long& countCmp)
{
    int i, pos, j, key;

    for (i = 1; countCmp++, i < n; ++i)
    {
        j = i - 1;
        key = a[i];

        // Find correct position of the key 
        pos = binarySearch(a, key, 0, j, countCmp);

        // Move all elements after key's position to create space to put key 
        while (countCmp++, j >= pos)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
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

void insertionSortforFlashSort(int arr[], int start, int end, long long& countCmp) {
    for (int i = start + 1; countCmp++, i < end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (countCmp++, j >= start && countCmp++, arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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
    int start = 0;
    for (int g = 0; g < groupindex; g++) {
        int end = group[g];
        insertionSortforFlashSort(arr, start, end, countCmp);
        start = end;
    }

    delete[] group;
}

void shellSort(int a[], int n, long long& countCmp) {
    countCmp = 0;
     // Start with a big gap, then reduce the gap
    for (int gap = n / 2; countCmp++, gap > 0; gap /= 2) {
        // Perform a gapped insertion sort
        for (int i = gap; countCmp++, i < n; i++) {
            int temp = a[i];
            int j;
            // Shift elements that are greater than temp to the right
            for (j = i; (countCmp++, j >= gap) && (countCmp++, a[j - gap] > temp); j -= gap) {
                 // Shift the element at j - gap to position j
                a[j] = a[j - gap];
            }
            //Place temp in correct positionposition
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
        // Perform a bubble sort from left to right
        for (int i = start; countCmp++, i < end; i++) {
            if (countCmp++, a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // If nothing moved, then array is sorted
        if (countCmp++, !swapped) {
            break;
        }
        swapped = false;
        end--;
        // Perform a bubble sort from right to left
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
    int largest = i;    // Assume the root is the largest
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ((countCmp++, left < n) && (countCmp++, a[left] > a[largest])) {    // If left child is larger than root
        largest = left;
    }

    if ((countCmp++, right < n) && (countCmp++, a[right] > a[largest])) {    // If right child is larger than root
        largest = right;
    }
    if (countCmp++, largest != i) {
        swap(a[i], a[largest]);    // Swap root with the largest child
        heapRebuild(largest, a, n, countCmp);
    }
}

// Construct a max-heap
void heapConstruct(int a[], int n, long long& countCmp) {
    for (int i = n / 2 - 1; countCmp++, i >= 0; i--) {
        heapRebuild(i, a, n, countCmp);
    }
}

// Heapify
void heapSort(int a[], int n, long long& countCmp) {
    countCmp = 0;
    //Build the max-heap
    heapConstruct(a, n, countCmp);
    int r = n - 1;
    while (countCmp++, r > 0) {
        swap(a[0], a[r]);		// Swap the root with the last element
        heapRebuild(0, a, r, countCmp);		//Rebuild the heap
        r--;
    }
}

void radixSort(int a[], int n, long long& countCmp) {
    countCmp = 0;
    int minn = minArray(a, n, countCmp);    // Find the minimum value in the array
    // Create a shifted array
    int* shiftedArr = new int[n];
    for (int i = 0; countCmp++, i < n; i++) {
        shiftedArr[i] = a[i] - minn;
    }

    int maxx = shiftedArr[maxArray(shiftedArr, n, countCmp)];    // Find the maximum value in the shifted array
    // Perform counting sort for each digit(from least significant to most significant)
    for (int exp = 1; countCmp++, maxx / exp > 0; exp *= 10) {
        countingSort(shiftedArr, n, countCmp);
    }
    // Shift the sorted array back to its original range
    for (int i = 0; countCmp++, i < n; i++) {
        a[i] = shiftedArr[i] + minn;
    }

    delete[] shiftedArr;
}
