#include <iostream>
#include <vector>
using namespace std;

int S(vector<vector<int>> &v, int r1, int c1, int r2, int c2) {
    for (int i = r1; i <= r2; i++) {
        for (int j = c1 ; j <= c2; j++) {
            if (v[i][j] != 0) return 0;
        }
    }
    return 1;
}

int triforce(vector<vector<int>> &v, int r1, int c1, int r2, int c2, int n){
    // cout << "CHECKING n = " << n << endl;
    // cout << "r1 c1 r2 c2 = " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    if (n == 2) {
        if (v[r2][c2] != 0) return 0;
        if (v[r1][c1] == 0 || v[r2][c1] == 0 || v[r1][c2] == 0) return 0;
        if (v[r1][c1] == v[r2][c1]) return v[r1][c1];
        if (v[r1][c1] == v[r1][c2]) return v[r1][c1];
        if (v[r1][c2] == v[r2][c1]) return v[r1][c2];
        if (v[r1][c2] == v[r2][c1] && v[r2][c1] == v[r1][c1]) return v[r1][c2];
        return 0;
    } else {
        int mr = (r1 + r2) >> 1;
        int mc = (c1 + c2) >> 1;
        int p = triforce(v, r1, c1, mr, mc, n/2);
        // cout << "p = " << p << endl;
        if (!p) return 0;
        int q = triforce(v, r1, mc + 1, mr, c2, n/2);
        // cout << "q = " << q << endl;
        if (!q) return 0;
        int r = triforce(v, mr + 1, c1, r2, mc,n/2);
        // cout << "r = " << r << endl;
        if (!r) return 0;
        int s = S(v, mr + 1, mc + 1, r2, c2);
        // cout << "s = " << s << endl;
        if (!s) return 0;
        if (p == q && q == r) return p;
        if (p == q) return p;
        if (p == r) return p;
        if (q == r) return r;
        return 0;
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        int n; cin >> n;
        vector<vector<int>> v(n,vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> v[j][k];
            }
        }
        cout << triforce(v, 0, 0, n-1, n-1, n) << endl;
    }
    return 0;
}