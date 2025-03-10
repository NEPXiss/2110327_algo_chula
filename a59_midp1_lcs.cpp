#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>> dp;
string a,b;

int main(){
    int n,m;
    cin >> n >> m;
    cin >> a;
    cin >> b;
    dp.resize(n+1,vector<int>(m+1,0));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cin >> dp[i][j];
        }
    }
    string ans = "";
    int idx1 = n;
    int idx2 = m;
    while(idx1 > 0 && idx2 > 0){
        if (dp[idx1 - 1][idx2 - 1] + 1 == dp[idx1][idx2]) {
            ans = a[idx1 - 1] + ans;
            idx1--;
            idx2--;
        } else if (dp[idx1 - 1][idx2] == dp[idx1][idx2]) idx1--;
        else if (dp[idx1][idx2 - 1] == dp[idx1][idx2]) idx2--;
    }
    cout << ans;
    return 0;
}