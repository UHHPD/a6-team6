#ifndef VOLLZYLINDER_HH
#define VOLLZYLINDER_HH
#include "Koerper.hh"
#include "Vektor.hh"

class Vollzylinder : public Koerper{
public:
  std:: string name();
  Vollzylinder(double nr, double nl);

  Vektor punkt();
  

private:
  double r_, l_;
};

#endif
