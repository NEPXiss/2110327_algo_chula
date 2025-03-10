#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> p;
vector<int> dp;

int main(){
    int n,k; cin >> n >> k;
    p.resize(n+1,0);
    dp.resize(n+1,INT_MAX);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int left = max(1, i - k);
        int right = min(n, i + k);
        int candidate_sol = dp[left - 1] + p[i];
        for (int k = left; k <= right; k++) {
            dp[k] = min(dp[k],candidate_sol);
        }
    }
    cout << dp[n];
    return 0;
}