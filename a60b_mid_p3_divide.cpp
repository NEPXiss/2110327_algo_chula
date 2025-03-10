#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp;
int MOD = 1997;

int recur(int n, int k){
    if (k == 1) return 1;
    if (n < k) return 0;
    if (dp[n][k] != -1) return dp[n][k];
    int sol = ((recur(n-1,k)*k)%MOD + recur(n-1,k-1)%MOD)%MOD;
    dp[n][k] = sol;
    return sol;
}

int main(){
    int n,k; cin >> n >> k;
    dp.resize(n+1,vector<int>(k+1,-1));
    cout << recur(n,k);
    return 0;
}