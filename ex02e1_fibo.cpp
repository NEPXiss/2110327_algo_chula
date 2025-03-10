#include <iostream>
#include <vector>
using namespace std;
vector<int> fibo;

int main() {
    int n; cin >> n;
    fibo.resize(n+1);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout << fibo[n];
}