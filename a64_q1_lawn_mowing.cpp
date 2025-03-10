#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
vector<int> v,sum;

int acc(int l, int r) {
    if (l == 0) return sum[r];
    return sum[r] - sum[l-1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    v.resize(n); sum.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0) sum[i] = v[i];
        else sum[i] = sum[i-1] + v[i];
    }
    for (int i = 0; i < m; i++) {
        int global_max = 0;
        int l,b; cin >> l >> b;
        
        int L = l;
        int R = n-1;
        //cout << "B is : " << b << endl;
        while (L < R) {
            int mid = (L+R)>>1;
            //cout << "current budget: " << (R-l+1)*k << endl;
            if ((R-l+1)*k > b) {
                R = mid;
                //cout << "R : " << R << endl;
            } else {
                L = mid + 1;
                //cout << "L : " << L << endl;
            }
        }

        int u = max(L,R);
        int j = l;
        if (acc(l,u)+(u-l+1)*k <= b) global_max = max(global_max, acc(l,u));
        while(j < u) {
            //cout << "current j = " << j << " current u : " << u << endl;
            int m = (u + j)>>1;
            if (acc(l,j)+(j-l+1)*k <= b) {
                global_max = max(global_max, acc(l,j));
                j = m + 1;
            } else {
                j = (j+l)>>1;
                u = m;
            }
            //cout << "current gm : " << global_max << endl;
        }
        // cout << "F\n";
        // cout << "current j = " << j << " current u : " << u << endl;
        // cout << "acc(l,j) = " << acc(l,j) << "\n";
        // cout << "acc(l,u) = " << acc(l,u) << "\n";

        // here we do - 1 : because in our binary search we let j = m+1, we might skip j = m;
        if (acc(l,j-1)+(j-1-l+1)*k <= b) global_max = max(global_max, acc(l,j-1));
        if (acc(l,u-1)+(u-1-l+1)*k <= b) global_max = max(global_max, acc(l,u-1));
        cout << global_max << "\n";
    }
}