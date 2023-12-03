#include "Simulation.h"

int	main(void)
{
    Species *first_species;

    first_species = create_species("First", 50, 0.15, 0.1);
    FILE *file = fopen("simulation_data.csv", "w");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    print_species_info(first_species);

    // Write header
    fprintf(file, "Step,Population,Change\n");

    initialize_random();

    for (int step = 0; step < 200; step++)
    {
        int diff = simulate_step(first_species);
        fprintf(file, "%d,%d,%d\n", step, first_species->population, diff);
    }

    fclose(file);
    destroy_species(first_species);

	return (0);
}
