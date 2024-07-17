// * Doves and Hawks Simulation.
// * Author: Aditya  

//adding libraries
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// ? number of generations. C1
int iterations = 100;

// contains generation data. C1
int numbers[100][3] = {0};
int itr = 0;

// ? assign trees to each creature C2
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

// ? decides how much food one gets, also contains the food matrix. C2
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

    //food matrix
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
    return creatures[6];
}

// ? finds the creature num for upcoming creature. C2
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

// ? gives and takes life of a creature. C2
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
            creatures[i][3] = 0;
            creatures[i][4] = 0;
            creatures[i][5] = 0;
        }
    }
    return creatures[6];
}

// ? calculates stats in a iterations. C2
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
    numbers[itr][0] = creatures[0][0];
    numbers[itr][1] = u_doves;
    numbers[itr][2] = u_hawks;
    cout << "doves: " << u_doves << endl;
    cout << "hawks: " << u_hawks << endl;
    return creatures[6];
}

// ? gives generation data. C2
void gen(int creatures[1001][6]) {
    int max = creatures[0][4];
    int stat = creatures[0][5];
    int generation[stat] = {0};
    for (int i = 1; i < max; i++) {
        if (creatures[i][0] != 0) {
            generation[creatures[i][1]]++;
        }
    }
    cout << "---------------" << endl;
    cout << "Number of creatures of a generation in each iteration: " << endl;
    for (int i = 0; i < stat; i++) {
        cout << generation[i] << " ";
    }
    cout << endl;
    
}
// ? collection of functions in loop. C2
int* next(int creatures[1001][6]) {
    assign_trees(creatures);
    calculate_food(creatures);
    deathORlife(creatures);
    stat(creatures);
    return creatures[6];
}

//calculates average of number of both types after each generation.
void average() {
    int sumh = 0, sumd = 0, sumt = 0;
    for (int i = 0; i < iterations; i++) {
        sumt += numbers[i][0];
        sumd += numbers[i][1];
        sumh += numbers[i][2];
    }
    cout << "average no. of creatures: " << (float)sumt / iterations << endl;
    cout << "average no. of doves: " << (float)sumd / iterations << endl;
    cout << "average no. of hawks: " << (float)sumh / iterations << endl;
}

int main() {
    //reset random values.
    srand(time(0));

    //initialize values.
    int doves = 500;
    int hawks = 500;
    int total_creatures = doves + hawks;
    int generation = 0;
    int tree_available = 500;
    int max_creatures = 2 * tree_available + 1;
    int creatures[max_creatures][6];

    // position 0 stores crutial information.
    creatures[0][0] = total_creatures;
    creatures[0][1] = doves;
    creatures[0][2] = hawks;
    creatures[0][3] = tree_available;
    creatures[0][4] = max_creatures;
    creatures[0][5] = iterations;

    // creating the doves and hawks to start
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

    // declaring rest all dead to avoid garbage values.
    for (int i = 1 + doves + hawks; i < max_creatures; i++) {
        creatures[i][0] = 0;
    }
    for (int i = 0; i < max_creatures; i++) {
        if (creatures[i][0] == 0) {
            creatures[i][1] = 0;
            creatures[i][2] = 0;
            creatures[i][3] = 0;
            creatures[i][4] = 0;
            creatures[i][5] = 0;
        }
    }

    // show initial number of creatures
    cout << "iteration no. " << itr << endl;
    stat(creatures);

    for (int i = 0; i < iterations; i++) {
        itr++;
        cout << "---------------" << endl;
        cout << "iteration no. " << itr << endl;
        next(creatures);
    }
    gen(creatures);
    average();
}