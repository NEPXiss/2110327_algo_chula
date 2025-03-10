#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp;
vector<int> check;
vector<int> a;
vector<int> b;
int n,k;

int recur(int i){
    if(i <= 0) return 0;
    if(i == 1) return a[1];
    if(check[i] != 0) return dp[i];
    int sol = recur(i-1) + a[i] - b[1];
    for(int j = 2; j <= k; j++) {
        if (i-j <= 0) break;
        sol = max(sol,recur(i-j) + a[i] - b[j]);
    }
    dp[i] = sol;
    check[i] = 1;
    return sol;
}

int main(){
    cin >> n >> k;
    a.resize(n+1);
    dp.resize(n+1);
    check.resize(n+1,0);
    check[1] = 1;
    dp[1] = a[1];
    b.resize(k+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= k; i++) cin >> b[i];
    cout << recur(n);
    return 0;
}