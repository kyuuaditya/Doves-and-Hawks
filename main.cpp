#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// hard coded.
int* assign_food(int creatures[100][6]) {
    int food_available = 50;
    // hard coded
    int food_count = 2 * food_available;
    int food_checker[food_available] = {0};
    while (food_count) {
        int random_number = rand() % food_available;
        if (food_checker[random_number] < 2) {
            creatures[food_available * 2 - food_count][5] = random_number + 1;
            food_checker[random_number]++;
            food_count--;
        }
    }
    for (int i = 0; i < 2 * food_available; i++) {
        if (creatures[i][5] > food_available) {
            creatures[i][5] = 0;
        }
    }
    return creatures[6];
}

// hard coded
int* calculate_food(int creatures[100][6]) {
    // hard coded
    int rows = 100;
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < rows; i++) {
        if (creatures[i][5] == 0) {
            creatures[i][0] = 0;
            creatures[i][1] = 0;
            creatures[i][2] = 0;
            creatures[i][3] = 0;
            creatures[i][4] = 0;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (creatures[i][5] == creatures[j][5] && i != j) {
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
            } else {
                creatures[i][4] = 1;
            }
        }
    }
    // for (int i = 0; i < 100; i++) {
    //     cout << creatures[i][0] << " " << creatures[i][1] << " " << creatures[i][2] << " " << creatures[i][3] << " " << creatures[i][4] << " " << creatures[i][5] << " " << endl;
    // }
    cout << a << " " << b << " " << c << " " << d << endl;
    return creatures[6];
}

int main() {
    srand(time(0));
    int doves = 60;
    int hawks = 40;
    int total_creatures = doves + hawks;
    int generation;
    // when changing food_available value search hardcoded and replace other values with twice of this
    int food_available = 50;
    int max_creatures = 2 * food_available;
    int creatures[max_creatures][6];

    for (int i = 0; i < max_creatures; i++) {
        creatures[i][1] = 1;
        creatures[i][0] = i + 1;
    }

    for (int i = 0; i < doves; i++) {
        creatures[i][2] = 0;
    }

    for (int i = 0; i < hawks; i++) {
        creatures[i + doves][2] = 1;
    }

    for (int i = 0; i < max_creatures; i++) {
        creatures[i][3] = 0;
        creatures[i][4] = 0;
    }

    assign_food(creatures);

    calculate_food(creatures);
    // for (int i = 0; i < max_creatures; i++) {
    //     cout << creatures[i][0] << " " << creatures[i][1] << " " << creatures[i][2] << " " << creatures[i][3] << " " << creatures[i][4] << " " << creatures[i][5] << " " << endl;
    // }
}