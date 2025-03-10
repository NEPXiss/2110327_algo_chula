#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> v;
vector<int> dp;

int B(int n) {
    if (n <= 3) return dp[n-1];
    if (dp[n-1] != INT_MIN) return dp[n-1];
    int a = max(B(n-1),max(B(n-2),B(n-3))) + v[n-1];
    dp[n-1] = a;
    return a;
}

int main(){
    int n; cin >> n;
    v.resize(n);
    dp.resize(n,INT_MIN);
    for (int i = 0; i < n; i++) cin >> v[i];
    dp[0] = v[0];
    if (n >= 2) dp[1] = dp[0]+v[1];
    if (n >= 3) dp[2] = max(dp[1]+v[2],dp[0]+v[2]);
    cout << B(n);
    return 0;
}