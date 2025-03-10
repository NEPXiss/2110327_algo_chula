#include <iostream>
#include <vector>
using namespace std;
int u,v,w,p;

int getvalue(long long n, long long r, long long c) {
    if (n == 1) {
        if (r == 0 && c == 0) return u;
        if (r == 0 && c == 1) return v;
        if (r == 1 && c == 0) return w;
        if (r == 1 && c == 1) return p;
    }
    long long s = 1LL << (n-1);
    if (r < s && c < s) {
        return getvalue(n-1,r,c);
    } else if (r < s && c >= s) {
        return getvalue(n-1,c - s,r);
    } else if (r >= s && c < s) {
        return -getvalue(n-1,r - s,c);
    } else if (r >= s && c >= s) {
        return -getvalue(n-1, c - s, r - s);
    }
}

int main() {
    int n,m;
    cin >> n >> m; cin >> u >> v >> w >> p;
    for (int i = 0; i < m; i++) {
        long long r,c; cin >> r >> c;
        cout << getvalue(n,r-1,c-1) << "\n";
    }
}