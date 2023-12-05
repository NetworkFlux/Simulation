#include "Simulation.hpp"
#include <cstdio>

Species::Species()
{
    name = "Basic Species";
    population = 10;
    _birthRate = 0.1;
    _deathRate = 0.1;
    _reproduciontRate = 0.1;

}

Species::~Species()
{

}


// Getters/Setters
float    Species::getBirthRate(void) const
{
    return (_birthRate);
}

float    Species::getDeathRate(void) const
{
    return (_deathRate);
}

int    Species::simulateStep(void)
{
    int deaths = simulateEvent(this->_deathRate);
    int births = simulateEvent(this->_birthRate);

    this->population -= deaths;
    this->population += births;

    if (this->population < 0)
        this->population = 0;

    return (births - deaths);
}

int Species::simulateEvent(float eventRate) const
{
    int eventCount = 0;

    for (int i = 0; i < this->population; i++)
    {
        if ((rand() / (float)RAND_MAX) < eventRate)
            eventCount++;
    }

    return (eventCount);
}

void    Species::runSimulation(int steps, bool saveSimulation)
{
    int     diff = 0;
    FILE    *file = NULL;
    
    if (saveSimulation)
    {
        file = fopen("simulation_data.csv", "w");
        if (!file)
        {
            perror("Error opening file");
            return ;
        }
        fprintf(file, "Step,Population,Change\n");
    }
    
    for (int step = 0; step < steps; step++)
    {
        diff = simulateStep();
        printf("%d %ld %d\n", step, this->population, diff);
        if (saveSimulation)
            fprintf(file, "%d,%ld,%d\n", step, this->population, diff);
    }

    if (saveSimulation)
        fclose(file);
}

void    Species::printInfo(void) const
{
    std::cout << "\tSPECIES INFORMATION" << std::endl;
    std::cout << "NAME\t\t\t" << name << std::endl;
    std::cout << "BRITH RATE\t\t" << _birthRate << std::endl;
    std::cout << "DEATH RATE\t\t" << _deathRate << std::endl;
    std::cout << "REPRODUCTION RATE\t" << _reproduciontRate << std::endl;
}







