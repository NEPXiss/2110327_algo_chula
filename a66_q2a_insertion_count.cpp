#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<int,int> map;
unordered_map<int,int> om;
vector<int> w;
int n, m;

int insertion_sort(vector<int> v, int k){
    sort(v.begin() + om[k],v.end());
    int idx = om[k];
    while(v[idx] != k && idx < n) idx++;
    return idx;
}

int main(){
    cin >> n >> m;
    vector<int> v;
    v.resize(n);
    w.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        w[i] = v[i];
        om[v[i]] = i;
    }
    sort(w.begin(),w.end());
    for(int i = 0; i < n; i++) map[w[i]] = i;
    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        int sort_idx = insertion_sort(v,k);
        cout << sort_idx - map[k] << "\n";
    }
    return 0;
}