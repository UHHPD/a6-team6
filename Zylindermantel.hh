#ifndef ZYLINDERMANTEL_HH
#define ZYLINDERMANTEL_HH

#include "Koerper.hh"
#include "Vektor.hh"

class Zylindermantel: public Koerper{
public:
  std:: string name();
  Zylindermantel(double nr, double nl);

  Vektor punkt();

private:
  double r_, l_;
};

#endif
