#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    ifstream fin("numbers.txt");
    if (!fin) {
        cout << "Error opening file";
        return 0;
    }

    string line, token;
    getline(fin, line);
    fin.close();

    int count = 1;
    for(char c : line) {
        if(c == ',')
            count++;
    }

    int* arr1 = new int[count];
    int* arr2 = new int[count];
    int n = 0;

    stringstream ss(line);
    while(getline(ss, token, ',')) {
        arr1[n] = stoi(token);
        arr2[n] = arr1[n];
        n++;
    }

    auto start1 = high_resolution_clock::now();
    bubbleSort(arr1, n);
    auto end1 = high_resolution_clock::now();
    auto bubbleTime = duration_cast<milliseconds>(end1 - start1);

    auto start2 = high_resolution_clock::now();
    selectionSort(arr2, n);
    auto end2 = high_resolution_clock::now();
    auto selectionTime = duration_cast<milliseconds>(end2 - start2);

    cout << "Bubble Sort: " << bubbleTime.count() << " milliseconds" << endl;
    cout << "Selection Sort: " << selectionTime.count() << " milliseconds" << endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}
