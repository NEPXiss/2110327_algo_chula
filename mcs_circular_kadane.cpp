#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int n; cin >> n; int c = 0;
    v.resize(n);
    int max_element;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        c += v[i];
        if (i == 0) max_element = v[0];
        else max_element = max(max_element,v[i]);
    }
    int max_min = v[0]; int current_min = v[0];
    for (int j = 1; j < n; j++) {
        current_min = min(current_min + v[j], v[j]);
        max_min = min(max_min, current_min);
    }
    if (max_element < 0) cout << max_element;
    else cout << c - max_min;
}