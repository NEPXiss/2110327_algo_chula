#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> c;
vector<int> dp;

int recur(int n) {
    if (n == 0) return c[0];
    if (n == 1) return max(c[0],c[1]);
    if (dp[n] != -1) return dp[n];
    int ans = max(recur(n-1),recur(n-2) + c[n]);
    dp[n] = ans;
    return ans;
}

int main() {
    int n; cin >> n;
    c.resize(n);
    dp.resize(n,-1);
    for(int i = 0; i < n; i++) cin >> c[i];
    dp[0] = c[0];
    dp[1] = max(c[0],c[1]);
    cout << recur(n-1);
    return 0;
}