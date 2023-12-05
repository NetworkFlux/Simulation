#include <Simulation.hpp>

void    runSimulation(int type)
{
    Species species = Species();
    string  buff;
    bool    visualization = false;

    cout << "Do you want visualization ? (y/n)\n";
    cin >> buff;

    if (buff == "y")
        visualization = true;

    if (type == 1)
        species.runSimulation(100, visualization);

    return ;
}
