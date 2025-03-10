#include <iostream>
#include <vector>
#include <climits>
using namespace std;
long long global_max = INT_MIN;
vector<vector<long long>> mat;

int main() {
    int n; cin >> n;
    mat.resize(n,vector<long long>(n,0)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            global_max = max(global_max,mat[i][j]);
        }
    }
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < n; q++) {
            long long max_tmp = mat[0+p][0+q];
            for (int k = 1; (k+p) < n && (k+q) < n; k++) {
                //kadane algorithm
                long long tmp = max_tmp + mat[k+p][k+q];
                max_tmp =  max(tmp, mat[k+p][k+q]);
                global_max = max(global_max,max_tmp);
            }
        }
    }
    cout << global_max;
    return 0;
}