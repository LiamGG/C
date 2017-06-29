#define LOOPNUMBER 4
#define TEMPMAX 5
#define MCS 100000
#include "stats.h"
#include "IsingSystem.h"
#include "IsingParticle.h"
#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std; 

int main() {
    IsingParticle p;
    cout << "The original spin is " << p.spinValue() << endl;
    p.flipSpin();
    cout << "The flipped spin is " << p.spinValue() << endl;
    IsingSystem model;
    model.print();
    cout << "The magnetisation is: " << model.magnetisation() << endl;
    cout << "The total energy is: " << model.totalEnergy() << endl;
    for (int i = 0; i<LOOPNUMBER; i++){
        model.choose();
        cout << "The local energy is  "<< model.localEnergy() << endl;
        model.perturb();
        cout << "The local energy is now "<< model.localEnergy() << endl;
    }
    model.print();
    cout << "The magnetisation is: " << model.magnetisation() << endl;
    cout << "The total energy is now: " << model.totalEnergy() << endl;
    cout << endl << endl << endl << endl << endl;
      
       
    cout << "Using the Metropolis algorithm:" << endl << endl;

    IsingSystem met;
    double T, before, after, change, r, Cv;
    FILE *output;
    FILE *shc;
    if ((output = fopen("mag_results.csv", "w")) == NULL )
    {
              printf("The file 'mag_results.csv' could not be accessed.\n");
              system("Pause");
              return 0;
    }
    if ((shc = fopen("heat_capacity.csv", "w")) == NULL )
    {
              printf("The file 'heat_capacity.csv' could not be accessed.\n");
              system("Pause");
              return 0;
    }
    
    fprintf(output, "Temperature, Magnetisation\n");
    fprintf(shc, "Temperature, Specific Heat Capacity\n");
    statistics MAGstats;
    statistics ENGstats;
    met.print();
    for (T = 0; T < TEMPMAX; T += 0.05) {
       // cout << "For temperature: " << T << endl;
        for (int i = 0; i < MCS; i++) {
            met.choose();
            before = met.localEnergy();
            met.perturb();
            after = met.localEnergy();
            change = after - before;
            r = ((double)rand() / RAND_MAX);
            if (r >= exp(-change/T)) met.perturb();
            if (i > MCS/2 && (i%(ISINGSIZE*ISINGSIZE) == 0)) MAGstats.add(met.magnetisation()); 
            if (i > MCS/2 && (i%(ISINGSIZE*ISINGSIZE) == 0)) ENGstats.add(met.totalEnergy());  
            }  
        if (T == 2.3) met.print();
        if (T == 4.5) met.print();    
        if (T == 1) met.print();
        
    cout << "Average Magnetisation: " << MAGstats.getAverage() << endl << endl;
    fprintf(output, "%lf, %lf\n", T, MAGstats.getAverage());
    Cv = (ENGstats.getSqAverage() - (ENGstats.getAverage() * ENGstats.getAverage()) )/ ((ISINGSIZE*ISINGSIZE)*T*T);
    fprintf(shc, "%lf, %lf\n", T, Cv);
    MAGstats.reset();
    ENGstats.reset();
    }
    system("Pause");
};

