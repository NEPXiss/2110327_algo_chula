#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<pair<int,int>> num(N); // stores pair (value, duplicate)
    map<int,int> order;
    /*
    // store relationship: {index : value} 
    e.g. {0:4,7:3} means the index[0:6] contains value 4, and the rest contains value 3.
    */
    int i = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        num[i] = make_pair(a,b);
    }
    sort(num.begin(), num.end());
    int current = num[0].first;
    order[0] = current;
    for (auto &x : num) {
        if (current != x.first) {
            order[i+1] = x.first;
            i+=x.second;
        } else i+=x.second;
    }
    for (int i = 0; i < Q; i++) {
        int c;
        cin >> c;
        auto it = order.upper_bound(c);
        it--;
        cout << it->second << "\n";
    }
}