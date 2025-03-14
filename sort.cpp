#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void printList (int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void selectionSort(int arr[], int n, int& countCmp)
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

void bubbleSort(int arr[], int n, int& countCmp)
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

void merge (int arr[], int left, int mid, int right, int& countCmp)
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

void mergeSort (int arr[], int left, int right, int& countCmp)
{
    if (left >= right) return;
    countCmp++;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, countCmp);
    mergeSort(arr, mid+1, right, countCmp);
    merge(arr, left, mid, right, countCmp);
}

int binarySearch(int a[], int item, int left, int right, int& countCmp)
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

void binaryInsertionSort(int a[], int n, int& countCmp)
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

int main()
{
    int arr[] = {8,7,6,5,4,3,2,1,0};
    int n = 9;
    int countCmp = 0;
    cout << "List before sort: ";
    printList(arr, n);
    cout << endl;

    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // mergeSort(arr, 0, 8);
    binaryInsertionSort (arr, n, countCmp);
     // ahahahs
    cout << "List after sort: ";
    printList(arr, n);
    cout << endl << "Comparison: " << countCmp;

    return 0;
}
