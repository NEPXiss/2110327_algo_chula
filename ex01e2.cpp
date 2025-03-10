#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int> accsum;

int get_sum(vector<int> &accsum, int a, int b) {
    int tmp = (a - 1 >= 0) ? accsum[a - 1] : accsum[0];
    return accsum[b] - tmp;
}

int mcs(vector<int> &v, vector<int> &accsum, int start, int stop) {
    if (start == stop) return v[start];
    // get the maxsum in the left and the right parts (that does not intersect):
    int m = (start + stop) >> 1;
    int sl = mcs(v,accsum,start,m); 
    int sr = mcs(v,accsum,m+1,stop);
    //crossing the middle (don't forget that index in accsum should be + 1)
    int ml = get_sum(accsum, start + 1, m + 1);
    for (int i = start; i <= m; i++) {
        ml = max(get_sum(accsum,i + 1,m + 1),ml);
    }
    int mr = get_sum(accsum, m+1 + 1,stop + 1);
    for (int j = m+1; j <= stop; j++) {
        mr = max(get_sum(accsum,m+1 + 1,j + 1),mr);
    }
    int sm = ml + mr;
    return max(max(sl,sr),sm);
}

int main() {
    int n; cin >> n; v.resize(n); accsum.resize(n+1);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        accsum[i+1] = accsum[i] + v[i];
    }
    cout << mcs(v,accsum,0,n-1);
}