#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int N) {
    for (int i = 0; i < N; ++i) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

void bubbleSort(int arr[], int N, int &cnt) {
    bool done = false;
    while (!done) {
        done = true;
        for (int i = N-1; i > 0; --i) {
            int tmp = arr[i];
            if (arr[i-1] > arr[i]) {
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
                done = false; 
                cnt++;
            }
        }
    }
}

int main() {
    int N; cin >> N;
    int cnt = 0;
    int arr[100];
    for (int i = 0; i < N; ++i) cin >> arr[i];

    bubbleSort(arr, N, cnt);
    printArray(arr, N);
    cout << cnt << endl;

    return 0;
}