/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_g.h
 Auteur(s)   : Nicolas Crausaz, Melvyn Herzig, Quentin Forestier
 Date        : 22.04.2020

 But         : Implémenter une classe permettant de stocker des objets quelconques
               avec une type de conteneur choisi.

                - Vérifier l'appartenance d'un objet
                - Savoir le nombre d'objet
                - Accéder/modifier un objet en position choisie
                - Une fonction qui applique une modification à tous les objets.

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef INF2_LABO4_COLLECTION_G_H
#define INF2_LABO4_COLLECTION_G_H

template <typename T, template<typename, typename> class Conteneur>
class Collection;

template<typename T, template<typename, typename> class Conteneur>
std::ostream& operator<< (std::ostream& os, Collection<T, Conteneur> c)
{
   os << "[";
   for (size_t i = 0; i < c.taille(); ++i)
   {
      if (i != 0)
      { os << ", "; }

      os << c.get(i);
   }
   os << "]";
   return os;
}


template <typename T, template<typename, typename> class Conteneur>
class Collection
{
   friend std::ostream& operator<< <T, Conteneur>(std::ostream& os,
                                   Collection<T, Conteneur> c);
public:

   Collection() = default;

   explicit Collection(const Conteneur<T, std::allocator<T>>& c);

   void ajouter(const T& item);

   T get(size_t index) const;

   T& get(size_t index);

   bool contient(const T& itemATrouver) const;

   void vider() noexcept;

   size_t taille() const noexcept;

   template<typename UnaryFunction>
   void parcourir(UnaryFunction function);

private:
   Conteneur<T, std::allocator<T>> conteneur;

};

#include "collectionImpl_g.h"

#endif //INF2_LABO4_COLLECTION_G_H
