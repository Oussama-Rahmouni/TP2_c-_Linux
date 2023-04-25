#ifndef PROPRIETAIRE_H
#define PROPRIETAIRE_H

/**
 * @file Proprietaire.h
 * @brief Header file for the Proprietaire class which represents the owner of the vehicles.
 */
#include <string>
#include <vector>
#include <memory>
#include "Vehicule.h"

namespace saaq {
    /**
     * @class Proprietaire
     * @brief Represents the owner of vehicles, containing their name, surname, and a list of their vehicles.
     */
    class Proprietaire {
    public:
        Proprietaire(const std::string& p_nom, const std::string& p_prenom);
        Proprietaire(const Proprietaire&) = default;
        Proprietaire& operator=(const Proprietaire&) = default;

        std::string getNom() const;
        std::string getPrenom() const;
        size_t getNbVehicules() const;

        std::string reqProprietaireFormate() const;
        void ajouterVehicule(const Vehicule& p_nouveauVehicule);

    private:
        std::string m_nom;
        std::string m_prenom;
        std::vector<std::unique_ptr<Vehicule>> m_vehicules;

        void verifieInvariant() const;
    };
}

#endif // PROPRIETAIRE_H
