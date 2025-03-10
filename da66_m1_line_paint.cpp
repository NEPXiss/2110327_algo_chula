#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,int> m;
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        auto it1 = m.upper_bound(a);
        auto it2 = m.upper_bound(b);

        if (m.empty()) {
            m[a] = b;
            continue;
        }
        if (it1 == m.end()) {
            auto ttt = it1; ttt--;
            if (a <= ttt->second) {
                m[ttt->first] = max(ttt->second,b);
                continue;
            }
            if (a - ttt->second == 1) {
                m[ttt->first] = b;
            } else m[a] = b;
            continue;
        }
        if (it2 == m.begin()){
            m[a] = b;
            continue;
        }
        if (it1 == m.begin()){
            it2--;
            while(it1 != it2) {
                auto tmp = it1;
                it1++;
                m.erase(tmp);
            }
            m[a] = max(it2->second,b);
            m.erase(it2);
            continue;
        }
        it1--;
        it2--;
        if (it1 == it2) {
            if (a > it1->second) {
                if (a - it1->second == 1) {
                    auto tt = it1; tt++;
                    if (tt != m.end() && tt->first - b == 1) {
                        m[it1->first] = tt->second;
                        m.erase(tt);
                        continue;
                    }
                    if (tt == m.end()) {
                        m[it1->first] = b;
                        continue;
                    }
                    m[it1->first] = b;
                    continue;
                } else {
                    auto tt = it1; tt++;
                    if (tt != m.end() && tt->first - b == 1) {
                        m[a] = tt->second;
                        m.erase(tt);
                        continue;
                    } 
                    if (tt == m.end()) {
                        m[a] = b;
                        continue;
                    }
                    else m[a] = b;
                    continue;
                }
            } else {
                auto tt = it1; tt++;
                if (tt != m.end() && tt->first - b == 1) {
                    m[it1->first] = tt->second;
                    m.erase(tt);
                    continue;
                } else m[it1->first] = b; 
                continue;
            }
            if (b <= it2->second) m[it1->first] = it1->second;
            else {
                auto tmp2 = it2; tmp2++;
                if (tmp2->first - 1 == b) {
                    m[it1->first] = tmp2->second;
                    m.erase(tmp2);
                } else {
                    m[it1->first] = b;
                }
            }
            continue;
        }
        if (it2->second < b && it1->second >= a){
            m[it1->first] = b;
            it1++;
            while(it1 != it2) {
                auto tmp = it1;
                it1++;
                m.erase(tmp);
            }
            m.erase(it2);
            continue;
        }
        if (it2->second < b && it1->second < a){
            auto check_abs_1 = it1;
            it1++;
            while(it1 != it2) {
                auto tmp = it1;
                it1++;
                m.erase(tmp);
            }
            m.erase(it2);
            if (a - check_abs_1->second == 1) m[check_abs_1->first] = b;
            else m[a] = b;
            continue;
        }
        if (it2->second >= b && it1->second >= a){
            m[it1->first] = it2->second;
            it1++;
            while(it1 != it2) {
                auto tmp = it1;
                it1++;
                m.erase(tmp);
            }
            m.erase(it2);
            continue;
        }
        if (it2->second >= b && it1->second < a){
            auto check_abs_1 = it1;
            it1++;
            while(it1 != it2) {
                auto tmp = it1;
                it1++;
                m.erase(tmp);
            }
            if (a - check_abs_1->second == 1) m[check_abs_1->first] = it2->second;
            else m[a] = it2->second;
            m.erase(it2);
            continue;
        }
    }
    for(auto &x : m) cout << x.first << " " << x.second << " ";
}