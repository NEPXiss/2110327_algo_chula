#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp;
vector<int> coin;

int main(){
    int n,b;
    cin >> n >> b;
    coin.resize(n+1);
    dp.resize(n+1,vector<int>(b+1,0));
    for (int i = n; i >= 1; i--) cin >> coin[i];
    for (int i = 1; i <= b; i++) {
        if (coin[1] > i) dp[1][i] = 0;
        else dp[1][i] = i;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= b; j++) {
            if (coin[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i][j - coin[i]] + 1, dp[i - 1][j]);
        }
    }
    cout << dp[n][b];
    // for (auto x : dp) {
    //     for (auto y : x) {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}