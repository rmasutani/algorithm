#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int N) {
    for (int i = 0; i < N; ++i) {
        if (arr[i]) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

void insertionSort(int arr[], int N) {
    for (int i = 0; i < N; ++i) {
        int tmp = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > tmp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
        printArray(arr, N);
    }
}

int main() {
    int N; cin >> N;
    int arr[N];
    for (int i = 0; i < N; ++i) cin >> arr[i];

    insertionSort(arr, N);
    
    return 0;
}