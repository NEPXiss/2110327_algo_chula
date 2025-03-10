#include <iostream>
#include <vector>
using namespace std;
vector<int> L;
vector<int> R;
vector<int> dp1;
vector<int> dp2;
int n,w,k;

int F(int kilometer, int direction){
    if (kilometer <= 0) return 0;
    if (direction == 0 && dp1[kilometer] != -1) return dp1[kilometer];
    if (direction == 1 && dp2[kilometer] != -1) return dp2[kilometer];
    int choose = F(kilometer - w - 1, (direction == 0 ? 1:0)) + (direction == 0 ? L[kilometer]:R[kilometer]);
    int skip = F(kilometer - 1, (direction == 0 ? 0:1));
    int sol = max(choose,skip);
    if (direction == 0) dp1[kilometer] = sol;
    if (direction == 1) dp2[kilometer] = sol;
    return sol;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> w >> k;
    L.resize(n+1);
    R.resize(n+1);
    dp1.resize(n+1,-1);
    dp2.resize(n+1,-1);
    for(int i = 1; i <= n; i++) cin >> L[i];
    for(int i = 1; i <= n; i++) cin >> R[i];
    cout << max(F(n,0),F(n,1));
    return 0;
}