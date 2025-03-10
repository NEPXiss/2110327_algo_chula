#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const int MOD = 100000007;
vector<vector<ll>> dp; 

int main(){
    int n; cin >> n;
    dp.resize(n+1,vector<ll>(5,0));
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 1;
    dp[2][4] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][2])%MOD;
        dp[i][1] = dp[i-1][0]%MOD;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3])%MOD;
        dp[i][3] = (dp[i-1][1] + dp[i-1][3])%MOD;
        dp[i][4] = (dp[i][0] + dp[i][1] + dp[i][2] + dp[i][3])%MOD;
    }
    cout << dp[n][4];
    return 0;
} 

