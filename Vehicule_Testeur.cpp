/*#include <iostream>
#include "Vehicule.h"
#include "ContratException.h"

using namespace std;

void testConstructor() {
  string niv = "1M8GDM9AXKP042788";
  string immatriculation = "XYZ 123";
  
  PRECONDITION(VinValidator::validerNiv(niv));
  PRECONDITION(ValidImma::validerImmatriculationPromenade(immatriculation));

  Vehicule vehicule(niv, immatriculation);
  
  POSTCONDITION(vehicule.reqNiv() == niv);
  POSTCONDITION(vehicule.reqImmatriculation() == immatriculation);
}

int main() {
  try {
    testConstructor();
    cout << "Le test est reussir" << endl;
  } catch (const ContratException& e) {
    cerr << "Vehicule_Testeur: " << e.reqTexteException() << endl;
  }

  return 0;
}
*/