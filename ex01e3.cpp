#include <iostream>
#include <vector>

using namespace std;

void b_search(int k, vector<int> &v, int start, int stop) {
    int middle = (start + stop) >> 1;
    if (start >= stop) {
        if (v[stop] <= k) cout << v[stop] << "\n";
        else cout << v[stop-1] << "\n";
    } else {
        if (v[middle] > k) {
            b_search(k, v, start, middle);
        } else {
            b_search(k, v, middle + 1, stop);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        if (v[0] > k) {
            cout << - 1 << "\n";
            continue;
        }
        if (v[v.size() - 1] < k) {
            cout << v[v.size() - 1] << "\n";
            continue;
        }
        b_search(k,v,0,n-1);
    }
}