#include "Simulation.h"

// This function simulates a number of events
// (e.g., births or deaths) based on the event rate
int simulate_events(int population, float event_rate)
{
    int event_count = 0;

    for (int i = 0; i < population; i++)
    {
        if ((rand() / (float)RAND_MAX) < event_rate)
            event_count++;
    }

    return event_count;
}

int simulate_step(Species *species)
{
    int deaths = simulate_events(species->population, species->death_rate);
    int births = simulate_events(species->population, species->birth_rate);

    species->population -= deaths;
    species->population += births;

    if (species->population < 0)
        species->population = 0; // Prevent negative population

    return (births - deaths);
}
