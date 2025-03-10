#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // idea from hall-of-frame -> use binary search
    int N, A;
    cin >> N >> A;
    vector<int> tables(N);
    for (int i = 0; i < N; i++) {
        cin >> tables[i];
    }
    for (int i = 0; i < A; i++) {
        long long k;
        long long L = 0;
        long long R = 1e16;

        cin >> k;

        while(L < R) {
            long long M = (L + R)/2; //middle
            long long x = N;

            // at any time = M, how many people have been served
            for (int i = 0; i < N; i++) {
                x += M/tables[i];
            }

            if (x >= k) {
                // that is if x >= k (at time = j, more than k tasks have been achieved) 
                // so we must lower our search down - lower upper bound
                R = M;
            } else {
                // increase search lower bound
                L = M + 1;
            }
        }
        cout << R << "\n";
    }
}