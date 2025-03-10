#include <iostream>
#include <vector>
using namespace std;
int N, A;

// get number of customers from width of the time
long long get_cust(long long width_time, vector<int> &chef)
{
    /* chef = 2 2 5
    if width = 5 --> 2 2 5 2 2
    [2] >> 5/2 >> 2
    [2] >> 5/2 >> 2
    [5] >> 5/5 >> 1
    [time chef takes] >> width/time
    */
    long long cnt = N;
    for (int time : chef)
    {
        cnt += width_time / time;
    }
    return cnt;
}

// Divided & Conquer >> BST
long long recur(long long l, long long r, vector<int> &chef, long long cust) {
    while (l < r) {
        long long m = (l + r) / 2;
        long long num_cust = get_cust(m, chef);

        if (num_cust >= cust) {
            r = m; // Search in the left half
        } else {
            l = m + 1; // Search in the right half 2^k : 1 << k;
        }
    }

    return l;
}

int main() {
    cin >> N >> A;
    
    vector<int> chef(N);
    for (int i = 0; i < N; i++) {
        cin >> chef[i];
    }

    for (int i = 0; i < A; i++) {
        long long cust;
        cin >> cust;
        cout << recur(0, 1000000000000LL, chef, cust) << endl;
    }

    return 0;
} 