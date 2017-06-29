#include <iostream>
#define ISINGSIZE 32
#include <cmath>
#include <cstdlib>
#include "IsingSystem.h"
#include "IsingParticle.h"

using namespace std;
 
IsingSystem::IsingSystem() {
                         current_column = 0;     current_row = 0;
                         left_column = 0;        right_column = 0;                         
                         up_row = 0;             down_row = 0;
};
                         
void IsingSystem::choose() {
      current_column = rand() % (ISINGSIZE);
      current_row = rand() % (ISINGSIZE);
      
   //   cout << "\nThe coordinates are :( " << current_column << " " << current_row << " ) " << endl;
};

void IsingSystem::perturb() {
    // cout << "Spin before: " << particles[current_column][current_row].spinValue() << endl;
     particles[current_column][current_row].flipSpin();
    // cout << "Spin after: "<< particles[current_column][current_row].spinValue() << endl;
}; 

void IsingSystem::print() {
     cout << endl;
     cout << endl;
     for (int p_row = 0; p_row < ISINGSIZE; p_row++) 
     {
         for (int p_col = 0; p_col < ISINGSIZE; p_col++) 
         {
             if(particles[p_col][p_row].spinValue() == 1)
             {
                 cout << "+ ";
             }
             else
             {
                 cout << "- ";
             }
         }
         cout << endl;
    
     }
     cout << endl;
};        

void IsingSystem::find_neighbours() {
     left_column = (current_column==0) ? ISINGSIZE-1 : current_column-1;
     right_column = (current_column==(ISINGSIZE-1)) ? 0 : current_column+1;
     up_row = (current_row==0) ? ISINGSIZE-1 : current_row-1;
     down_row = (current_row==(ISINGSIZE-1)) ? 0 : current_row+1;
}; 

double IsingSystem::localEnergy() {
       find_neighbours();
       int energy_l = (particles[current_column][current_row].spinValue()) * (particles[left_column][current_row].spinValue());
       int energy_r = (particles[current_column][current_row].spinValue()) * (particles[right_column][current_row].spinValue());
       int energy_u = (particles[current_column][current_row].spinValue()) * (particles[current_column][up_row].spinValue());
       int energy_d = (particles[current_column][current_row].spinValue()) * (particles[current_column][down_row].spinValue());
       return -(energy_l + energy_r + energy_u + energy_d );
};

double IsingSystem::magnetisation() {
       double totalSpin = 0;
       for (int p_row = 0; p_row < ISINGSIZE; p_row++)
       {
           for (int p_col = 0; p_col < ISINGSIZE; p_col++)
           {
               totalSpin += particles[p_col][p_row].spinValue();
           }
       }
       return fabs(totalSpin / (ISINGSIZE * ISINGSIZE));
};
       
double IsingSystem::totalEnergy() {
       double total = 0;
       for (current_row = 0; current_row < ISINGSIZE; current_row++)
       {
           for (current_column = 0; current_column < ISINGSIZE; current_column++)
           {
               total += localEnergy();
           }
       }
       return total/2;
};
