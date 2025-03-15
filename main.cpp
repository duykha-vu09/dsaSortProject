#include "sort.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool isNumber(const char* str) {
    if (!str || *str == '\0') return false;  // Handle null or empty string
    while (*str) {
        if (!isdigit(static_cast<unsigned char>(*str))) {
            return false;
        }
        ++str;
    }
    return true;
}

bool isLetter(const char* str) {
    if (!str || *str == '\0') return false;  // Handle null or empty string
    while (*str) {
        if (!isalpha(static_cast<unsigned char>(*str))) {
            return false;
        }
        ++str;
    }
    return true;
}

//Copy New Array
void copyArray(int a[], int b[], int n) {

    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

void readArrayfromFile(const string& fileName, int& n, int*& arr) {
    ifstream fin(fileName);
    if (!fin.is_open()) {
        cout << "Can't open file\n";
        return;
    }
    fin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }

    fin.close();
}

int main(int argc, char* argv[])
{
    long long countCmp = 0;

    double runTime = 0;

    string mode = argv[1];

    if (mode == "-a") {
        string algorithm = argv[2];
        cout << "ALGORITHM MODE\n";
        cout << "Algorithm: " << algorithm << "\n";
        if (argc < 4) {
            cout << "Invalid Command";
            return 1;
        }
        if (argc == 5) {
            if (isNumber(argv[3])) {                   //Command 3

                string size = argv[3];
                string parameter = argv[4];

                cout << "Input size: " << size << "\n\n";

                int n = stoi(size);
                int* A1 = new int[n];
                int* A2 = new int[n];

                //Randomize
                cout << "Input order: Randomize\n";


                GenerateData(A1, n, 0);
                copyArray(A1, A2, n);

                runTime = measureSortingTime(algorithm, A2, n, countCmp);

                //Result
                if (parameter == "-time" || parameter == "-both") {
                    cout << "Running time : " << runTime << "ms\n";
                }
                if (parameter == "-comp" || parameter == "-both") {
                    cout << "Comparisons : " << countCmp << "\n";
                }
                cout << "--------------------------------------\n";

                //Nearly Sorted
                cout << "Input order: Nearly Sorted\n";


                // GenerateData(A1, n, 3);
                copyArray(A1, A2, n);

                runTime = measureSortingTime(algorithm, A2, n, countCmp);

                //Result
                if (parameter == "-time" || parameter == "-both") {
                    cout << "Running time : " << runTime << "ms\n";
                }
                if (parameter == "-comp" || parameter == "-both") {
                    cout << "Comparisons : " << countCmp << "\n";
                }
                cout << "--------------------------------------\n";

                //Sorted
                cout << "Input order: Sorted\n";

                // GenerateData(A1, n, 1);
                copyArray(A1, A2, n);

                runTime = measureSortingTime(algorithm, A2, n, countCmp);

                //Result
                if (parameter == "-time" || parameter == "-both") {
                    cout << "Running time : " << runTime << "ms\n";
                }
                if (parameter == "-comp" || parameter == "-both") {
                    cout << "Comparisons : " << countCmp << "\n";
                }
                cout << "--------------------------------------\n";

                //Reversed
                cout << "Input order: Reversed\n";


                // GenerateData(A1, n, 2);
                copyArray(A1, A2, n);

                runTime = measureSortingTime(algorithm, A2, n, countCmp);

                //Result
                if (parameter == "-time" || parameter == "-both") {
                    cout << "Running time : " << runTime << "ms\n";
                }
                if (parameter == "-comp" || parameter == "-both") {
                    cout << "Comparisons : " << countCmp << "\n";
                }
                cout << "--------------------------------------\n";
                delete[]A1;
                delete[]A2;
            }
            else {                        //Command 1
                int n;
                int* A1 = nullptr;

                string input = argv[3];
                string parameter = argv[4];
                const string fileName = input;

                readArrayfromFile(fileName, n, A1);

                int* A2 = new int[n];
                copyArray(A1, A2, n);

                cout << "Input file: " << input << "\n";
                cout << "Input size: " << n << "\n";
                cout << "--------------------------------------\n";

                runTime = measureSortingTime(algorithm, A2, n, countCmp);

                //Result
                if (parameter == "-time" || parameter == "-both") {
                    cout << "Running time : " << runTime << "ms\n";
                }
                if (parameter == "-comp" || parameter == "-both") {
                    cout << "Comparisons : " << countCmp << "\n";
                }
            }
        }
        if (argc == 6) {            //Command 2
            string size = argv[3];
            string order = argv[4];
            string parameter = argv[5];
            int n = stoi(argv[3]);
            int* A1 = new int[n];
            int* A2 = new int[n];
            cout << "Input size: " << size << "\n";
            cout << "Input order: " << order << "\n";
            cout << "--------------------------------------\n";
            if (order == "-rand") {
                GenerateData(A1, n, 0);
                copyArray(A1, A2, n);
            }
            else if (order == "-nsorted") {
                GenerateData(A1, n, 3);
                copyArray(A1, A2, n);
            }
            else if (order == "-sorted") {
                GenerateData(A1, n, 1);
                copyArray(A1, A2, n);
            }
            else if (order == "-rev") {
                GenerateData(A1, n, 2);
                copyArray(A1, A2, n);
            }

            runTime = measureSortingTime(algorithm, A2, n, countCmp);

            //Result
            if (parameter == "-time" || parameter == "-both") {
                cout << "Running time : " << runTime << "ms\n";
            }
            if (parameter == "-comp" || parameter == "-both") {
                cout << "Comparisons : " << countCmp << "\n";
            }
            delete[]A1;
            delete[]A2;

        }
    }
    if (mode == "-c") {
        string algorithm1 = argv[2];
        string algorithm2 = argv[3];
        cout << "COMPARE MODE\n";
        cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << "\n";
        if (argc == 5) {            //Command 4
            double runTime1;
            double runTime2;

            long long countCmp1;
            long long countCmp2;
            int n;
            int* A1 = nullptr;

            string algorithm;
            string input = argv[4];
            const string fileName = input;

            readArrayfromFile(fileName, n, A1);

            int* A2 = new int[n];
            int* A3 = new int[n];

            cout << "Input file: " << input << "\n";
            cout << "Input size: " << n << "\n";
            cout << "--------------------------------------\n";

            //Lan 1

            runTime1 = measureSortingTime(algorithm1, A2, n, countCmp1);

            //Lan 2

            runTime2 = measureSortingTime(algorithm2, A2, n, countCmp2);

            //Result
            cout << "Running time : " << runTime1 << "ms" << " | " << runTime2 << "ms\n";
            cout << "Comparisons : " << countCmp1 << " | " << countCmp2 << "\n";

            delete[]A1;
            delete[]A2;
            delete[]A3;
        }
        if (argc == 6) {            //Command 5
            string size = argv[4];
            string order = argv[5];
            string algorithm;

            int n = stoi(argv[4]);
            int* A1 = new int[n];
            int* A2 = new int[n];
            int* A3 = new int[n];
            long long countCmp1;
            long long countCmp2;

            double runTime1;
            double runTime2;

            cout << "Input size: " << size << "\n";
            cout << "Input order: " << order << "\n";
            cout << "--------------------------------------\n";

            if (order == "-rand") {
                GenerateData(A1, n, 0);
                copyArray(A1, A2, n);
                copyArray(A1, A3, n);
            }
            else if (order == "-nsorted") {
                GenerateData(A1, n, 3);
                copyArray(A1, A2, n);
                copyArray(A1, A3, n);
            }
            else if (order == "-sorted") {
                GenerateData(A1, n, 1);
                copyArray(A1, A2, n);
                copyArray(A1, A3, n);
            }
            else if (order == "-rev") {
                GenerateData(A1, n, 2);
                copyArray(A1, A2, n);
                copyArray(A1, A3, n);
            }

            //Lan 1
            runTime1 = measureSortingTime(algorithm1, A2, n, countCmp1);

            //Lan 2
            runTime2 = measureSortingTime(algorithm2, A2, n, countCmp2);

            //Result
            cout << "Running time : " << runTime1 << "ms" << " | " << runTime2 << "ms\n";
            cout << "Comparisons : " << countCmp1 << " | " << countCmp2 << "\n";

            delete[]A1;
            delete[]A2;
            delete[]A3;

        }
    }
}
