#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> X,Y;

int calculate(pair<int,int> p1, pair<int,int> p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return dx*dx + dy*dy;
}

int bf(int start, int stop) {
    int dq = calculate(X[start], X[stop]);
    for (int i = start; i <= stop; i++) {
        for (int j = i+1; j <= stop; j++) {
            dq = min(dq, calculate(X[i],X[j]));
        }
    }
    return dq;
}

int closest_pair(int start, int stop, vector<pair<int,int>> &Y) {
    if (stop - start <= 3) return bf(start,stop);
    int m = (start + stop) >> 1;

    // use left_Y, right_Y to reduce no. of combinations 
    // (left_Y means every pair in left half (already sorted by x) sorted by y)
    vector<pair<int,int>> left_Y, right_Y;
    for (auto &a : Y) {
        if (a.first <= X[m].first) left_Y.push_back(a);
        else right_Y.push_back(a);
    }
    int dl = closest_pair(start,m, left_Y);
    int dr = closest_pair(m+1,stop, right_Y);
    int c = min(dl,dr);

    vector<pair<int,int>> search_boundary;
    for (auto &x : Y) {
        if (abs(x.first - X[m].first) <= c) search_boundary.push_back(x);
    }

    int dm = c;
    for(int i = 0; i < search_boundary.size(); i++) {
        int j = i+1;
        while(j < search_boundary.size() && search_boundary[j].first <= c) {
            dm = min(dm, calculate(search_boundary[i],search_boundary[j]));
            j++;
        }
    }
    return min(c,dm);
}

int main() {
    int n; cin >> n;
    Y.resize(n);
    for (int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        X.push_back(make_pair(x,y));
        Y[i] = X[i];
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end(), [](pair<int,int> p1, pair<int,int> p2){return p1.second < p2.second;});
    cout << closest_pair(0, n-1, Y);
}