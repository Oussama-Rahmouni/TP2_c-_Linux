/**
 * @file FonctionsVehiculePromenade.cpp
 * @brief Implementation of the VehiculePromenade class methods.
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
 * @class VehiculePromenade
 * @brief Represents a passenger vehicule.
 */
VehiculePromenade::VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces): Vehicule (p_niv, p_immatriculation)
{
   if (VinValidator::validerNiv(p_niv) && ValidImma::validerImmatriculationPromenade(p_immatriculation) && p_nbPlaces > 0 )
      {
        m_niv = p_niv;
        m_immatriculation = p_immatriculation;
        m_nbPlaces = p_nbPlaces;
     } else { throw std::runtime_error("NIV ou Immatriculation ou nb places invalide"); }
};

int VehiculePromenade::getNbPlaces() const
{
    return m_nbPlaces;
}

void VehiculePromenade::assignerImmatriculation(const std::string& p_immatriculation) {
    PRECONDITION (ValidImma::validerImmatriculationPromenade(p_immatriculation))
         { m_immatriculation = p_immatriculation;}
    POSTCONDITION (m_immatriculation == p_immatriculation);
    INVARIANT(!m_niv.empty());
    INVARIANT(!m_immatriculation.empty());
}

double VehiculePromenade::tarificationAnnuelle() const {
    return 232.74;
}

std::string VehiculePromenade::reqVehiculeFormate() const {
    std::ostringstream oss;
    oss << Vehicule::reqVehiculeFormate()
        << "Nombre de places : " << m_nbPlaces << std::endl
        << "Tarif :" << VehiculePromenade::tarificationAnnuelle() << std::endl;
    return oss.str();
}