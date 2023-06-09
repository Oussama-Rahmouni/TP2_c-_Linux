/**
 * @file FonctionsVehicule.cpp
 * @brief Implementation of the Vehicule class methods and VinValidator and ValidImma namespaces.
 */
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <unordered_map>

#include "Vehicule.h"
#include "Camion.h"
#include "VehiculePromenade.h"


using namespace std;
/**
 * @namespace VinValidator
 * @brief Contains utility functions for validating Vehicle Identification Numbers (VINs).
 */
namespace VinValidator {
    
/*int vin_weight(int position) {
    int weights[] = {8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3, 2};
    return weights[position];
}



int vin_char_value(char c) {
    if (isdigit(c)) {
        return c - '0';
    }
    if (c >= 'A' && c <= 'I') {
        return (c - 'A') + 1;
    }
    if (c >= 'J' && c <= 'R') {
        return (c - 'J') + 1;
    }
    if (c >= 'S' && c <= 'Z') {
        return (c - 'S') + 2;
    }
    return 0;
}
 
char calculate_check_digit(const std::string& p_niv) {
    int sum = 0;
    for (int i = 0; i < 17; ++i) {
        int weight = vin_weight(i);
        int char_value = vin_char_value(p_niv[i]);
        sum += weight * char_value;
        
    }
    int remainder = sum % 11;
    if (remainder == 10) {
        return 'X';
    }
    return remainder + '0';
}

int char_to_int(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 10;
    } else {
        return -1; // Return an error value if the character is not a valid digit or letter
    }
}
*/
bool validerNiv(const std::string& p_niv) {
    const int longueurNiv = 17;
    const int positionCheckDigit = 8;
    const std::unordered_map<char, int> transco = {
        {'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'E', 5}, {'F', 6}, {'G', 7}, {'H', 8},
        {'J', 1}, {'K', 2}, {'L', 3}, {'M', 4}, {'N', 5}, {'P', 7}, {'R', 9},
        {'S', 2}, {'T', 3}, {'U', 4}, {'V', 5}, {'W', 6}, {'X', 7}, {'Y', 8}, {'Z', 9},
        {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'0', 0}
    };
    const int poids[] = {8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3, 2};

    // Vérifier la longueur du NIV
    if (p_niv.length() != longueurNiv) {
        return false;
    }

    // Calculer le caractère de contrôle
    int somme = 0;
    for (int i = 0; i < longueurNiv; ++i) {
        char c = p_niv[i];
        if (transco.count(c) == 0) {
            return false;
        }
        somme += transco.at(c) * poids[i];
    }

    int check_digit = somme % 11;
    char check_char = (check_digit == 10) ? 'X' : '0' + check_digit;

    return p_niv[positionCheckDigit] == check_char;
}

}


/**
 * @namespace ValidImma
 * @brief Contains utility functions*/
namespace ValidImma 
{    
    
/**
 * @class Vehicule
 * @brief Represents a generic vehicle.
 */
bool validerImmatriculationCamion(const std::string& p_immatriculation) {
    
    std::string regex_pattern = "^[A-Z]\\d{6}$";
    
    std::regex regex_obj(regex_pattern);
    
    return std::regex_match(p_immatriculation, regex_obj);
}   

bool validerImmatriculationPromenade(const std::string& p_immatriculation) {
    bool estValide = true;

    std::string inputWithoutSpaces;
    for (char c : p_immatriculation) {
        if (c != ' ') {
            inputWithoutSpaces += c;
        }
    }

    if (inputWithoutSpaces.length() != 6) {
        estValide = false;
    } else {
        for (int i = 0; i < 3; i++) {
            if (!isupper(inputWithoutSpaces[i])) {
                estValide = false;
                break;
            }
        }
        for (int i = 3; i < 6; i++) {
            if (!isdigit(inputWithoutSpaces[i])) {
                estValide = false;
                break;
            }
        }
    }
    return estValide;
} 
}

/////////////// Vehicule methods
Vehicule::Vehicule(const std::string& niv, const std::string& immatriculation)
{
    if (VinValidator::validerNiv(niv)) {
        m_niv = niv;
        m_immatriculation = immatriculation;
    } else {
        throw std::runtime_error("NIV invalide");
   }
}
  
std::string Vehicule::getNiv() const 
{
    return m_niv;
}

std::string Vehicule::getImmatriculation() const 
{
    return m_immatriculation;
}

/*
void Vehicule::setImmatriculation(const std::string& p_immatriculation) {
    PRECONDITION(!p_immatriculation.empty());
    m_immatriculation = p_immatriculation;
    POSTCONDITION(m_immatriculation == p_immatriculation);
    INVARIANT(!m_niv.empty());
}
*/
 
void Vehicule::verifieInvariant() const 
{
    INVARIANT(!m_niv.empty());
    INVARIANT(!m_immatriculation.empty());
}

bool Vehicule::operator==(const Vehicule& autre) const
{
    return m_immatriculation == autre.m_immatriculation &&
           m_niv == autre.m_niv;
}

Proprietaire::Proprietaire(const std::string& p_nom, const std::string& p_prenom)
        : m_nom(p_nom), m_prenom(p_prenom) {};

