
#ifndef CAMION_H
#define CAMION_H
#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "Vehicule.h"
#include "ContratException.h"

class Vehicule;

/**
 * @brief Classe représentant un camion.
 */
class Camion : public Vehicule 
{
    /**
     * @brief Constructeur de la classe Camion.
     * 
     * @param p_niv Le numéro d'identification du véhicule (NIV).
     * @param p_immatriculation Le numéro d'immatriculation du véhicule.
     * @param p_poids Le poids du camion.
     * @param p_nbEssieux Le nombre d'essieux du camion.
     */
public:
    Camion(const std::string& p_niv, const std::string& p_immatriculation, double p_poids, int p_nbEssieux);
    double getPoids() const;
    int getNbEssieux() const;
    //double setPoids(double& p_poids);
    //int setNbEssieux(int& m_nbEssieux);

    double tarificationAnnuelle() const override ; //verifier commenct calculer le tarif 
    
   std::unique_ptr<Vehicule> clone() const override {
    return std::unique_ptr<Vehicule>(new Camion(*this));
}

    std::string reqVehiculeFormate() const override;
    
private:
    double m_poids;
    int m_nbEssieux;
    
protected:
    virtual void assignerImmatriculation(const std::string& p_immatriculation) override;
};

#endif /* CAMION_H */

