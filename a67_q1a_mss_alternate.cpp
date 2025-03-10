#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n;

int acc(int start, int stop) {
    return v[start] - v[stop];
}

int mcs(int start, int stop) {
    // cout << "CHECKING : " << start << " " << stop << "\n";
    if (start == stop) {
        return v[start];
        // cout << "-------------------------\n";
    }


    int mid = (start + stop) >> 1;
    int ml = mcs(start, mid);
    int mr = mcs(mid + 1, stop);

    // cout << "ml = " << ml << " mr = " << mr << "\n";

    // Left
    int bestEvenL = -1e9;
    int currEvenL = 0;
    int bestOddL = v[mid];
    int currOddL = v[mid];
    for (int i = 1; i < mid - start + 1; i++) {
        if (mid - (2*i) + 1 >= start) {
            currEvenL += acc(mid - (2*i) + 1, mid - (2*i) + 1 + 1);
            bestEvenL = max(bestEvenL, currEvenL);
        }
        if (mid - (2*i) >= start) {
            currOddL += acc(mid - (2*i), mid - (2*i) + 1);
            bestOddL = max(bestOddL, currOddL);
        }
    }

    // Right
    int bestEvenR = -1e9;
    int currEvenR = 0;
    int bestOddR = v[mid + 1];
    int currOddR = v[mid + 1];
    int lessEvenR = 1e9;
    int currLessEvenR = 0;
    int lessOddR = v[mid + 1];
    int currLessOddR = v[mid + 1];
    
    for (int i = 1; i < stop - mid + 1 ; i++) {
        if (mid + 1 + (2*i) - 1 <= stop) {
            currEvenR += acc(mid + 1  + (2*i) - 1 - 1, mid + 1 + (2*i) - 1);
            bestEvenR = max(bestEvenR, currEvenR);

            currLessEvenR += acc(mid + 1 + (2*i) - 1 - 1, mid + 1 + (2*i) - 1);
            lessEvenR = min(lessEvenR, currLessEvenR);
        }
        if (mid + 1 + (2*i) <= stop) {
            // cout << " i = " << i << " currOddR = " << currOddR << " currbest = " << bestOddR << "\n";
            currOddR -= acc(mid + 1 + (2*i) - 1, mid + 1 + (2*i));
            bestOddR = max(currOddR, bestOddR);
            // cout << " new best : " << bestOddR << "\n";

            currLessOddR -= acc(mid + 1 + (2*i) - 1, mid + 1 + (2*i));
            lessOddR = min(currLessOddR, lessOddR);
        }
    }

    // cout << "BEL = " << bestEvenL << "\n";
    // cout << "BER = " << bestEvenR << "\n";
    // cout << "BOL = " << bestOddL << "\n";
    // cout << "BOR = " << bestOddR << "\n";
    // cout << "LER = " << lessEvenR << "\n";
    // cout << "LOR = " << lessOddR << "\n";

    int p = bestEvenL + bestEvenR;
    int q = bestEvenL + bestOddR;
    int r = bestOddL - lessEvenR;
    int s = bestOddL - lessOddR;
    int mm = max(max(p,q),max(r,s));

    // cout << "mm = " <<  mm << "\n";
    // cout << "max() : " << max(max(mr,ml),mm) << "\n";
    // cout << "-------------------------\n";
    return max(max(mr,ml),mm);
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << mcs(0,n-1);
    return 0;
}