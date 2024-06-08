#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// a function to generate a random number while also checking that it doesnt repeats more than twice
int random_generator(int* array) {
    // srand(time(0));
    int a = 1;
    int random;
    while (a) {
        // generating random number
        random = (rand() % 100);
        // checking if its not reperating more than twice
        if (array[random] < 2) {
            array[random]++;
            a--;
        }
    }
    // cout << random << endl;
    return random;
}

// calcualte food
// note that creatures[100][6] is hard coded value and need to be chenged when max_creatures changes.
int* calculate_food(int creatures[100][6]) {
    for (int i = 0; i < 100; i++) {
        // cout << "works" << 100 << endl;
        for (int j = 0; j < 100; j++) {
            if (creatures[i][5] == creatures[j][5] && i != j) {
                creatures[i][3] = 1;
                creatures[j][3] = 1;
                creatures[i][4] = 0;
                creatures[i][4] = 0;
                break;
                cout << "did" << i << " " << j << " " << creatures[i][5] << " " << creatures[j][5] << endl;
            } else {
                creatures[i][3] = 1;
                creatures[i][4] = 1;
                cout << i << "-" << j << " ";
            }
        }
    }
    return creatures[6];
}

// adding a creature to the array
int* add_one(int creatures[100][6]) {
}

int* next_generation(int creatures[100][6]) {
    // cout<<"works"<<endl;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            // survival
            if (creatures[i][3] == 1 && creatures[i][4] == 0) {
                cout << " " << creatures[i][0];
                creatures[i][3] = 0;
            }
            if (creatures[i][3] == 0) {
                for (int k = 0; k < 6; k++) {
                    creatures[i][k] = 0;
                }
            }
            if (creatures[i][3] == 1 && creatures[i][4] == 1) {
                creatures[i][3] = 0;
                creatures[i][4] = 0;
                add_one(creatures);
            }
        }
    }
}

int main() {
    int max_creatures = 100;
    int creatures_count = 100;
    int doves = 80;
    int hawks = 20;
    int gen = 1;
    int food = 50;

    // structure of array taken [100*5]
    int creatures[max_creatures][6];
    // creature number
    // generation
    // agression
    // survival
    // reproduction
    // food_no

    // assigning generation 1 to every creauture.
    for (int i = 0; i < 100; i++) {
        creatures[i][1] = 1;
    }

    // assigning doves and hawks values
    for (int i = 0; i < doves; i++) {
        creatures[i][2] = 0;
    }
    for (int i = 0; i < hawks; i++) {
        creatures[i + doves][2] = 1;
    }

    // assigning a unique number to every creature
    for (int i = 0; i < creatures_count; i++) {
        creatures[i][0] = i + 1;
    }

    // food assigning with a checker for not more than 2 repeteition
    for (int i = 0; i < creatures_count; i++) {
        int food_counter[food];
        int random_number = random_generator(food_counter);
        creatures[i][5] = random_number;
    }

    // calculating survival and reproduction for next generation.

    // for (int i = 0; i < 100; i++) {
    //     cout << creatures[i][0] << " " << creatures[i][1] << " " << creatures[i][2] << " " << creatures[i][3] << " " << creatures[i][4] << " " << creatures[i][5] << endl;
    // }

    // cout << "----------------------------------" << endl;
    calculate_food(creatures);
    for (int i = 0; i < 100; i++) {
        cout << creatures[i][0] << " " << creatures[i][1] << " " << creatures[i][2] << " " << creatures[i][3] << " " << creatures[i][4] << " " << creatures[i][5] << endl;
    }
    // cout << "reaching here" << endl;

    // calculating the next generation
}