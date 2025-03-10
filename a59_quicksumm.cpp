#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<vector<int>> mat;

int calculate(int r, int c) {
    if (r < 0 || c < 0) return 0;
    else return mat[r][c];
} 

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    mat.resize(n,vector<int>(m,0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int a; cin >> a;
            if (i == 0) {
                if (j == 0) mat[i][j] = a;
                else mat[i][j] = mat[i][j-1] + a;
            } else {
                if (j == 0) mat[i][j] = mat[i-1][j] + a;
                else mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + a;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << calculate(r2,c2) - calculate(r1-1,c2) - calculate(r2,c1-1) + calculate(r1-1,c1-1);
        cout << "\n";
    }
}