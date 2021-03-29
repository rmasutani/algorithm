#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    // Base cases
    if (b == 0) return a;

    return gcd(b, a%b);
} 

int multiple_gcd(int a, int arr[]) {
    
}


int main() {
    int N;
    cin >> N;
    vector<int> T;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        T.push_back(t);
    }


    return 0;
}