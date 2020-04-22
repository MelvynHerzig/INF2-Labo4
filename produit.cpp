/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.cpp
 Auteur(s)   : Nicolas Crausaz, Melvyn Herzig, Quentin Forestier
 Date        : 22.04.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip>
#include "produit.h"
#include "exceptions.h"

const double Produit::PRIX_MINIMUM = 0.05;

std::ostream& operator<<(std::ostream& os, const Produit& rhs)
{
   const short PRECISION_PRIX = 2;
   os << std::fixed << std::setprecision(PRECISION_PRIX);
   return os << "(" << rhs.no << ", \"" << rhs.libelle << "\", " << rhs.prix << ")";
}

Produit::Produit(unsigned no, const std::string& libelle, double prix) : no(no), libelle(libelle)
{
   if (prix < PRIX_MINIMUM)
   {
      std::string errMessage = (std::string) "le prix doit etre >= " +
                               (std::string) std::to_string((unsigned) (PRIX_MINIMUM * 100)) +
                               (std::string) +" cts !";
      throw PrixNonValide(errMessage);
   }
   this->prix = prix;
}

void Produit::setPrix(double prix)
{
   this->prix = prix;
}

Produit& Produit::operator=(Produit& rhs)
{
   if (&rhs == this)
   { return *this; }

   (unsigned&) no = rhs.no;
   (std::string&) libelle = rhs.libelle;
   (double&) prix = rhs.prix;
   return *this;
}

bool operator==(const Produit& lhs, const Produit& rhs)
{
   return lhs.no == rhs.no && lhs.libelle == rhs.libelle && lhs.prix == rhs.prix;
}

double Produit::getPrix() const
{
   return prix;
}
