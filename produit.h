/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.h
 Auteur(s)   : Nicolas Crausaz, Melvyn Herzig, Quentin Forestier
 Date        : 22.04.2020

 But         : Implémenter une classe produit minimale
                  - Construction
                  - get/set du prix
                  - operator=
                  - operator<< (amitié)
                  - operator== (amitié)
                  - validation prix (amitié)

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef INF2_LABO4_PRODUIT_H
#define INF2_LABO4_PRODUIT_H

#include <string> // std::string

class Produit
{
   friend void verificationPrix(double prix, const std::string& source);
   friend std::ostream& operator<<(std::ostream& os, const Produit& rhs);
   friend bool operator==(const Produit& lhs, const Produit& rhs);

public:
   Produit(unsigned no, const std::string& libelle, double prix);
   Produit(const Produit& produit) = default;
   double getPrix() const noexcept;
   void setPrix(double prix);
   Produit& operator=(Produit& rhs);

private:
   const unsigned no;
   const std::string libelle;
   double prix;
   static const double PRIX_MINIMUM;
};

#endif //INF2_LABO4_PRODUIT_H
