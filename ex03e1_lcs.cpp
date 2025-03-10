#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> dp;
string a,b;

int LCS(int idx1, int idx2){
    if (idx1 < 0 || idx2 < 0) return 0;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if (a[idx1] == b[idx2]) {
        int q = LCS(idx1-1,idx2-1) + 1;
        dp[idx1][idx2] = q;
        return q;
    } else {
        int p = max(LCS(idx1,idx2-1), LCS(idx1-1,idx2));
        dp[idx1][idx2] = p;
        return p;
    }
}

int main(){
    cin >> a >> b;
    int k = a.size();
    int g = b.size();
    dp.resize(a.size(),vector<int>(b.size(),-1));
    cout << LCS(k - 1, g - 1) << endl;
    return 0;
}