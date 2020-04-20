/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.cpp
 Auteur(s)   : Nicolas Crausaz
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include "produit.h"
#include "exceptions.h"

const double Produit::PRIX_MINIMUM = 0.05;

// Produit::Produit() {}

std::ostream& operator<<(std::ostream& os, const Produit& rhs)
{
   return os << "(" << rhs.no << ", \"" << rhs.libelle << "\", " << rhs.prix << ")";
}

Produit::Produit(unsigned no, const std::string& libelle, double prix) : no(no), libelle(libelle)
{
   if (prix < PRIX_MINIMUM)
   {
      std::string errMessage = "le prix doit etre >= ";
      errMessage += PRIX_MINIMUM;
      errMessage += " cts !";
      throw PrixNonValide(errMessage);
   }
   this->prix = prix;
}

void Produit::setPrix(double prix)
{
   this->prix = prix;
}