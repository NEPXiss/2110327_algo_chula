#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

void perm(int n, vector<string> &sol, vector<pair<string, int>> &available_char, int len, set<string> &s){
    if (len < n) {
        for (auto &x : available_char) {
            if (x.second != 0) {
                x.second--;
                sol.push_back(x.first);
                perm(n, sol, available_char, len+1, s);
                sol.pop_back();
                x.second++;
            }
        }
    } else {
        string temp = "";
        for (auto x : sol) temp += x;
        s.insert(temp);
    }
}

int main() {
    set<string> s;
    vector<pair<string, int>> vec;
    vector<string> sol;
    vec.push_back({"A",0});
    vec.push_back({"B",0});
    vec.push_back({"C",0});
    int a,b,c,n;
    cin >> n >> a >> b >> c;
    vec[0].second = a;
    vec[1].second = b;
    vec[2].second = c;
    if (a + b + c == 0 || a + b + c < n) {
        cout << 0;
    } else {
        perm(n,sol,vec,0,s);
        cout << s.size() << endl;
        for(auto x : s) {
            cout << x << endl;
        }
    }
}