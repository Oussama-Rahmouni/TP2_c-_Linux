

#ifndef VEHICULEPROMENADE_H
#define VEHICULEPROMENADE_H
#pragma once


#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "Vehicule.h"
#include "ContratException.h"

/**
 * @brief Classe représentant un véhicule de promenade.
 */
class VehiculePromenade : public Vehicule {

/**
     * @brief Constructeur de la classe VehiculePromenade.
     * 
     * @param p_niv Le numéro d'identification du véhicule (NIV).
     * @param p_immatriculation Le numéro d'immatriculation du véhicule.
     * @param p_nbPlaces Le nombre de places dans le véhicule de promenade.
     */  
public:
    VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces);
    
    int getNbPlaces() const;
    //int setNbPlaces(int& p_nbPlaces);
    
    double tarificationAnnuelle() const override ;

    
    std::unique_ptr<Vehicule> clone() const override {
    return std::unique_ptr<Vehicule>(new VehiculePromenade(*this));
}

    std::string reqVehiculeFormate() const override;
    
private:
    int m_nbPlaces;

protected:
    virtual void assignerImmatriculation(const std::string& p_immatriculation) override;
};

#endif /* VEHICULEPROMENADE_H */

