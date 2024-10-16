#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* arr, const int size, const int Low, const int High, int i) {
    if (i < size) {
        arr[i] = Low + rand() % (High - Low + 1);
        Create(arr, size, Low, High, i + 1); 
    }
}

void Print(int* arr, const int size, int i) {
    if (i < size) {
        cout << setw(4) << arr[i];
        Print(arr, size, i + 1); 
    }
    else {
        cout << endl;
    }
}

int Max(int* arr, const int size, int i, int max) {
    if (i < size) {
        if (arr[i] > max) {
            max = arr[i];
        }
        return Max(arr, size, i + 1, max); 
    }
    return max; 
}

int Min(int* arr, const int size, int i, int min) {
    if (i < size) {
        if (arr[i] < min) {
            min = arr[i];
        }
        return Min(arr, size, i + 1, min); 
    }
    return min; 
}

int MaxIndex(int* arr, const int size, int max, int i) {
    if (i >= size) return -1; 
    if (arr[i] == max) return i;
    return MaxIndex(arr, size, max, i + 1);
}

int MinIndex(int* arr, const int size, int min, int i) {
    if (i >= size) return -1;
    if (arr[i] == min) return i; 
    return MinIndex(arr, size, min, i + 1); 
}

void SwapMinMax(int* arr, const int size) {
    int min = Min(arr, size, 1, arr[0]); 
    int max = Max(arr, size, 1, arr[0]); 

    int minIndex = MinIndex(arr, size, min, 0); 
    int maxIndex = MaxIndex(arr, size, max, 0); 

    if (minIndex != maxIndex) {
        int temp = arr[minIndex];
        arr[minIndex] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

int main() {
    srand((unsigned)time(NULL)); 

    const int n = 15;  
    int arr[n];
    int Low = 1;        
    int High = 100;     
   
    Create(arr, n, Low, High, 0);
    Print(arr, n, 0);
    int max = Max(arr, n, 1, arr[0]);
    int min = Min(arr, n, 1, arr[0]);
    cout << "Max element index: " << MaxIndex(arr, n, max, 0) << " (value: " << max << ")" << endl;
    cout << "Min element index: " << MinIndex(arr, n, min, 0) << " (value: " << min << ")" << endl;
    SwapMinMax(arr, n);
    Print(arr, n, 0);

    return 0;
}
