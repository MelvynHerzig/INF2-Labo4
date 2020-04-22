/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.cpp
 Auteur(s)   : Nicolas Crausaz, Melvyn Herzig, Quentin Forestier
 Date        : 22.04.2020

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */


#include "produit.h"
#include <iostream>     // std::cout
#include <iomanip>      // std::fixed, std::setprecision
#include "exceptions.h" // PrixNonValide

// Fonction non membre
void afficheEtThrowErreurPrix(const std::string& source, double PRIX_MINIMUM);


const double Produit::PRIX_MINIMUM = 0.05;

// Surcharge opérateur de flux <<
std::ostream& operator<<(std::ostream& os, const Produit& rhs)
{
   const short PRECISION_PRIX = 2;
   os << std::fixed << std::setprecision(PRECISION_PRIX);
   return os << "(" << rhs.no << ", \"" << rhs.libelle << "\", " << rhs.prix << ")";
}

// Constructeur
Produit::Produit(unsigned no, const std::string& libelle, double prix) : no(no), libelle(libelle)
{
   if (prix < PRIX_MINIMUM)
   {
      afficheEtThrowErreurPrix("Erreur dans Produit::Produit : ", PRIX_MINIMUM);
   }
   this->prix = prix;
}

// Accesseurs
double Produit::getPrix() const noexcept
{
   return prix;
}

void Produit::setPrix(double prix)
{
   if (prix < PRIX_MINIMUM)
   {
      afficheEtThrowErreurPrix("Erreur dans Produit::setPrix : ", PRIX_MINIMUM);
   }
   this->prix = prix;
}

// Opérateur d'affectation
Produit& Produit::operator=(Produit& rhs)
{
   if (&rhs == this) return *this; // En cas d'auto-assignation

   (unsigned&) no = rhs.no;
   (std::string&) libelle = rhs.libelle;
   (double&) prix = rhs.prix;
   return *this;
}

// Opérateur d'égalité
bool operator==(const Produit& lhs, const Produit& rhs)
{
   return lhs.no == rhs.no && lhs.libelle == rhs.libelle && lhs.prix == rhs.prix;
}

void afficheEtThrowErreurPrix(const std::string& source, double PRIX_MINIMUM) {
   std::cout << source << std::endl;
   std::string errMessage = (std::string) "le prix doit etre >= " +
                            std::to_string((unsigned) (PRIX_MINIMUM * 100)) +
                            (std::string) + " cts !";
   throw PrixNonValide(errMessage);
}
