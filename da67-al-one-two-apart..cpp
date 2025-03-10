#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> dp;
int MOD = 100000007;

int main() {
    int n; cin >> n;
    dp.resize(n+1);
    dp[0] = 0;
    dp[1] = 3;
    dp[2] = 7;
    dp[3] = 15;
    if (n <= 3) cout << dp[n];
    else {
        for(int i = 4; i <= n; i++) {
            dp[i] = (dp[i-1]*2 + dp[i-3])%MOD;
        }
        cout << dp[n];
    }
    return 0;
}