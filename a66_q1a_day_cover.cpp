#include <iostream>
#include <vector>

using namespace std;

int ans;
vector<vector<int>> students_available_days;
vector<vector<int>> students_assign;
vector<bool> days;
int n, m;

void solve(int current_group, int covered_days, int used_group) {
    /*
    Algorithm:
    i-th group = i-th student
    We will try to assign each student to maximum of his/her work days. 
    In other words, if Smith (1st student) can work on day 2,5,8. We will assign him those 3 days.

    */
    if (used_group >= ans) return; 
    if (covered_days == n) {
        ans = min(used_group, ans);
        return;
    }
    if (current_group >= m) return;
    bool check = false;
    for (auto &x : students_available_days[current_group]) {
        if (!days[x]) {
            days[x] = true;
            covered_days++;
            check = true;
            students_assign[current_group].push_back(x);
        }
    }
    if (check) solve(current_group + 1, covered_days, used_group + 1);
    for (auto &x : students_assign[current_group]) {
        days[x] = false;
        covered_days--;
    }
    students_assign[current_group].resize(0);
    solve(current_group + 1, covered_days, used_group);
}

int main() {
    // idea from hall-of-frame
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    students_available_days.resize(m);
    students_assign.resize(m);
    days.resize(n, false);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            students_available_days[i].push_back(b-1);
        }
    }
    ans = m;
    solve(0,0,0);
    cout << ans;
}