#include <iostream>
#include <vector>
#include <string>

using namespace std;

void gen_path(vector<vector<int>> &grid, vector<string> commands, int cur_r, int cur_c, int r, int c, string sol) {
    if (cur_r == r - 1 && cur_c == c - 1) {
        cout << sol << endl;
        return;
    }
    for (auto &x : commands) {
        if (x == "A" && cur_c + 1 < c && grid[cur_r][cur_c + 1] < c && grid[cur_r][cur_c + 1] >= 0) {
            if (grid[cur_r][cur_c + 1] != 1 && grid[cur_r][cur_c + 1] != 2) {
                sol += x;
                grid[cur_r][cur_c + 1] = 2;
                gen_path(grid,commands,cur_r,cur_c+1,r,c,sol);
                sol.pop_back();
                grid[cur_r][cur_c + 1] = 0;
            }
        } else if (x == "B" && cur_r + 1 < r && grid[cur_r + 1][cur_c] < r && grid[cur_r + 1][cur_c] >= 0) {
            if (grid[cur_r + 1][cur_c] != 1 && grid[cur_r + 1][cur_c] != 2) {
                sol += x;
                grid[cur_r + 1][cur_c] = 2;
                gen_path(grid,commands,cur_r + 1,cur_c,r,c,sol);
                sol.pop_back();
                grid[cur_r + 1][cur_c] = 0;
            }
        } else if (x == "C" && cur_r - 1 >= 0 && grid[cur_r - 1][cur_c] < r && grid[cur_r - 1][cur_c] >= 0) {
            if (grid[cur_r - 1][cur_c] != 1 && grid[cur_r - 1][cur_c] != 2) {
                sol += x;
                grid[cur_r - 1][cur_c] = 2;
                gen_path(grid,commands,cur_r - 1,cur_c,r,c,sol);
                sol.pop_back();
                grid[cur_r - 1][cur_c] = 0;
            }
        }
    }
}

int main() {
    vector<string> commands = {"A", "B", "C"};
    int r,c;
    cin >> r >> c;
    vector<vector<int>> grid;
    for (int i = 0; i < r; i++) {
        vector<int> row;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            row.push_back(a);
        }
        grid.push_back(row);
    }
    string sol = "";
    grid[0][0] = 2;
    gen_path(grid, commands, 0, 0, r, c, sol);
    cout << "DONE";
}