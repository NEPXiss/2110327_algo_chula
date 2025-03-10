#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int> &v, const vector<int> &u) {
    vector<int> tmp(4);
    tmp[0] = v[0]*u[0] + v[1]*u[2];
    tmp[1] = v[0]*u[1] + v[1]*u[3];
    tmp[2] = v[2]*u[0] + v[3]*u[2];
    tmp[3] = v[2]*u[1] + v[3]*u[3];
    return tmp;
}

vector<int> mod(vector<int> &v, int n, int k) {
    if (n == 1) {
        for(auto &x : v) x = x%k;
        return v;
    } else {
        if (n%2 == 0) {
            vector<int> tmp = mod(v,n/2,k);
            tmp = multiply(tmp, tmp);
            // Recursion, M^n has already reduced n to 1;
            return mod(tmp, 1, k);
        } else {
            vector<int> tmp = mod(v,n/2,k);
            tmp = multiply(tmp, tmp);
            vector<int> m = mod(v,1,k);
            tmp = multiply(tmp, m);
            // Recursion, M^n has already reduced n to 1;
            return mod(tmp, 1, k);
        }
    }
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v(4);
    for(int i = 0; i < 4; i++) {
        cin >> v[i];
    }
    v = mod(v,n,k);
    for(auto &x : v) cout << x << " ";
}