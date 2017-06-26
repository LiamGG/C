#define ISINGSIZE 32
#include "IsingParticle.h"
#include <cstdlib>


class IsingSystem {
      private:
              IsingParticle particles[ISINGSIZE][ISINGSIZE];
              int current_column;
              int current_row;
              int left_column;
              int right_column;
              int up_row;
              int down_row;
              void find_neighbours();
      public:
             IsingSystem();
             void choose(); // choose a particle in the lattice
             void perturb(); // spin-flip for the chosen particle
             void print(); // prints the lattice configuration
             double localEnergy(); // Interaction energy for the chosen particle
             double totalEnergy(); // total energy for the lattice
             double magnetisation(); // magnetisation of the system
};

