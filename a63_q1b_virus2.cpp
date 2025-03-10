#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool virus_check(vector<int> &virus, int start, int stop){
    if (stop - start == 1) {
        if (virus[start] == 0 && virus[stop] == 0) return true;
        if (virus[start] == 1 && virus[stop] == 0) return true;
        if (virus[start] == 0 && virus[stop] == 1) return true;
        if (virus[start] == 1 && virus[stop] == 1) return true;
    } else {
        int m = (start + stop) >> 1;
        int left = 0; int right = 0;
        for (int i = start; i <= m; i++) if (virus[i] == 1) left++;
        for (int i = m + 1; i <= stop; i++) if (virus[i] == 1) right++;
        if (abs(right - left) > 1) return false;
        else {
            bool v_left = virus_check(virus, start, m);
            bool v_right = virus_check(virus, m + 1, stop);
            return v_left && v_right;
        }
    }
}

int main() {
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a = pow(2,k);
        vector<int> virus(a);
        for (int i = 0; i < a; i++) {
            cin >> virus[i];
        }
        if (virus_check(virus,0,a-1)) cout << "yes\n";
        else cout << "no\n";
    }
}