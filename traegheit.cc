#include "Vektor.hh"
#include "Koerper.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

double K_M= 1.0;
const int N= 1000;
double traegheit(Koerper*k, Vektor a, Vektor u){
  double K_J=0;
  double K_m = (double)K_M/N;
  for (int i=0 ; i < N ; ++i){
    Vektor x = k->punkt();
   Vektor n = (x-a).kreuz(u);
   double r = n.betrag()/u.betrag();
   K_J += K_m * r * r;

  }
  std::cout << "Traegheitsmoment" << k->name()<< "\n";
  return K_J;

}

int main() {
  const double M = 1;      // Masse des Zylindermantels
  const double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels
  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  const double VZ_L = 1.0;
  int VZ_R;
  std:: cout<< "Radius";
  std:: cin>> VZ_R;
  int VZ_M;
  std:: cout<< "Masse";
  std:: cin>> VZ_M;


  

  std::unique_ptr<Zylindermantel> zm(new Zylindermantel(ZM_R, ZM_L));

  double J = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = zm->punkt();
    // Abstand Punkt x und Gerade a + t*u
    // Vektor n = ...;//Normalenvektor x-a kreuz u
    Vektor n = (x-a).kreuz(u);
    double r = n.betrag()/u.betrag() ;//|n|/|u|
    // std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;
            


 std::unique_ptr<Vollzylinder> vz(new Vollzylinder(VZ_R, VZ_L));
 
 double VZ_J = 0;
 double VZ_m = (double)VZ_M/N;
 for( int i=0;i<N;++i){
   Vektor x = vz->punkt();
   Vektor n = (x-a).kreuz(u);
   double r = n.betrag()/u.betrag();
   VZ_J += VZ_m * r * r;
 }
 std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            << " mit a = " << a << " und u = " << u << ": " << VZ_J<< std::endl;

 std::unique_ptr<Koerper> k(new Zylindermantel(ZM_R,ZM_L));
 double Jtest= traegheit(k.get(),a,u);
 std::cout<< Jtest <<std::endl;

std::unique_ptr<Koerper> k2(new Vollzylinder(VZ_R, VZ_L));
 double Jtest2= traegheit(k2.get(),a,u);
 std::cout<< Jtest2 <<std::endl;



}


          


