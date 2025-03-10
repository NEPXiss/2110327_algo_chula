#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool virus_check(vector<int> &virus, int start, int stop, int left_right) {
    // left_right = -1 means initial, = 0 means on the left, = 1 means on the right.
    if (stop - start == 1 ) {
        if (left_right == 0) {
            // when reduced to 2 bits
            // we check 2 cases for left - since it is possible that left may be inverted.
            if (virus[start] == 0 && virus[stop] == 1) return true;
            if (virus[start] == 1 && virus[stop] == 0) return true;
            return false;
        } else {
            // when reduced to 2 bits
            // we check one case for right - for 2 bits, right is guaranteed not to be inverted.
            if (virus[start] == 0 && virus[stop] == 1) return true;
            return false;
        }
    } else {
        int m = (start + stop) >> 1;
        bool left = virus_check(virus, start, m, 0);
        bool right = virus_check(virus, m + 1, stop, 1);
        if (!left && right) {
            // it might be possible that left might be inverted.
            vector<int> tmp;
            for (int x = m; x >= start; x--) {
                tmp.push_back(virus[x]);
            }
            left = virus_check(tmp,0,tmp.size() - 1,-1); //initial check
        }
        return left && right;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int p = (int)pow(2,k);
        vector<int> virus(p);
        for (int i = 0; i < p; i++) cin >> virus[i];
        if (k == 1) {
            if (virus[0] == 0 && virus[1] == 1) cout << "yes\n";
            else cout << "no\n";
        } else {
            if (virus_check(virus,0,p-1,-1)) cout << "yes\n";
            else cout << "no\n";
        }
    }
}
