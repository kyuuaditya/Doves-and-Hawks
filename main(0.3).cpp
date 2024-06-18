#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// hard coded.
int* assign_food(int creatures[1000][6]) {
    int rows = 1000;
    int food_available = 50;
    // hard coded
    int food_count = 2 * food_available;
    int food_checker[food_available] = {0};
    while (food_count) {
        if (creatures[food_available * 2 - food_count][0] != 0) {
            int random_number = rand() % food_available;
            if (food_checker[random_number] < 2) {
                creatures[food_available * 2 - food_count][5] = random_number + 1;
                food_checker[random_number]++;
                food_count--;
            }
        }
    }
    for (int i = 0; i < 2 * food_available; i++) {
        if (creatures[i][5] > food_available) {
            creatures[i][5] = 0;
        }
    }
    return creatures[6];
    /*
    int rows=1000;
    int food_available=50;
    int food_count=2*food_available;
    int food_checker[food_available]={0};
    int num=0;

    while(food_count){
        if(creatures[num][0]!=0){

        }
        food_count--;
        num++;
    }
    */
}

// hard coded
int* calculate_food(int creatures[1000][6]) {
    // hard coded
    int rows = 1000;
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

// hardcoded
int max(int creature[1000][6]) {
    int max = 0;
    // hardcoded
    int rows = 1000;
    for (int i = 0; i < rows; i++) {
        if (creature[i][0] > max) {
            max = creature[i][0];
        }
    }
    return max;
}

// hardcoded
//  death and birth of new characters
int* yamraj(int creatures[1000][6]) {
    // hardcoded
    int rows = 1000;
    for (int i = 0; i < rows; i++) {
        if (creatures[i][3] == 0) {
            creatures[i][0] = 0;
            creatures[i][1] = 0;
            creatures[i][2] = 0;
            creatures[i][3] = 0;
            creatures[i][4] = 0;
            creatures[i][5] = 0;
        }
        if (creatures[i][4] == 1) {
            int birth = 1;
            int traversal = rows;
            while (birth) {
                if (creatures[rows - traversal][0] == 0) {
                    creatures[rows - traversal][0] = max(creatures) + 1;
                    creatures[rows - traversal][2] = creatures[i][2];
                    creatures[rows - traversal][1] = creatures[i][1] + 1;
                    // reset stats
                    creatures[i][4] = 0;
                    birth--;
                }
                traversal--;
            }
        }
    }
    return creatures[6];
}

// hardcode
int count_doves(int creatures[1000][6]) {
    // hardcode
    int dove = 0;
    for (int i = 0; i < 1000; i++) {
        if (creatures[i][0] != 0) {
            if (creatures[i][2] == 0) {
                dove++;
            }
        }
    }
    return dove;
}

// hardcode
int count_hawks(int creatures[1000][6]) {
    // hardcode
    int hawk = 0;
    for (int i = 0; i < 1000; i++) {
        if (creatures[i][0] != 0) {
            if (creatures[i][2] == 1) {
                hawk++;
            }
        }
    }
    return hawk;
}

// hardcode
int* next(int creatures[1000][6]) {
    assign_food(creatures);
    calculate_food(creatures);
    yamraj(creatures);
    cout << "<--------------->" << endl;
    cout << count_doves(creatures) << " " << count_hawks(creatures) << endl;
    return creatures[6];
}

int main() {
    // reset the random variables
    srand(time(0));
    // setting the number of creatures
    int doves = 10;
    int hawks = 50;
    // total number of creatures
    int total_creatures = doves + hawks;
    // generation number
    int generation = 0;
    // total number of pairs of food available
    int food_available = 50;
    // max number of creatures possible
    int max_creatures = 1000;
    int creatures[1000][6];

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

    for (int i = 0; i < 1000; i++) {
        creatures[i][3] = 0;
        creatures[i][4] = 0;
    }
    cout << doves << " " << hawks << endl;

    for (int i = 0; i < 20; i++) {
        next(creatures);
    }
    for (int i = 0; i < 1000; i++) {
        if (creatures[i][0] != 0) {
            cout << creatures[i][0] << " " << creatures[i][1] << " " << creatures[i][2] << " " << creatures[i][3] << " " << creatures[i][4] << " " << creatures[i][5] << " " << endl;
        }
    }

    cout << "ends here" << endl;
}