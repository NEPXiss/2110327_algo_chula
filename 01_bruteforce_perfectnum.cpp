#include <iostream>
#include <vector>

using namespace std;

bool perfect_num(int a) {
    vector<int> divisors;
    for (int i = 1; i <= a/2; i++) 
        if (a%i == 0) divisors.push_back(i);
    int b = 0;
    for (auto x : divisors) b += x;
    if (b == a) return true;
    return false;
}

int main() {
    int j;
    cout << "Please enter your number: ";
    cin >> j;
    bool test = perfect_num(j);
    if (test) cout << "YES";
    else cout << "NO";
}