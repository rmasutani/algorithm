#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void binary_search() {
    return;
}


int main() {
    int a[] = {10, 11, 12, 13, 14};

    int left = -1;
    int right = 5;
    int goal = 12;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (a[mid] < goal) left = mid;
        else right = mid;
    }

    cout << "left: " << left << endl;
    cout << "right: " << right << endl;
    return 0;
}
