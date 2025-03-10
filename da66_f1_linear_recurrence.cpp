#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
vector<int> C;
vector<int> A;

int recur(int n, int k) {
    if (dp[n] != -1) return dp[n];
    if (n < k) return A[n];
    int p = 0;
    for (int i = 0; i < k; i++) {
        p += (C[i]*recur(n-1-i,k))%32717;
        p %= 32717;
    }
    dp[n] = p;
    return p;
}

int main() {
    int k,n;
    cin >> k >> n;
    C.resize(k); A.resize(k);
    dp.resize(n+1,-1);
    for (int i = 0; i < k; i++) cin >> C[i];
    for (int i = 0; i < k; i++) cin >> A[i];
    cout << recur(n,k);
    return 0;
}