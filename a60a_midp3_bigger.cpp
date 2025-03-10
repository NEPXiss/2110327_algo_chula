#include <iostream>
#include <vector>
using namespace std;
vector<int> p;
vector<int> dp;

int F(int idx){
    if (idx <= 0 ) return 0;
    if (dp[idx] != -1) return dp[idx];
    int sol = max(F(idx-1),F(idx-3)+p[idx]);
    dp[idx] = sol;
    return sol;
}

int main(){
    int n;
    cin >> n;
    p.resize(n+1);
    dp.resize(n+1,-1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) cin >> p[i];
    cout << F(n);
    return 0;
}