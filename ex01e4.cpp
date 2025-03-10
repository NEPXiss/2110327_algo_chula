#include <iostream>
#include <vector>
using namespace std;

int mod(int x, int n, int k) {
    if (n == 1) {
        return x%k;
    } else {
        if (n%2 == 0) {
            int tmp = mod(x,n/2,k);
            return (tmp * tmp)%k;
        } else {
            int tmp = mod(x,n/2,k);
            int a = x%k;
            tmp = (tmp*tmp);
            int q = mod(tmp,1,k);
            return (q*a)%k;
        }
    }
}

int main() {
    int x,n,k;
    cin >> x >> n >> k;
    cout << mod(x,n,k);
}