/**
 * @file FonctionsCamion.cpp
 * @brief Implementation of the Camion class methods.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include "Vehicule.h"
#include "Camion.h"
#include "VehiculePromenade.h"

using namespace VinValidator;
using namespace ValidImma;

/**
 * @class Camion
 * @brief Represents a truck vehicle.
 */
Camion::Camion(const std::string& p_niv, const std::string& p_immatriculation, double p_poids, int p_nbEssieux): Vehicule (p_niv, p_immatriculation)
{
if (!VinValidator::validerNiv(p_niv)) {
    throw std::runtime_error("Invalid NIV");
}
if (!ValidImma::validerImmatriculationCamion(p_immatriculation)) {
    throw std::runtime_error("Invalid Immatriculation");
}
if (p_poids <= 3000) {
    throw std::runtime_error("Invalid Poids");
}
if (p_nbEssieux < 2) {
    throw std::runtime_error("Invalid NbEssieux");
}

m_niv = p_niv;
m_immatriculation = p_immatriculation;
m_poids = p_poids;
m_nbEssieux = p_nbEssieux;

}

double Camion::getPoids() const 
{
    return m_poids;
}
int Camion::getNbEssieux() const 
{
    return m_nbEssieux;
}

void Camion::assignerImmatriculation(const std::string& p_immatriculation) {
    PRECONDITION (ValidImma::validerImmatriculationCamion(p_immatriculation))
         { m_immatriculation = p_immatriculation;}
    POSTCONDITION (m_immatriculation == p_immatriculation);
    INVARIANT(!m_niv.empty());
    INVARIANT(!m_immatriculation.empty());
}

double Camion::tarificationAnnuelle() const {
    double tarif = 0.0;
    if (m_poids < 4000) {
        tarif = 570.28;
    } else {
        tarif = 905.28 + (m_nbEssieux - 4) * 100.0 + (m_poids - 4000) * 0.4011;
    }
    return tarif;
}

std::string Camion::reqVehiculeFormate() const {
    std::ostringstream oss;
    oss << Vehicule::reqVehiculeFormate()
        << "nombre d'essieux  : " << Camion::getNbEssieux() << std::endl
        << "poids :" << Camion::getPoids() <<std::endl
        << "tarif :" << Camion::tarificationAnnuelle()<< std::endl;
    return oss.str();
}