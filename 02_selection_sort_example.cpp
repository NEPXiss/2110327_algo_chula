#include <iostream>
#include <vector>
using namespace std;

vector<int> selection_sort_ver1(vector<int> A) {
    vector<int> B(A.size());
    while (A.size() > 0) {
        auto it = max_element(A.begin(), A.end());
        B[A.size() - 1] = *it;
        swap(*it, A[A.size() - 1]);
        A.pop_back();
    }
    return B;
}