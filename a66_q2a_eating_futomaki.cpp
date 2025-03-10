#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<vector<int>> dp;

int recur(int left, int right){
    if (left > right) return 0;
    if (dp[left][right] != -1) return dp[left][right];
    dp[left][right] = max(dp[left][right], recur(left,right - 2) + max(v[right],v[right - 1]));
    dp[left][right] = max(dp[left][right], recur(left + 2,right) + max(v[left],v[left + 1]));
    dp[left][right] = max(dp[left][right], recur(left + 1, right - 1) + max(v[right],v[left]));
    return dp[left][right];
}

int main(){
    int n; cin >> n;
    v.resize(n+1);
    dp.resize(n+1,vector<int>(n+1,-1));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) cin >> v[i];
    cout << recur(1,n);
    return 0;
}