#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<vector<ll>> dp;
int MOD = 100000007;

int main(){
    int n; cin >> n;
    dp.resize(n,vector<ll>(4,1)); 
    //idx = 0 stores no. of all possible matrix end with 00
    //idx = 1 stores no. of all possible matrix end with 10
    //idx = 2 stores no. of all possible matrix end with 01
    //idx = 3 -> total (which is dp[i][0] + dp[i][1] + dp[i][2])
    dp[0][3] = 3;
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][3]%MOD ; // to extend with 00: we can extend every thing
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD; // to extend with 10: we can extend only with idx = 0 and idx = 2
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%MOD; // to extend with 01: we can extend only with idx = 0 and idx = 1
        dp[i][3] = (dp[i][0] + dp[i][1] + dp[i][2])%MOD;
    }
    cout << dp[n-1][3];
    return 0;
}