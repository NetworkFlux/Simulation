#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Species_s
{
    char    *name;
    int     population;
    float   birth_rate;
    float   death_rate;
}   Species;

// Species
Species *create_species(const char *name, int population_start, float birth_rate, float death_rate);
void    destroy_species(Species *species);
void    print_species_info(Species *species);

// SIMULATION
int     simulate_step(Species *species);
int     simulate_events(int population, float event_rate);

// RANDOM
void    initialize_random(void);
