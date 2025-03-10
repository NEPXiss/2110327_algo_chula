#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int> sum;

int get_sum(vector<int> &sum, int a, int b) {
    int tmp = (a-1 >= 0) ? sum[a-1] : sum[0];
    return sum[b] - tmp;
}

int mcs(vector<int> &v, vector<int> &sum, int start, int stop) {
    if (start == stop) return v[start];
    int m = (start + stop) >> 1;
    int sl = mcs(v,sum,start,m);
    int sr = mcs(v,sum,m+1,stop);
    
    int ml = get_sum(sum, start + 1, m + 1);
    for (int i = start; i <= m; i++){
        ml = max(ml, get_sum(sum, i + 1,m + 1));
    }

    int mr = get_sum(sum, m + 1 + 1, m + 1 + 1);
    for (int i = m + 1; i <= stop; i++){
        mr = max(mr, get_sum(sum, m + 1 + 1,i + 1));
    }

    int sm = ml + mr;
    return max(max(sl,sr), sm);
}

int wrap_around(vector<int> &v, vector<int> &sum, int n) {
    int min_sum = v[0];
    int current_min = v[0];
    for (int i = 1; i < n; i++) {
        current_min = min(current_min + v[i], v[i]);
        min_sum = min(min_sum, current_min);
    }
    return sum[n+1] - min_sum;
}

int main() {
    int n; cin >> n;
    v.resize(n); sum.resize(n+1);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sum[i+1] = sum[i] + v[i];
    }
    cout << max(mcs(v,sum,0,n-1),wrap_around(v,sum,n-1));
}