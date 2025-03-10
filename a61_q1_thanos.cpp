#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int p,k,A,B;
vector<int> u;

long long thanos(int start, int stop) {
    long long btw = upper_bound(u.begin(), u.end(), stop) - u.begin() - (lower_bound(u.begin(), u.end(), start) - u.begin());
    if (start == stop) {
        return (btw == 0) ? A : btw*B;
    }
    long long ml,mr,mt;
    int m = (start + stop) >> 1;
    ml = thanos(start,m);
    mr = thanos(m+1,stop);
    mt = (btw == 0) ? A : btw*B*(stop - start + 1);
    return min(ml + mr, mt);
}   

int main() {
    cin >> p >> k >> A >> B;
    long long n = 1 << p;
    u.resize(k);
    for(int i = 0; i < k; i++) {
        int c; cin >> c; 
        c--;
        u[i] = c;
    }
    sort(u.begin(), u.end());
    cout << thanos(0,n-1);
}