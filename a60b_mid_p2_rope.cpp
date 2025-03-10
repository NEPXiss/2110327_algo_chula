#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int a,b,c;
vector<int> dp;

int B(int n) {
    if (n < 0) return INT_MIN;
    if (n == 0) return 0;
    if (dp[n-1] != -1) return dp[n-1];
    int ans = max(B(n-a),max(B(n-b),B(n-c))) + 1;
    dp[n-1] = ans;
    return ans;
}

int main(){
    int n; cin >> n >> a >> b >> c;
    dp.resize(n,-1);
    cout << B(n);
    return 0;
}