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

const double Produit::PRIX_MINIMUM = 0.05;

// Vérification du prix, lance une erreur PrixNonValide en cas d'erreur
void verificationPrix(double prix, const std::string& source)
{
   if (prix < Produit::PRIX_MINIMUM)
   {
      std::cout << source << std::endl;
      std::string errMessage = (std::string) "le prix doit etre >= " +
                               std::to_string((unsigned) (Produit::PRIX_MINIMUM * 100)) +
                               (std::string) + " cts !";

      throw PrixNonValide(errMessage);
   }
}

// Surcharge opérateur de flux <<
std::ostream& operator<<(std::ostream& os, const Produit& rhs)
{
   const short PRECISION_PRIX = 2;
   os << std::fixed << std::setprecision(PRECISION_PRIX);
   return os << "(" << rhs.no << ", \"" << rhs.libelle << "\", " << rhs.prix << ")";
}

// Opérateur d'égalité
bool operator==(const Produit& lhs, const Produit& rhs)
{
   return lhs.no == rhs.no && lhs.libelle == rhs.libelle && lhs.prix == rhs.prix;
}

// Constructeur
Produit::Produit(unsigned no, const std::string& libelle, double prix) : no(no), libelle(libelle)
{
   try
   {
      verificationPrix(prix, "Erreur dans Produit::Produit : ");
      this->prix = prix;
   }
   catch (const PrixNonValide& e)
   {
      throw e;
   }
}

// Accesseurs
double Produit::getPrix() const noexcept
{
   return prix;
}

void Produit::setPrix(double prix)
{
   try
   {
      verificationPrix(prix, "Erreur dans Produit::setPrix : ");
      this->prix = prix;
   }
   catch (const PrixNonValide& e)
   {
      throw e;
   }
}

// Opérateur d'affectation
Produit& Produit::operator=(Produit& rhs)
{
   if (&rhs == this) return *this; // En cas d'auto-assignation

   (unsigned&) no = rhs.no;
   (std::string&) libelle = rhs.libelle;
   prix = rhs.prix;

   return *this;
}
