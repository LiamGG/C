#include <iostream>
#include <cmath>
#include <cstdlib>
#include "IsingParticle.h"


using namespace std;

IsingParticle::IsingParticle() {  spin = 1;  }
void IsingParticle::flipSpin() { spin *= -1; }
int IsingParticle::spinValue() const {  return spin; }
