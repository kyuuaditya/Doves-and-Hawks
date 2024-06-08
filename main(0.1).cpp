#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// structure of the creature which stores all the values
struct Creature {
    int generation;
    int creature_number;
    int agression;
    int survival;
    int reproduction;
    struct Creature* next;
};

// add a new creature at the start of the linked list
void push(struct Creature** head, int add_generation, int add_creature_number, int add_agression, int add_survival, int add_reproduction) {
    struct Creature* new_creature = new Creature;
    new_creature->generation = add_generation;
    new_creature->creature_number = add_creature_number;
    new_creature->agression = add_agression;
    new_creature->survival = add_survival;
    new_creature->reproduction = add_reproduction;
    new_creature->next = *head;
    *head = new_creature;
}

// delete an specific creature of the linked list
void del(struct Creature* head, int creature_del) {
    if (head == NULL) {
        cout << "no linked list present" << endl;
    }
    struct Creature* removed = head;
    if (head->creature_number == creature_del) {
        *head = *head->next;
        return;
    }
    while ((removed->next)->creature_number != creature_del) {
        removed = removed->next;
    }
    removed->next = removed->next->next;
}

// display command to show all the data about the creatures
void display(struct Creature* creature) {
    while (creature != NULL) {
        cout << creature->generation << " " << creature->creature_number << " " << creature->agression << " " << creature->survival << " " << creature->reproduction << endl;
        creature = creature->next;
    }
    if (creature == NULL) {
        cout << "end of list" << endl;
    }
}
// assigning the food slot array to individual creatures
int* assign_food(struct Creature* creature, int population) {
    static int temp_food[10];
    int temp_creatures[population];
    int count = 0;
    while (creature != NULL) {
        temp_creatures[count] = creature->creature_number;
        count++;
        creature = creature->next;
    }
    srand(time(0));
    int random_number;
    int iterations = population;
    // as the no. of food is 10
    int checker[10] = {0};
    while (iterations) {
        random_number = ((int)((((double)(rand() % 100000000) + 1) / 100000001) * 100000) % 10);
        // cout << random_number << endl;
        if (checker[random_number] < 1) {
            if (iterations <= 10)
                temp_food[random_number] = temp_creatures[population - iterations];
            cout << "---" << temp_creatures[population - iterations] << "---" << random_number << "---" << temp_food[random_number] << endl;
            checker[random_number]++;
            iterations--;
        }
    }

    return temp_food;
}

// main fuction
int main() {
    // creating the head fuction for creatures.
    struct Creature* head = NULL;

    // adding the creatures manually to test
    // push(&head, 1, 1, 0, 1, 1);
    // push(&head, 1, 2, 0, 1, 0);
    // push(&head, 1, 3, 1, 1, 0);
    // push(&head, 1, 4, 0, 0, 1);
    // push(&head, 1, 5, 0, 1, 0);
    // push(&head, 1, 6, 1, 0, 1);
    // push(&head, 1, 7, 0, 1, 0);
    // push(&head, 1, 8, 1, 1, 1);
    // push(&head, 1, 8, 1, 1, 1);
    // push(&head, 1, 8, 1, 1, 1);
    // display(head);

    // creature counter
    int creature_count = 0;

    // loop to create one certain types of creatures
    int Doves = 3;
    int Hawks = 7;
    int gen = 1;
    for (int i; i < Doves; i++) {
        push(&head, gen, creature_count + 1, 0, 0, 0);
        creature_count++;
    }
    for (int i; i < Hawks; i++) {
        push(&head, gen, creature_count + 1, 1, 0, 0);
        creature_count++;
    }
    // displaying the initial creatures
    display(head);
    cout << "---------------------------------" << endl;
    // food array
    int total_pop = Doves + Hawks;
    int* food = assign_food(head, total_pop);
    for (int i; i < 10; i++) {
        cout << food[i] << endl;
    }
}