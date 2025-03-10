#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int max_sum = v[0];
    int current_sum = v[0];
    for (int i = 1; i < n; i++) {
        current_sum = max(current_sum + v[i], v[i]);
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum;
}