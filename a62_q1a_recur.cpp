#include <iostream>
#include <vector>
using namespace std;
int a,b;

void recur(vector<vector<int>> &v, int a, int b,int top,int bottom,int left,int right) {
    if (a == 0) {
        //handle edge case
        v[top][left] = b;
        return;
    }
    if (a == 1) {
        v[top][left] = b;
        v[top][right] = b - 1;
        v[bottom][left] = b + 1;
        v[bottom][right] = b;
        return;
    }
    int mr = (top + bottom) >> 1;
    int mc = (right + left) >> 1;
    recur(v,a-1,b,top,mr,left,mc);
    recur(v,a-1,b-1,top,mr,mc+1,right);
    recur(v,a-1,b+1,mr+1,bottom,left,mc);
    recur(v,a-1,b,mr+1,bottom,mc+1,right);
}

int main() {
    cin >> a >> b;
    int n = 1 << a;
    vector<vector<int>> v(n, vector<int>(n,0));
    recur(v, a, b, 0, n-1, 0, n-1);
    for(auto &x : v) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}