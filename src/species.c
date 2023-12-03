#include "Simulation.h"
#include <string.h>

void    print_species_info(Species *species)
{
    printf("\tSpecies Information\n");
    printf("NAME:\t\t%s\n", species->name);
    printf("BIRTH RATE:\t%f\n", species->birth_rate);
    printf("DEATH RATE:\t%f\n", species->death_rate);
}

void    destroy_species(Species *species)
{
    if (species)
    {
        if (species->name)
            free(species->name);
        free(species);
    }
}

Species *create_species(const char *name, int population_start, float birth_rate, float death_rate)
{
    Species *new_species;

    new_species = malloc(sizeof(Species));
    if (!new_species)
    {
        printf("Failed to malloc Species\n");
        return (NULL);
    }
    
    new_species->name = strdup(name);
    new_species->population = population_start;
    new_species->birth_rate = birth_rate;
    new_species->death_rate = death_rate;

    return (new_species);
}
