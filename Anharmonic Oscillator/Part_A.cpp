#include <iostream>
#include "stdlib.h"
#define k 1
#define m 1

double F(const double &x){
       return -(k*x)/m;
}

double xder(const double &t, const double &x, const double &v){
       return v;
       }
       
double vder(const double &t, const double &x, const double &v) {
       return F(x)/m;
       }


void stepRK4(double &t, double &x, double &v, const double &dt) {
      
 double k1x=dt*xder(t, x, v);
 double k1v=dt*vder(t, x, v);
 
 double k2x=dt*xder(t+dt/2, x+k1x/2, v+k1v/2);
 double k2v=dt*vder(t+dt/2, x+k1x/2, v+k1v/2);
 
 double k3x=dt*xder(t+dt/2, x+k2x/2, v+k2v/2);
 double k3v=dt*vder(t+dt/2, x+k2x/2, v+k2v/2);

 double k4x=dt*xder(t+dt, x+k3x, v+k3v);
 double k4v=dt*vder(t+dt, x+k3x, v+k3v);
 
 t+=dt;
 x+=(k1x/6) + (k2x/3) + (k3x/3) + (k4x/6);
 v+=(k1v/6) + (k2v/3) + (k3v/3) + (k4v/6);
}


int main(){
    
//Variable initial declarations    
    double t = 0;
 // Changed for A3  double x = 0.5;
    
 // Crossed out for A3   double v = 0;
    double dt = 0.1;
    //A2
    double kin = 0;
    double pot = 0;
    double tot_en = 0;
    FILE *output;
    
    if((output = fopen("harmonic_oscillations_a3fixed.csv","w")) == NULL){
               std::cout << "Could not access the output file" << std::endl;
               system("pause");
               return 0;
    }
    
    
//Start RK4 method
    
    
    for(int N=0; N<=10; N++){
            double x = 0; 
            double v0 = 0.1;
            double v = N * v0;
            t=0;
            fprintf(output, "t, x, v, K, V, E\n");
    
    for(int i=0; i<=650; i++){
            stepRK4(t, x, v, dt);
            
            kin = 0.5*m*(v*v);
            pot = 0.5*k*(x*x);
            tot_en = kin + pot;
            
// This loop used to minimise time to find final energy after 1000 osciallations    if(i==650000){
            
            std::cout << "x(" << i << ")=" << x << "   ";
            std::cout << "v(" << i << ")=" << v << "   ";
            std::cout << "K(" << i << ")=" << kin << "   ";
            std::cout << "V(" << i << ")=" << pot << "   ";
            std::cout << "E(" << i << ")=" << tot_en << "   ";
            std::cout << "t(" << i << ")=" << t << std::endl;
            
            
            fprintf(output, "%lf, %lf, %lf, %lf, %lf, %lf\n", t, x, v, kin, pot, tot_en);
//   }
            }
            }
            
    fclose(output);
            
            
            
    system("pause");
    return 0;
}
