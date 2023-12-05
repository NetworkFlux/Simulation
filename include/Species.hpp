#pragma once

#include "Simulation.hpp"

class Species
{
    // Members
    public:
        string  name;
        long    population;

    private:
        float       _birthRate;
        float       _deathRate;
        float       _reproduciontRate;

    // Constructors
    public:
        Species();
        ~Species();

    // Getters/Setters
    public:
        float   getBirthRate() const;
        float   getDeathRate() const;
    
    // Private Methods
    private:
        int simulateStep(void);
        int simulateEvent(float eventRate) const;

    // Public Methods
    public:
        void    runSimulation(int steps, bool saveSimulation);
        void    printInfo(void) const;
    
};

