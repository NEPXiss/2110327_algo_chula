#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n,w;

int main() {
    cin >> n >> w;
    v.resize(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    int count = 1;
    int current_sum = v[0];
    int global_sum = v[0];
    int front_idx = 0;
    for(int i = 1; i < n; i++) {
        if (count == w) {
            // if count == w --> say we are covering idx = p to q. Then we will start new cover from p+1.
            front_idx++;
            current_sum = v[front_idx];
            count = 1;
            i = front_idx;
            global_sum = max(global_sum, current_sum);
        } else {
            if (current_sum + v[i] < v[i]) {
                current_sum = v[i];
                front_idx = i;
                count = 1;
            } else {
                current_sum = current_sum + v[i];
                count++;
            }
            global_sum = max(global_sum,current_sum);
        }
    }
    cout << global_sum;
    return 0;
}