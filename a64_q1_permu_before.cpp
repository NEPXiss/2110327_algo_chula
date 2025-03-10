#include <iostream>
#include <vector>
#include <map>

using namespace std;

void perm(vector<int> &sol, vector<bool> &used , vector<vector<int>> &constraint, int len, int n) {
    // don't forget pass by reference for optimization.
    if (len < n) {
        for (int i = 0; i < n; i++) {
            if (used[i]) continue; // if i already chosen, we skip it
            for(auto x : constraint[i]) {
                if (used[x]) return; // if contradict our constraint we terminate
            }
            sol.push_back(i);
            used[i] = true;
            perm(sol, used, constraint, len + 1, n);
            used[i] = false;
            sol.pop_back();
        }
    } else {
        for (auto x : sol) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> sol;
    // b is unique
    vector<vector<int>> constraint(n);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        constraint[a].push_back(b);
    }
    vector<bool> used(n);
    perm(sol, used, constraint, 0, n);
}