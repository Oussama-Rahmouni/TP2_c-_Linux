/*#include <iostream>
#include <string>
#include <limits>

#include "Vehicule.h"
//#include "ContratException.h"
//#include "Proprietaire.h"
#include "Camion.h"
#include "VehiculePromenade.h"

/**
 * @file Vehicule.cpp
 * @brief Implementation of the main function to demonstrate the use of Vehicule, Camion, and VehiculePromenade classes.
 */
/*int main() {
    std::string niv, immatriculation;
    int nbPlaces, nbEssieux;
    double poids;

  
    std::cout << "Ajoutez un vehicule de promenade" << std::endl;

    do {
        std::cout << "Entrez le numero de serie: "<< std::flush;
        std::cin >> niv;
    } while (!VinValidator::validerNiv(niv));
       
    do {
       std::cout << "Entrez le numero d'immatriculation: " << std::flush;
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       std::getline(std::cin, immatriculation);
   } while (!ValidImma::validerImmatriculationPromenade(immatriculation));
   

   do {
        std::cout << "Entrez le nombre de places > 0: ";
        std::cin >> nbPlaces;
    } while (nbPlaces <= 0);

    VehiculePromenade voiture(niv, immatriculation, nbPlaces);

    
    std::cout << "\nAjoutez un camion\n" << std::endl;

  do {
        std::cout << "Entrez le numero de serie: ";
        std::cin >> niv;
   } while (!VinValidator::validerNiv(niv));

   do {
        std::cout << "Entrez le numero d'immatriculation: ";
        std::cin >> immatriculation;
   } while (!ValidImma::validerImmatriculationCamion(immatriculation));

   do {
        std::cout << "Entrez le poids du camion > 3000 kg: ";
        std::cin >> poids;
   } while (poids <= 3000);

   do {
        std::cout << "Entrez le nombre d'essieux >= 2: ";
        std::cin >> nbEssieux;
   } while (nbEssieux < 2);

    Camion camion(niv, immatriculation, poids, nbEssieux);

    
    std::cout << "\nProprietaire\n" << std::endl;
    std::cout << "Nom : hajar" << std::endl;
    std::cout << "Prenom : kadouri\n" << std::endl;

    std::cout << voiture.reqVehiculeFormate() << std::endl;
    std::cout << camion.reqVehiculeFormate() << std::endl;

    return 0;
}
*/