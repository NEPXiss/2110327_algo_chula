#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp;
vector<vector<int>> num;
int global_max = 0;

int main() {
    int n; cin >> n;
    num.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        num[i].resize(i+1);
        for (int j = 0; j <= i; j++) {
            cin >> num[i][j];
        } 
    }
    dp[0].push_back(num[0][0]);
    global_max = dp[0][0];
    for(int i = 1; i < n; i++) {
        dp[i].resize(i+1);
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + num[i][j];
                if (i == n-1) global_max = max(global_max,dp[i][j]);
            }
            else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + num[i][j];
                if (i == n-1) global_max = max(global_max,dp[i][j]);
            }
            else {
                dp[i][j] = max(dp[i-1][j-1] + num[i][j], dp[i-1][j] + num[i][j]);
                if (i == n-1) global_max = max(global_max,dp[i][j]);
            }
        }
    }
    cout << global_max;
    return 0;
}