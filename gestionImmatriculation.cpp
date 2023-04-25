#include <iostream>
#include "Vehicule.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include "Proprietaire.h"

/**
 * @file gestionImmatriculation.cpp
 * @brief Implementation of the main function to demonstrate the use of Vehicule, Camion, VehiculePromenade and Proprietaire classes.
 */
int main() {
    std::string nom, prenom, niv, immatriculation;
    int nbPlaces, nbEssieux;
    double poids = 0.0;

    std::cout << "Bienvenue a l'outil d'ajout de gestion de vehicules\n\n";
    std::cout << "*******************************************************\n\n";

    std::cout << "Entrez le nom du proprietaire: ";
    std::getline(std::cin, nom);

    std::cout << "Entrez le prenom du proprietaire: ";
    std::getline(std::cin, prenom);

    Proprietaire proprietaire(nom, prenom);

    std::cout << "-------------------------------------------------------\n";
    std::cout << "Ajoutez un vehicule de promenade\n";
    std::cout << "-------------------------------------------------------\n";

    while (true) {
        std::cout << "Entrez le numero de serie du vehicule de promenade: ";
        std::getline(std::cin, niv);

        if (VinValidator::validerNiv(niv)) {
            break;
        }
        std::cout << "Ce numero de Serie n'est pas valide\n";
    }

    while (true) {
        std::cout << "Entrez le numero d'immatriculation : ";
        std::getline(std::cin, immatriculation);

        if (ValidImma::validerImmatriculationPromenade(immatriculation)) {
            break;
        }
        std::cout << "Le numero d'immatriculation n'est pas valide.\n";
    }

    std::cout << "Entrez le nombre de places du vehicule de promenade: ";
    std::cin >> nbPlaces;
    std::cin.ignore();

    VehiculePromenade vehiculePromenade(niv, immatriculation, nbPlaces);
    proprietaire.ajouterVehicule(vehiculePromenade);

    std::cout << "-------------------------------------------------------\n";
    std::cout << "Ajoutez un camion\n";
    std::cout << "-------------------------------------------------------\n";

    while (true) {
        std::cout << "Entrez le numero de serie du camion: ";
        std::getline(std::cin, niv);

        if (VinValidator::validerNiv(niv)) {
            break;
        }
        std::cout << "Ce numero de Serie n'est pas valide\n";
    }

    while (true) {
        std::cout << "Entrez l'immatriculation du camion: ";
        std::getline(std::cin, immatriculation);

        if (ValidImma::validerImmatriculationCamion(immatriculation)) {
            break;
        }
        std::cout << "Le numero d'immatriculation n'est pas valide.\n";
    }

    std::cout << "Entrez le poids du camion > 3000 kg : ";
    std::cin >> poids;
    std::cin.ignore();

    std::cout << "Entrez le nombre d'essieux >= 2: ";
    std::cin >> nbEssieux;
    std::cin.ignore();

    Camion camion(niv, immatriculation, poids, nbEssieux);
    proprietaire.ajouterVehicule(camion);

    std::cout << "\nProprietaire\n";
    std::cout << proprietaire.reqProprietaireFormate() << std::endl;

    return 0;
}
