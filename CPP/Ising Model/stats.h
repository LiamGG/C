#ifndef STATS_H
#define STATS_H
#include <cstdlib>


class statistics {
      private:
              int n;
              double sum;
              double sumsq;
      public:
             statistics();
             int getNumber() const;
             double getAverage() const;
             double getSqAverage() const;
             void add(double x);
             void reset();
};


statistics::statistics() {
                         n=0;
                         sum=0.0;
                         sumsq=0.0;
};

int statistics::getNumber() const {
    return n;
};

double statistics::getAverage() const {
       if(n==0) return 0.0;
       return sum/n;
};

double statistics::getSqAverage() const {
       if(n==0) return -1;
       return sumsq/n;
};

void statistics::add(double x) {
     n++;
     sum += x;
     sumsq += x*x;
};

void statistics::reset() {
     n = 0;  sum = 0.0;  sumsq = 0.0;
};

#endif

