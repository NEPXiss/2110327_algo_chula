#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> matrix;
vector<vector<int>> dp;

int mcm(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) {
        dp[l][r] = 0;
        return 0;
    }
    int minimum_cost = INT_MAX;
    for (int i = l; i < r; i++) {
        int a = mcm(l,i) + mcm(i+1,r) + matrix[l]*matrix[i+1]*matrix[r+1];
        minimum_cost = min(minimum_cost,a);
    }
    dp[l][r] = minimum_cost;
    return minimum_cost;
}

int main() {
    int n; cin >> n;
    matrix.resize(n+1);
    dp.resize(n,vector<int>(n,-1));
    for(int i = 0; i < matrix.size(); i++) cin >> matrix[i];
    cout << mcm(0,n-1); //there are n matrices --> index from 0 to n-1
}