#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000003;
vector<int> s;
vector<int> dp;

int main(){
    int n, k;
    cin >> n >> k;
    s.resize(n);
    for(int i = 0; i < k; i++) cin >> s[i];
    dp.resize(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        int sum = 0;
        for(auto& x:s){
            if (i - x >= 0) sum = (sum + dp[i - x])%MOD;
        }
        dp[i] = sum;
    }
    cout << dp[n];
    return 0;
}