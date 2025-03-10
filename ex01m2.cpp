#include <iostream>
#include <vector>

using namespace std;
vector<int> V;
int inversion = 0;

int merge(vector<int> &V, int start, int stop, int m, vector<int> &tmp) {
    // merge count --> assume that both left and right subvectors are already sorted.
    int count = 0;
    int bi = start;
    int ci = m + 1;
    for (int i = start; i <= stop; i++) {
        if (ci > stop) {
            tmp[i] = V[bi++];
            continue;
        }
        if (bi > m) {
            tmp[i] = V[ci++]; 
            continue;
        }
        if (V[bi] <= V[ci]) tmp[i] = V[bi++];
        else {
            tmp[i] = V[ci++];
            //e.g. [1 4 5 | -1 2 3] we say that -1 < 1 -> so -1 must also be lower than the rest of left subarray.
            // next we compare (1,2), then (4,2) -> That means the rest of the left aubarray ([4,5]) must be greater than 2.
            count += m - bi + 1;
        }
    }
    for(int i = start; i <= stop; i++) V[i] = tmp[i];
    return count;
}

void merge_sort(vector<int> &V, int start, int stop, vector<int> &tmp){
    if (start < stop) {
        int m = (start + stop) >> 1;
        merge_sort(V, start, m, tmp);
        merge_sort(V, m+1, stop, tmp);
        inversion += merge(V, start, stop, m, tmp);
    }
}

int main() {
    int n;
    cin >> n;
    V.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> V[i];
    }
    vector<int> tmp(n);
    merge_sort(V, 0, n-1, tmp);
    cout << inversion;
}