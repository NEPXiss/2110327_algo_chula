#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long>> cnk;

int main() {
    int n, k; cin >> n >> k;
    cnk.resize(n+1, vector<long long>(n+1,-1));
    cnk[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        cnk[i][0] = 1; cnk[i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cnk[i][j] = cnk[i-1][j-1] + cnk[i-1][j];
        }
    }
    cout << cnk[n][k];
}