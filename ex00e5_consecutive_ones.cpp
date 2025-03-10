#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void gen_barcode(int n, int k, vector<string> bits, int len, string sol, string ones, set<string> &s) {
    if (len < n) {
        for (auto x : bits) {
            sol += x;
            gen_barcode(n,k,bits,len+1,sol,ones,s);
            sol.pop_back();
        }
    } else {
        if (k == 0) {
            if (sol.find("1") != -1) return;
            else s.insert(sol);
        } else {
            if (sol.find(ones) != -1) {
                s.insert(sol);
            } else {return;}
        }
    }
}

int main() {
    vector<string> bits = {"0", "1"};
    int n,k;
    cin >> n >> k;
    string ones(k, '1'); //string ones = "111111...1";
    set<string> s;
    string sol = "";
    gen_barcode(n,k,bits,0,sol,ones,s);
    if (s.size() == 0) {}
    else {
        for (auto x : s) cout << x << endl;
    }
}