#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &arr) {
    for (int i = 0; i < (int)arr.size(); ++i) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

void mergeSort(vector<int> &arr, int left, int right, int& count) {
    if (right - left <= 1) return;

    int mid = left + (right-left) / 2;

    // 分割統治
    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid, right, count);

    // 統合
    vector<int> buf;
    for (int i = left; i < mid; ++i) buf.push_back(arr[i]);
    for (int i = right - 1; i >= mid; --i) buf.push_back(arr[i]);

    // bufとarrのindexが違うことに注意
    int index_left = 0;
    int index_right = (int)buf.size()-1;
    for (int i = left; i < right; ++i) {
        count++;
        if (buf[index_left] <= buf[index_right]) {
            arr[i] = buf[index_left++];
            continue;
        }
        arr[i] = buf[index_right--];
    }

}

int main(void) {
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    int count = 0;
    mergeSort(arr, 0, N, count);
    printVector(arr);
    cout << count << endl;

    return 0;
}