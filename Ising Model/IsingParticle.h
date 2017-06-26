//spin 1/2 Ising particle class
#ifndef ISINGPARTICLE_H
#define ISINGPARTICLE_H
#include <cstdlib>


class IsingParticle {
      private:
              int spin; //private data. +1 is spin up, -1 is spin down
              
      public:
             IsingParticle(); //constructor. Set spins in up position.
             void flipSpin(); //flips the spin.
             int spinValue() const; //returns the spin value.
};
#endif

