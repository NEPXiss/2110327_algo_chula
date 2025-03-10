#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<int> tower;
vector<int> monster;
vector<int> position;
vector<int> tower_assignment;
int n,m,k,w;
int ans;

void solve(int a) {
    // we must assign our configuration such that every tower has at least one monster to shoot 
    // -- even if it is prohibited by monster's health or k+-w;
    if (a != k) {
        //not all tower has been assigned
        for (int i = 0; i < m; i++) {
            tower_assignment[a] = i;
            solve(a + 1);
            /*
                When we start our 'solve' function, we pass a = 0. So the tower_assignment[0] = 0 and solve(1) will be called.
                which means that tower_assignment[1] = 0, also. And this goes on and on until every tower_assignment[i] = 0; where i is counted up to k;
                And when a = k, we evaluate our first configuration: tower_assignment[1...k] = [0,0,...,0] (In the 'else' condition)

                But don't forget that the for loop "for (int i = 0; i < m; i++)" always iterates "again" from 0 to m - by nature of recursion.
                So if we fix tower_assignment[0] = 0, we will have, by such nature of for-loop, we will eventually generate tower_assignment[1] = 1, tower_assignment[2] = 1.. etc. too
                Therefore, by this for loop, we generate ALL possible combinations.
            */
        }
    } else {
        // every tower has been assigned:
        vector<int> hit_damage(m);
        // make every tower shoot if it is possible:
        for(int i = 0; i < k; i++) {
            int monster_index = tower_assignment[i];
            if (abs(tower[i] - position[monster_index]) <= w) {
                hit_damage[monster_index]++;
                // damage cannot be higher than monster's health
                hit_damage[monster_index] = std::min(monster[monster_index], hit_damage[monster_index]);
            }
        }

        //calculate the total possible health left:
        int sum = 0;
        for (int i = 0; i < m; i++) {
            // monster's health cannot be lower than 0;
            sum += max(monster[i] - hit_damage[i],0);
        }
        if (sum < ans) ans = sum;
    }

}

int main() {
    // idea by hall-of-frame
    cin >> n >> m >> k >> w;
    tower.resize(k); // stores position of tower
    monster.resize(m); // stores i-th monster's health
    position.resize(m); // stores i-th monster's position
    ans = 0;
    for (int i = 0; i < m ; i++) {
        cin >> position[i];
    }
    for (int i = 0; i < m ; i++) {
        cin >> monster[i];
        // total health
        ans += monster[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> tower[i];
    }
    tower_assignment.resize(k); //stores which monster the i-th tower will shoot
    solve(0);
    cout << ans;
}