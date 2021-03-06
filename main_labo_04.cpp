/*
 -------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : main_labo_04.cpp
 Auteur(s)   : Nicolas Crausaz, Melvyn Herzig, Quentin Forestier
 Date        : 24.04.2020

 But         : Tester le fonctionnement d'un Produit.

               Tester de manipuler des Collections avec plusieurs types
               de données:
                  - char
                  - Produit
               Et différents conteneurs:
                  - Vector
                  - List

 Remarque(s) : /

 Compilateur : MinGW-g++ 6.3.0
 -------------------------------------------------------------------------------
 */

#include <cstdlib>         // std::EXIT_SUCCESS
#include <iostream>        // std::cout
#include <list>            // std::list
#include <vector>          // std::vector
#include "collection_g.h"  // Collection, operator<<
#include "exceptions.h"    // PrixNonValide, IndiceNonValide
#include "produit.h"       // Produit, SetPrix, GetPrix, operator=

using namespace std;

int main()
{
   {
      cout << "------------------------------------------------------------" << endl;
      cout << "Test sur Collection<char, vector> :" << endl;
      try {
         Collection<char, vector> c;
         for (char ch = 'A'; ch < 'D'; ++ch)
            c.ajouter(ch); 
         cout << c << " (taille = " << c.taille() << ")" << endl;
         c.get(0) = 'B';
         c.get(1) = c.get(2);
         c.get(2) = 'D';
         cout << c << " (taille = " << c.taille() << ")" << endl;
         cout << boolalpha
              << c.contient('A') << endl
              << c.contient('D') << endl
              << noboolalpha;
         c.vider();
         cout << c << " (taille = " << c.taille() << ")" << endl;
         cout << c.get(0) << endl;
      } catch (const IndiceNonValide& e) {
         cout << e.what() << endl;   
      }
      cout << "------------------------------------------------------------" << endl;
      cout << endl;
   }

   {
      cout << "------------------------------------------------------------" << endl;
      cout << "Test sur Produit :" << endl;
      try {
         // un produit se caractérise par un no, un libellé, un prix
         Produit p1(1, "Produit 1", 0.05);
         cout << p1 << endl;
         {
            try {
               Produit p2(2, "Produit 2", 0);
            } catch (const PrixNonValide& e) {
               cout << e.what() << endl;
            }
         }
         p1.setPrix(0.0);
      } catch (const PrixNonValide& e) {
         cout << e.what() << endl;
      }
      cout << "------------------------------------------------------------" << endl;
      cout << endl;
   }

   {
      cout << "------------------------------------------------------------" << endl;
      cout << "Test sur Collection<Produit, list> :" << endl;
      try {
         Collection<Produit, list> c;
         Produit p1(1, "Produit 1", 1.55);
         Produit p2(2, "Produit 2", 5);
         c.ajouter(p1); 
         c.ajouter(p2); 
         cout << c << " (taille = " << c.taille() << ")" << endl;
         Produit tmp = c.get(0);     
         c.get(0) = c.get(1);
         c.get(1) = tmp;
         cout << c << " (taille = " << c.taille() << ")" << endl;
         cout << boolalpha
              << c.contient(p1) << endl
              << c.contient(p2) << endl
              << noboolalpha;
         {
            class Majoration
            {
            public:
               explicit Majoration (int pourcent): pourcent(pourcent) {};

               Produit& operator() (Produit& p)
               {
                  double copiePrix = p.getPrix();
                  p.setPrix((1.0 + pourcent / 100.0) * copiePrix);

                  return p;
               }
            private:
               double pourcent;
            };

            // On parcourt la collection en majorant le prix de chacun
            // des produits de 10%
            c.parcourir(Majoration(10));
            cout << c << " (taille = " << c.taille() << ")" << endl;      
         }
         c.vider();
         cout << c << " (taille = " << c.taille() << ")" << endl;
      } catch (const IndiceNonValide& e) {
         cout << e.what() << endl;   
      }
      cout << "------------------------------------------------------------" << endl;
      cout << endl;
   }
   return EXIT_SUCCESS;
}

// ------------------------------------------------------------
// Test sur Collection<char, vector> :
// [A, B, C] (taille = 3)
// [B, C, D] (taille = 3)
// false
// true
// [] (taille = 0)
// Erreur dans Collection::get : 
// n doit etre strictement plus petit que collection.size()
// ------------------------------------------------------------
// 
// ------------------------------------------------------------
// Test sur Produit :
// (1, "p", 0.05)
// Erreur dans Produit::Produit : 
// le prix doit etre >= 5 cts !
// Erreur dans Produit::setPrix : 
// le prix doit etre >= 5 cts !
// ------------------------------------------------------------
// 
// ------------------------------------------------------------
// Test sur Collection<Produit, list> :
// [(1, "Produit 1", 1.55), (2, "Produit 2", 5.00)] (taille = 2)
// [(2, "Produit 2", 5.00), (1, "Produit 1", 1.55)] (taille = 2)
// true
// true
// [(2, "Produit 2", 5.50), (1, "Produit 1", 1.71)] (taille = 2)
// [] (taille = 0)
// ------------------------------------------------------------
