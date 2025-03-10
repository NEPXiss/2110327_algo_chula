#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> v;
vector<int> s;

int acc(int l, int r) {
    if (l == 0) return s[r];
    else return s[r] - s[l-1];
}

int des(int start, int stop) {
    if (start == stop) return v[start];
    int mid = (start + stop) >> 1;
    int ml = des(start, mid);
    int mr = des(mid+1,stop);

    unordered_map<int,int> um;
    for(int i = start; i <= mid; i++) {
        if (um.find(v[i]) != um.end()) {
            um[v[i]] = max(acc(i,mid), um[v[i]]);
        } else {
            um[v[i]] = acc(i,mid);
        }
    }
    int sr = -852551458;
    for(int i = mid+1; i <= stop; i++) {
        if (um.find(v[i]) != um.end()) {
            sr = max(um[v[i]] + acc(mid+1,i), sr);
        }
    }
    // cout << "check from " << start << " to " << stop <<"\n";
    // cout << "return : " << max(max(ml,mr),sr) << "\n";
    return max(max(ml,mr),sr);
}


int main() {
    int n; cin >> n;
    v.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i==0) s[i] = v[i];
        else s[i] = s[i-1] + v[i];
    }
    cout << des(0,n-1);
}
