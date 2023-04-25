#ifndef INTERFACE_H
#define INTERFACE_H
#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "ContratException.h"

/**
 * @brief Espace de noms pour les fonctions de validation du NIV (Numéro d'Identification du Véhicule).
 */
namespace VinValidator 
{
    bool validerNiv(const std::string& p_niv);
    char calculate_check_digit(const std::string& p_niv);
    int vin_weight(int position);
    int vin_char_value(char c);
}

/**
 * @brief Espace de noms pour les fonctions de validation d'immatriculation.
 */
namespace ValidImma 
{
    bool validerImmatriculationPromenade(const std::string& p_immatriculation);
    bool validerImmatriculationCamion(const std::string& p_immatriculation);
}

/**
 * @brief Classe représentant un véhicule générique.
 */
class Vehicule 
{
/**
     * @brief Constructeur de la classe Vehicule.
     * 
     * @param p_niv Le numéro d'identification du véhicule (NIV).
     * @param p_immatriculation Le numéro d'immatriculation du véhicule.
     */    
public:
    Vehicule(const std::string& p_niv, const std::string& p_immatriculation);
    
    std::string getNiv() const;
    std::string getImmatriculation() const;
    //std::string setNiv(std::string& p_niv);
    //void setImmatriculation(const std::string& p_immatriculation);
    
    bool operator==(const Vehicule& autre) const;

    virtual ~Vehicule() = default;

    virtual std::unique_ptr<Vehicule> clone ()const = 0;

    virtual double tarificationAnnuelle()const = 0;
    
    virtual std::string reqVehiculeFormate() const 
 {
        std::ostringstream oss;
        oss << "Numero de serie : " << Vehicule::getNiv() << std::endl
            << "Numero d'immatriculation : " << Vehicule::getImmatriculation() << std::endl;
        return oss.str();
 }
     
   void verifieInvariant() const;
   
protected:
    std::string m_niv;
    std::string m_immatriculation;
    virtual void assignerImmatriculation(const std::string& p_immatriculation) = 0; //hedhi tnajem tkoun feha definition kima fl req format
};

/**
 * @brief Classe représentant le proprietaire.
 */
class Proprietaire {
    /**
     * @brief Constructeur de la classe Proprietaire.
     * 
     * @param m_nom Le nom.
     * @param m_prenom Le prenom.
     */ 
private:
    std::string m_nom;
    std::string m_prenom;
    std::vector<std::unique_ptr<Vehicule>> m_vehicules;    

public:
    Proprietaire(const std::string& p_nom, const std::string& p_prenom);
      
    std::string getNom() const { return m_nom; };
    std::string getPrenom() const { return m_prenom; };
    int getNombreVehicules() const { return m_vehicules.size(); };

    std::string reqProprietaireFormate() {
        std::stringstream ss;
        ss << "Proprietaire\n"
           << "-------------------\n"
           << "Nom : " << m_nom << "\n"
           << "Prenom : " << m_prenom << "\n"
           << "-------------------\n";

        for (const auto& vehicule : m_vehicules) {
            ss << vehicule->reqVehiculeFormate() << "\n";}        
        return ss.str();
    }

    void ajouterVehicule(const Vehicule& p_nouveauVehicule) {
        m_vehicules.push_back(p_nouveauVehicule.clone());}
    
 
    Proprietaire(const Proprietaire& other)
        : m_nom(other.m_nom), m_prenom(other.m_prenom) {
        for (const auto& vehicule : other.m_vehicules) {
            m_vehicules.push_back(vehicule->clone());
        }
    }

    Proprietaire& operator=(const Proprietaire& other) {
        if (this == &other) {
            return *this;
        }

        m_nom = other.m_nom;
        m_prenom = other.m_prenom;
        m_vehicules.clear();

        for (const auto& vehicule : other.m_vehicules) {
            m_vehicules.push_back(vehicule->clone());
        }
        return *this;
    }
};

#endif /* INTERFACE_H */

