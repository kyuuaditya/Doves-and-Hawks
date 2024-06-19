#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// assign trees
int* assign_trees(int creatures[1001][6]) {
    int count = creatures[0][0];
    int tree_available = creatures[0][3];
    int max = creatures[0][4];
    int runs;
    if (max > count) {
        runs = count;
    } else {
        runs = max;
    }
    int tree_checker[tree_available] = {0};
    int creature_checker[max] = {0};
    while (runs) {
        int random = rand() % max;
        if (creatures[random][0] != 0 && random != 0 && creature_checker[random] < 1) {
            int random2 = rand() % tree_available;
            if (tree_checker[random2] < 2) {
                creatures[random][5] = random2 + 1;
                creature_checker[random]++;
                tree_checker[random2]++;
                runs--;
            }
        }
    }
    for (int i = 1; i < max; i++) {
        if (creatures[i][5] > max || creatures[i][5] < 0) {
            creatures[i][5] = 0;
        }
    }
    return creatures[6];
}

// hardcoded
int* calculate_food(int creatures[1001][6]) {
    int count = creatures[0][0];
    int tree_available = creatures[0][3];
    int max = creatures[0][4];

    for (int i = 1; i < max; i++) {
        if (creatures[i][5] == 0) {
            creatures[i][0] = 0;
            creatures[i][1] = 0;
            creatures[i][2] = 0;
            creatures[i][3] = 0;
            creatures[i][4] = 0;
        }
    }

    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 1; i < max; i++) {
        for (int j = 1; j < max; j++) {
            if (creatures[i][5] == creatures[j][5] && i != j && creatures[i][0] != 0) {
                if (creatures[i][2] == 0 && creatures[j][2] == 0) {
                    creatures[i][3] = 1;
                    creatures[i][4] = 0;
                    a++;
                    break;
                }
                if (creatures[i][2] == 1 && creatures[j][2] == 0) {
                    creatures[i][3] = 1;
                    creatures[i][4] = (rand() % 100) / 50;
                    b++;
                    break;
                }
                if (creatures[i][2] == 0 && creatures[j][2] == 1) {
                    creatures[i][3] = (rand() % 100) / 50;
                    creatures[i][4] = 0;
                    c++;
                    break;
                }
                if (creatures[i][2] == 1 && creatures[j][2] == 1) {
                    creatures[i][3] = 0;
                    creatures[i][4] = 0;
                    d++;
                    break;
                }
            } else if (creatures[i][0] != 0) {
                creatures[i][3] = 1;
                creatures[i][4] = 1;
            }
        }
    }
    // cout << a << " " << b << " " << c << " " << d << endl;
    return creatures[6];
}

int creature_num(int creatures[1001][6]) {
    int num = 0;
    int max = creatures[0][4];
    for (int i = 1; i < max; i++) {
        if (creatures[i][0] > num) {
            num = creatures[i][0];
        }
    }
    return num;
}
// hardcoded
int* deathORlife(int creatures[1001][6]) {
    int max = creatures[0][4];
    for (int i = 1; i < max; i++) {
        if (creatures[i][3] == 0) {
            creatures[i][0] = 0;
            creatures[i][1] = 0;
            creatures[i][2] = 0;
            creatures[i][4] = 0;
            creatures[i][5] = 0;
        }
    }
    for (int i = 1; i < max; i++) {
        if (creatures[i][4] == 1) {
            int temp = 1;
            int birth = 1;
            while (birth) {
                if (creatures[temp][0] == 0) {
                    creatures[temp][0] = creature_num(creatures) + 1;
                    creatures[temp][1] = creatures[i][1] + 1;
                    creatures[temp][2] = creatures[i][2];
                    birth--;
                } else {
                    temp++;
                }
            }
        }
    }
    for (int i = 1; i < max; i++) {
        if (creatures[i][3] == 1) {
            creatures[i][1]++;
            creatures[i][3] = 0;
            creatures[i][4] = 0;
            creatures[i][5] = 0;
        }
    }
    return creatures[6];
}
// hardcoded

int* kill(int creatures[1001][6]) {
    int max_creatures = creatures[0][4];
    for (int i = 0; i < max_creatures; i++) {
        if (creatures[i][0] == 0) {
            creatures[i][1] = 0;
            creatures[i][2] = 0;
            creatures[i][3] = 0;
            creatures[i][4] = 0;
            creatures[i][5] = 0;
        }
    }
    return creatures[6];
}

void print(int creatures[1001][6]) {
    int max_creatures = creatures[0][4];
    cout << "==========" << endl;
    for (int i = 0; i < max_creatures; i++) {
        if (creatures[i][0] != 0) {
            cout << creatures[i][0] << " " << creatures[i][1] << " " << creatures[i][2] << " " << creatures[i][3] << " " << creatures[i][4] << " " << creatures[i][5] << endl;
        }
    }
}

int* stat(int creatures[1001][6]) {
    int count = creatures[0][0];
    int doves = creatures[0][1];
    int hawks = creatures[0][2];
    int tree_available = creatures[0][3];
    int max = creatures[0][4];

    int u_doves = 0;
    int u_hawks = 0;
    for (int i = 1; i < max; i++) {
        if (creatures[i][2] == 0 && creatures[i][0] != 0) {
            u_doves++;
        }
        if (creatures[i][2] == 1 && creatures[i][0] != 0) {
            u_hawks++;
        }
    }
    creatures[0][0] = u_doves + u_hawks;
    // cout << "_____________" << endl;
    cout << "doves: " << u_doves << endl;
    cout << "hawks: " << u_hawks << endl;
    cout << "_____________" << endl;

    return creatures[6];
}

int* next(int creatures[1001][6]) {
    assign_trees(creatures);
    calculate_food(creatures);
    // print(creatures);
    deathORlife(creatures);
    // cout << "<------------->" << endl;
    stat(creatures);
    return creatures[6];
}

int main() {
    int iterations = 50;
    srand(time(0));

    int doves = 10;
    int hawks = 990;
    int total_creatures = doves + hawks;
    int generation = 0;
    int tree_available = 500;
    //-------------------------------------
    int max_creatures = 2 * tree_available + 1;
    //-------------------------------------
    int creatures[max_creatures][6];

    // position 0 manual storage
    creatures[0][0] = total_creatures;
    creatures[0][1] = doves;
    creatures[0][2] = hawks;
    creatures[0][3] = tree_available;
    creatures[0][4] = max_creatures;

    // assigning the doves and hawks to start
    for (int i = 1; i < doves + 1; i++) {
        creatures[i][0] = i;
        creatures[i][1] = 1;
        creatures[i][2] = 0;
        creatures[i][3] = 0;
        creatures[i][4] = 0;
        creatures[i][5] = 0;
    }
    for (int i = 1 + doves; i < hawks + doves + 1; i++) {
        creatures[i][0] = i;
        creatures[i][1] = 1;
        creatures[i][2] = 1;
        creatures[i][3] = 0;
        creatures[i][4] = 0;
        creatures[i][5] = 0;
    }
    // declaring rest all dead
    for (int i = 1 + doves + hawks; i < max_creatures; i++) {
        creatures[i][0] = 0;
    }
    // killing the declared deads
    kill(creatures);

    // show initial number of creatures
    stat(creatures);

    for (int i = 0; i < iterations; i++) {
        next(creatures);
    }

    // testing
    cout << "<------------------>" << endl;
    // print(creatures);
}