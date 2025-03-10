#include <iostream>
#include <vector>
#include <string>

using namespace std;

void gen_barcode(int B, int len, vector<pair<string,int>> bits, string sol) {
    if (len < B) {
        for(auto &x : bits) {
            if (x.second != 0) {
                x.second--;
                sol += x.first;
                gen_barcode(B, len + 1, bits, sol);
                sol.pop_back();
                x.second++;
            }
        }
    } else {
        if (bits[1].second == 0) cout << sol << endl;
    }
}

int main() {
    vector<pair<string,int>> bits;
    bits.push_back(make_pair("0",0));
    bits.push_back(make_pair("1",0));
    int a,b;
    cin >> a >> b;
    bits[0].second = b-a;
    bits[1].second = a;
    string sol = "";
    gen_barcode(b,0,bits,sol);
}