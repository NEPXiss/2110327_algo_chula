#include <iostream>
#include <vector>

using namespace std;

void perm(int n, vector<int> &sol, int len, vector<bool> &used) {
    if (len < n) {
        for (int i = 1; i <= n; i++) {
            if (used[i] == false) {
                used[i] == true;
                sol[len] = i;
                perm(n, sol, len+1, used);
                used[i] = false;
            }
        }
    } else {
        for (auto &x : sol) cout << x;
        cout << endl;
    }
}

int main() {

}