#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const int MOD = 100000007;
vector<ll> dp;

int main(){
    int n,k; cin >> n >> k;
    if (k == 1) {
        cout << (1 << n);
        return 0;
    }
    // k >= 2
    dp.resize(n+1,0);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 3;
    for(int i = 3; i <= n; i++) {
        if (i < k) dp[i] = (dp[i-1] + 1)%MOD; //do not extend with 1 unless it all 0..00 --> so we add 1
        else dp[i] = (dp[i-1] + dp[i-k])%MOD;
    }
    cout << dp[n];
    return 0;
}