/*#include <iostream>
#include "VehiculePromenade.h"
#include "ContratException.h"

using namespace std;

void testConstructor() {
  string niv = "1M8GDM9AXKP042788";
  string immatriculation = "XYZ 123";
  int nbPlaces = 5;

  PRECONDITION(VinValidator::validerNiv(niv));
  PRECONDITION(ValidImma::validerImmatriculationPromenade(immatriculation));
  PRECONDITION(nbPlaces > 0);

  VehiculePromenade vehicule(niv, immatriculation, nbPlaces);

  POSTCONDITION(vehicule.getNiv() == niv);
  POSTCONDITION(vehicule.getImmatriculation() == immatriculation);
  POSTCONDITION(vehicule.getNbPlaces() == nbPlaces);
}

int main() {
  try {
    testConstructor();
    cout << "VehiculePromenade_Testeur: Tests completed successfully." << endl;
  } catch (const ContratException& e) {
    cerr << "VehiculePromenade_Testeur: " << e.reqTexteException() << endl;
  }

  return 0;
}
*/