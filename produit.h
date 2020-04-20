/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.h
 Auteur(s)   : Nicolas Crausaz
 Date        : 20.04.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef INF2_LABO4_PRODUIT_H
#define INF2_LABO4_PRODUIT_H

#include <string>

class Produit {
   friend std::ostream& operator<<(std::ostream& os, const Produit& rhs);
   friend bool operator==(const Produit& lhs, const Produit& rhs);

public:
   Produit(unsigned no, const std::string& libelle, double prix);
   Produit(const Produit& produit) = default;
   void setPrix(double prix);
   double getPrix() const;
   Produit& operator=(Produit& rhs);

private:
   const unsigned no;
   const std::string libelle;
   double prix;
   static const double PRIX_MINIMUM;
};

#endif //INF2_LABO4_PRODUIT_H
