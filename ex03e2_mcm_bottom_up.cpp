#include <iostream>
#include <vector>
using namespace std;
vector<int> matrix;
vector<vector<int>> dp;

int main() {
    int n; cin >> n;
    matrix.resize(n+1);
    dp.resize(n,vector<int>(n,0));
    for (int i = 0; i < n+1; i++) cin >> matrix[i];
    for (int l = 1; l < n; l++) {
    
    }


}