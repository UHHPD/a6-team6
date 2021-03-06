#include "Zylindermantel.hh"

#include <cmath>
#include <cstdlib>

Zylindermantel::Zylindermantel(double nr, double nl) {
  r_ = nr;
  l_ = nl;
}

std::string Zylindermantel::name(){
  return "Zylindermantel";
}

Vektor Zylindermantel::punkt() {
  double R = r_;
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double z = l_ * (rand() / (double)RAND_MAX - 0.5);

  double x = r_*cos(phi);
  double y = r_*sin(phi);
  return Vektor(x, y, z);
};
