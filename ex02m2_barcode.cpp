#include <iostream>
#include <vector>
using namespace std;
vector<vector<vector<int>>> dp;
int N,M,K;

int recur(int len, int cnt_k, int cnt_m) {
    if (len > N) return (cnt_k == K ? 1 : 0);
    if (dp[len][cnt_k][cnt_m] != -1) return dp[len][cnt_k][cnt_m];
    int sol = 0;
    if (cnt_m < M) {
        sol += recur(len+1,cnt_k,cnt_m+1);
    } 
    if (cnt_k < K) {
        sol += recur(len+1,cnt_k+1,cnt_m);
    }
    dp[len][cnt_k][cnt_m] = sol;
    return sol;
}

int main(){
    cin >> N >> M >> K;
    dp.resize(N+1, vector<vector<int>>(K+1,vector<int>(M+1,-1)));
    cout << recur(2,0,1);
    return 0;
}