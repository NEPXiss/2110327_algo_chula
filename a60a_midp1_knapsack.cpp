#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> v;
vector<int> w;
vector<vector<int>> knapsack;

int main() {
    cin >> n >> m;
    v.resize(n);
    w.resize(n);
    knapsack.resize(n+1);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n+1; i++) {
        for (int j = 0; j < m+1; j++) {
            int a; cin >> a;
            knapsack[i].push_back(a);
        }
    }
    int row = n; int col = m; 
    vector<int> ans;
    while (row != 0) {
        if (knapsack[row-1][col] != knapsack[row][col]) {
            ans.push_back(row);
            col -= w[row-1]; // trace back column
        }
        row--; // trace back row
    }
    cout << ans.size() << "\n";
    for (auto &x : ans) cout << x << " ";
}