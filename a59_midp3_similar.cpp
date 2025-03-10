#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool similar(string &a, string &b) {
    if (a==b) return true;
    if (a.size() == 1) {
        if (a==b) return true;
        return false;
    }
    int mid = (a.size()) >> 1;
    string fa = a.substr(0,mid);
    string sa = a.substr(mid,a.size() - mid);
    string sb = b.substr(mid,b.size() - mid);
    string fb = b.substr(0,mid);
    //cout << fa << " " << sa << " " << sb << " "<< fb << " ";
    bool i = similar(fa,fb);
    bool j = similar(sa,sb);
    //cout << i << j;
    if (i&&j) return true;
    bool k = similar(fa,sb);
    bool m =  similar(sa,fb);
    //cout << k << m;
    if (k&&m) return true;
    return false;
}

int main() {
    string a,b;
    cin >> a; cin >> b;
    if (similar(a,b)) cout << "YES";
    else cout << "NO";
}
