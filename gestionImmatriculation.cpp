#include <iostream>
#include "Vehicule.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include "Proprietaire.h"

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

    // Vehicule de promenade
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Ajoutez un vehicule de promenade\n";
    std::cout << "-------------------------------------------------------\n";

    while (true) {
        std::cout << "Entrez le NIV du vehicule de promenade: ";
        std::getline(std::cin, niv);

        if (VinValidator::validerNiv(niv)) {
            break;
        }
        std::cout << "Ce numero de Serie n'est pas valide\n";
    }

    while (true) {
        std::cout << "Entrez l'immatriculation du vehicule de promenade: ";
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

    // Camion
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Ajoutez un camion\n";
    std::cout << "-------------------------------------------------------\n";

    while (true) {
        std::cout << "Entrez le NIV du camion: ";
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

    std::cout << "Entrez la capacite de charge du camion (en kg): ";
    std::cin >> poids;
    std::cin.ignore();

    std::cout << "Entrez le nombre d'essieux >= 2: ";
    std::cin >> nbEssieux;
    std::cin.ignore();

    Camion camion(niv, immatriculation, poids, nbEssieux);
    proprietaire.ajouterVehicule(camion);

    // Affichage des informations
    std::cout << "\nProprietaire\n";
    std::cout << proprietaire.reqProprietaireFormate() << std::endl;

    return 0;
}




/*#include <iostream>
#include "Vehicule.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include "Proprietaire.h"

int main() {
    std::string nom, prenom, niv, immatriculation;
    int nbPlaces, nbEssieux;
    double poids = 0.0;

    std::cout << "Entrez le nom du proprietaire: ";
    std::getline(std::cin, nom);

    std::cout << "Entrez le prenom du proprietaire: ";
    std::getline(std::cin, prenom);

    Proprietaire proprietaire(nom, prenom);

    // Vehicule de promenade
    std::cout << "Entrez le NIV du vehicule de promenade: ";
    std::getline(std::cin, niv);

    std::cout << "Entrez l'immatriculation du vehicule de promenade: ";
    std::getline(std::cin, immatriculation);

    std::cout << "Entrez le nombre de places du vehicule de promenade: ";
    std::cin >> nbPlaces;
    std::cin.ignore();

    VehiculePromenade vehiculePromenade(niv, immatriculation, nbPlaces);
    proprietaire.ajouterVehicule(vehiculePromenade);

    // Camion
    std::cout << "Entrez le NIV du camion: ";
    std::getline(std::cin, niv);

    std::cout << "Entrez l'immatriculation du camion: ";
    std::getline(std::cin, immatriculation);

    std::cout << "Entrez la capacite de charge du camion (en kg): ";
    std::cin >> nbEssieux;
    std::cin.ignore();

   std::cout << "Entrez le poids du camions: ";
    std::cin >> poids;
    std::cin.ignore();

    Camion camion(niv, immatriculation, poids, nbEssieux);
    proprietaire.ajouterVehicule(camion);

    // Affichage des informations
    std::cout << proprietaire.reqProprietaireFormate() << std::endl;

    return 0;
}

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <regex>*/

// Include your class declarations and other necessary code here

/*int main() {
    try {
        VehiculePromenade vp("3VWFE21C04M000001", "IFT 006", 7);
        std::cout << "VehiculePromenade created successfully." << std::endl;

        Camion c("3VWFE21C04M000001", "L032006", 6500, 3);
        std::cout << "Camion created successfully." << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
*/
/*int main() {
    std::string niv1 = "3VWFE21C04M000001";
    std::string niv2 = "1HTMKADN43H561298";

    if (VinValidator::validerNiv(niv1)) {
        std::cout << "NIV1 valide." << std::endl;
    } else {
        std::cout << "NIV1 invalide." << std::endl;
    }

    if (VinValidator::validerNiv(niv2)) {
        std::cout << "NIV2 valide." << std::endl;
    } else {
        std::cout << "NIV2 invalide." << std::endl;
    }

    return 0;
}
*/
