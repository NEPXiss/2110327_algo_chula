#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> integers;
int N, M;

int main() {
    cin >> N >> M;
    integers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> integers[i];
    }
    sort(integers.begin(), integers.end());

    for (int i = 0; i < M; i++){
        int k; cin >> k;
        // divide our problem into 'pair-sum' problem
        bool exist = false;
        for (int j = 0; j < N - 1; j++) {
            // we will fix the j-th number and iterate all pair-sum after j-th.
            int a = j + 1;
            int b = N - 1;
            while (a < b) {
                if (k == integers[j] + integers[a] + integers[b]) {
                    exist = true;
                    cout << "YES\n";
                    break;
                } else {
                    if (k > integers[j] + integers[a] + integers[b]) a++; //sum is too small
                    else b--; // sum if too big
                }
            }
            if (exist) break;
        }
        if (!exist) cout << "NO\n";
    }

}