/**
 * @file FonctionsVehicule.cpp
 * @brief Implementation of the Vehicule class methods and VinValidator and ValidImma namespaces.
 */
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include "Vehicule.h"
#include "Camion.h"
#include "VehiculePromenade.h"


using namespace std;
/**
 * @namespace VinValidator
 * @brief Contains utility functions for validating Vehicle Identification Numbers (VINs).
 */
namespace VinValidator {
    
int vin_weight(int position) {
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
        std::cout << "Position: " << i
                  << ", Weight: " << weight
                  << ", Char Value: " << char_value
                  << ", Sum: " << sum << std::endl;
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

bool validerNiv(const std::string& p_niv) {
    int len = p_niv.length();
    if (len != 17) {
        std::cout << "NIV length is incorrect." << std::endl;
        return false;
    }
    char check_digit = VinValidator::calculate_check_digit(p_niv);
    if (p_niv[8] != check_digit && p_niv[9] != check_digit) {
        std::cout << "NIV check digit is incorrect. Expected: " << check_digit << ", Found: " << p_niv[8] << " or " << p_niv[9] << std::endl;
        return false;
    }
   unsigned int sum = 0;
for (size_t i = 0; i < p_niv.size(); ++i) {
    int char_value = char_to_int(p_niv[i]);
    int weight = vin_weight(i);
    sum += char_value * weight;
    std::cout << "Position: " << i << ", Char: " << p_niv[i] << ", Char Value: " << char_value << ", Weight: " << weight << ", Sum: " << sum << std::endl;
}

    return true;
}

}

/**
 * @namespace ValidImma
 * @brief Contains utility functions*/
namespace ValidImma 
{    

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

/**
 * @class Vehicule
 * @brief Represents a generic vehicle.
 */
bool validerImmatriculationCamion(const std::string& p_immatriculation) {
    
    std::string regex_pattern = "^[A-Z]{3}\\d{3}$";
    
    std::regex regex_obj(regex_pattern);
    
    return std::regex_match(p_immatriculation, regex_obj);
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

