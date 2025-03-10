#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;
vector<ll> v;
int n;

void MCS(int a, int b, int& gidx1, int& gidx2, ll& sum){
    if (a >= b || b >= n || a < 0) return;
    ll current_sum = v[a];
    ll mcs1 = v[a];
    int idx1 = a;
    int idx2 = a;
    int global_idx1 = a;
    int global_idx2 = a;
    for(int i = a + 1; i <= b; i++) { 
        if (current_sum + v[i] > v[i]) {
            idx2++;
            current_sum += v[i];
            if (mcs1 <= current_sum) {
                mcs1 = current_sum;
                global_idx1 = idx1;
                global_idx2 = idx2;
            }
        } else {
            idx1 = i;
            idx2 = idx1;
            current_sum = v[i];
            if (mcs1 <= current_sum) {
                mcs1 = current_sum;
                global_idx1 = idx1;
                global_idx2 = idx2;
            }
        }
    }
    gidx1 = global_idx1;
    gidx2 = global_idx2;
    sum = mcs1;
}

int main(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll sum1 = INT_MIN;
    int gidx1 = 0;
    int gidx2 = 0;
    MCS(0,n-1,gidx1,gidx2,sum1);
    ll sum2 = INT_MIN;
    int p1,p2,q1,q2;
    ll sum3 = INT_MIN;
    MCS(0,gidx1 - 1,p1,p2,sum2);
    MCS(gidx2 + 1,n - 1,q1,q2,sum3);
    if (sum2 <= 0) sum2 = 0;
    if (sum3 <= 0) sum3 = 0;
    // cout << "DEBUG: \n";
    // cout << gidx1 << " " << gidx2 << "\n";
    // cout << p1 << " " << p2 << " " << q1 << " " << q2 << " \n";
    // cout << (sum2 > sum3 ? "sum2\n":"sum3\n");
    // cout << sum2 << "\n" << sum3 << " \n";
    cout << sum1 + max(sum2,sum3);
    return 0;
}
