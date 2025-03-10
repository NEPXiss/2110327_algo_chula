#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> mat;
vector<vector<int>> dp;

int recur(int n, int m) {
    if (n < 0 || m < 0) return 0;
    if (n == 0 && m == 0) return mat[n][m];
    if (dp[n][m] != -1) return dp[n][m];
    int up = recur(n-1,m) + (n - 1 < 0 ? 0 : mat[n][m]);
    int left = recur(n,m-1) + (m - 1 < 0 ? 0 : mat[n][m]);
    int dia = recur(n-1,m-1) + 2*(n - 1 < 0 || m - 1 < 0 ? 0 : mat[n][m]);    
    dp[n][m] = max(up,max(left,dia));
    return dp[n][m];
}

int main(){
    int n,m; cin >> n >> m;
    mat.resize(n,vector<int>(m,0));
    dp.resize(n,vector<int>(m,-1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> mat[i][j];
    }
    cout << recur(n-1,m-1);
    return 0;
}