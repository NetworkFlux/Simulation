#include "Simulation.hpp"

void initialize_random(void)
{
    srand(time(NULL));
}

int initialization(void)
{
    string buff;
    int choice;

    initialize_random();

    do {
        cout << "1. Introduction to Simulation\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> buff;
        choice = std::atoi(buff.c_str());

        if (choice >= 1 && choice <= 3)
            return (choice);
        else if (choice != 0)
            cout << "Invalid choice. Please try again.\n";
    } while (choice != 0);

    return (0);
}

int main(void)
{
    int choice;
    
    choice = initialization();

    if (choice != 0)
        runSimulation(choice);

    return (0);
}
