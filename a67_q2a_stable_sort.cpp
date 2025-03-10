#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> sorted;
unordered_map<int,vector<int>> ux;
int n,m;

int main(){
    cin >> n >> m;
    a.resize(n);
    sorted.resize(n);
    vector<int> x;
    x.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted.begin(),sorted.end());
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            cin >> x[j];
            ux[a[x[j] - 1]].push_back(x[j]);
        }

        bool sy = true;
        bool stable = true;

        for(int k = 0; k < n; k++){
            if(a[x[k] - 1] != sorted[k]) {
                sy = false;
                break;
            }
            if (ux[sorted[k]].size() == 1) continue;
            else {
                int mx = ux[sorted[k]][0];
                for(int q = 1; q < ux[sorted[k]].size(); q++){
                    if (!((ux[sorted[k]][q] > max(mx,ux[sorted[k]][q-1])))) {
                        stable = false;
                        break;
                    } else {
                        mx = ux[sorted[k]][q];
                    }
                }
            }
        }

        if(!sy) stable = 0;

        if (sy) cout << 1 << " ";
        else cout << 0 << " ";

        if (stable) cout << 1 << "\n";
        else cout << 0 << "\n";

        x.clear();
        ux.clear();
    }
    return 0;
}