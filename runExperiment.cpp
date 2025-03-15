#include "sort.h"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>  

using namespace std;

double measureSortingTime(string algorithm, int arr[], int n, long long& countCmp) {
    if (algorithm == "selection-sort") {
        auto start = chrono::high_resolution_clock::now();
        selectionSort(arr, n, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "insertion-sort") {
        auto start = chrono::high_resolution_clock::now();
        insertionSort(arr, n, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "shell-sort") {
        auto start = chrono::high_resolution_clock::now();
        shellSort(arr, n, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "bubble-sort") {
        auto start = chrono::high_resolution_clock::now();
        bubbleSort(arr, n, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "heap-sort") {
        auto start = chrono::high_resolution_clock::now();
        heapSort(arr, n, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "merge-sort") {
        auto start = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n - 1, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "quick-sort") {
        auto start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, n - 1, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "radix-sort") {
        auto start = chrono::high_resolution_clock::now();
        radixSort(arr, n, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "counting-sort") {
        auto start = chrono::high_resolution_clock::now();
        countingSort(arr, n, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "binary-insertion-sort") {
        auto start = chrono::high_resolution_clock::now();
        binaryInsertionSort(arr, n, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "shaker-sort") {
        auto start = chrono::high_resolution_clock::now();
        shakerSort(arr, n, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    if (algorithm == "flash-sort") {
        auto start = chrono::high_resolution_clock::now();
        flashSort(arr, n, countCmp);
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    }
    
    cout << "Error: Unknown sorting algorithm!" << endl;
    return -1;
}

void writeResults(string algorithm, string order, int size, double time, long long countCmp) {
    ofstream file("results.txt", ios::app);
    file << algorithm << " " << order << " " << size << " " << time << " ms " << countCmp << " comparisons\n";
    file.close();
}

void runExperiments() {
    vector<string> algorithms = {"selection-sort", "insertion-sort", "shell-sort", "bubble-sort", "heap-sort", "merge-sort", "quick-sort", "radix-sort", "counting-sort", "binary-insertion-sort", "shaker-sort", "flash-sort"}; // Thêm các thuật toán khác
    vector<string> dataOrders = {"-rand", "-sorted", "-rev", "-nsorted"};
    vector<int> dataSizes = {10000, 30000, 50000, 100000, 300000, 500000};

    for (int i = 0; i < 4; i++) {
        for (int size : dataSizes) {
            int* A1 = new int[size];
            GenerateData(A1, size, i);

            for (const string& algo : algorithms) {
                int* A2 = new int[size];
                A2 = A1;
                long long countCmp = 0;
                double time = 0.0;

                if (algo == "selection-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "insertion-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "shell-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "bubble-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "heap-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "merge-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "quick-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "radix-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "counting-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "binary-insertion-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "shaker-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }
                else if (algo == "flash-sort")
                {
                    time = measureSortingTime(algo, A2, size, countCmp);
                }



                cout << algo << " " << dataOrders[i] << " " << size << " Time: " << time << " ms Comparisons: " << countCmp << endl;
                writeResults(algo, dataOrders[i], size, time, countCmp);
                delete[] A2;
            }
            delete[] A1;
        }
    }
}
