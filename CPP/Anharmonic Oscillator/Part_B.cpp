#include <iostream>
#include "stdlib.h"
#include <cmath>

#define l 9.8
#define g 9.8

// a = theta
double ader(const double &t, const double &a, const double &w){
       return w;
       }
       
double wder(const double &t, const double &a, const double &w) {
       return -(g/l)*sin(a);
       }


void stepRK4(double &t, double &a, double &w, const double &dt) {
      
 double k1a=dt*ader(t, a, w);
 double k1w=dt*wder(t, a, w);
 
 double k2a=dt*ader(t+dt/2, a+k1a/2, w+k1w/2);
 double k2w=dt*wder(t+dt/2, a+k1a/2, w+k1w/2);
 
 double k3a=dt*ader(t+dt/2, a+k2a/2, w+k2w/2);
 double k3w=dt*wder(t+dt/2, a+k2a/2, w+k2w/2);

 double k4a=dt*ader(t+dt, a+k3a, w+k3w);
 double k4w=dt*wder(t+dt, a+k3a, w+k3w);
 
 t+=dt;
 a+=(k1a/6) + (k2a/3) + (k3a/3) + (k4a/6);
 w+=(k1w/6) + (k2w/3) + (k3w/3) + (k4w/6);
}


int main(){
    
//Variable initial declarations    
    double t=0;
    //double a=0.5;
    //double w=0;
    double w0 = 0.3;
    double dt=0.05;
    
    FILE *output;
    
    if((output = fopen("partb-results_b3-adjust.csv","w")) == NULL){
               std::cout << "Could not access the output file" << std::endl;
               system("pause");
               return 0;
    }
    
    
//Start RK4 method
    
 // change to adjust results for loop   for(int N = 0; N<=10; N++){
    for(int N = 7; N<=10; N++){
            t = 0;
            double a = 0;
            double w = N * w0;
            
    fprintf(output, "t, a, w\n");
    
    for(int i=0; i<=1000; i++){
            stepRK4(t, a, w, dt);
            if(a>M_PI){
                       a=a-(2*M_PI);
            }
            fprintf(output, "%lf, %lf, %lf\n", t, a, w);
    }
    }   
    fclose(output);
                    
    system("pause");
    return 0;
} 
