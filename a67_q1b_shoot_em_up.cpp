#include <bits/stdc++.h>
using namespace std;
int n,w,b;

void recur(int len, int height, string ans){
    if (height < 1 || height > w) return;
    if (len == n) {
        cout << ans << "\n";
        return;
    }
    recur(len + 1, height - 1, ans + 'D');
    recur(len + 1, height, ans + 'S');
    recur(len + 1, height + 1, ans + 'U');
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    cin >> n >> w >> b;
    recur(0,b,"");
}