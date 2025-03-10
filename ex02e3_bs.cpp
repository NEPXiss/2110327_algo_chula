#include <iostream>
#include <vector>

using namespace std;
vector<int> v;

void b_search(int k, vector<int> &v, int start, int stop) {
    int middle = (start + stop) >> 1;
    if (start >= stop) {
        if (v[stop] > k) cout << stop - 1 << "\n";
        else {
            int ans = stop;
            for (int i = stop; i < v.size(); i++) {
                if (v[i] <= k) ans = i;
                else break;
            }
            cout << ans << "\n";
        }
    } else {
        if (v[middle] > k) {
            b_search(k, v, start, middle);
        } else {
            b_search(k, v, middle + 1, stop);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        if (v[0] > k) {cout << -1 << "\n"; continue;}
        if (v[n-1] <= k) {cout << n-1 << "\n"; continue;}
        b_search(k,v,0,n-1);
    }
}