/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_g.h
 Auteur(s)   : Nicolas Crausaz
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

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

   void ajouter(T item);
   T& get(size_t index) const;
   bool contient(T itemATrouver);
   void vider();
   size_t taille();

   template<typename Fonction>
   void parcourir(Fonction f);

private:
   Conteneur<T, std::allocator<T>> conteneur;
};

#include "collectionImpl_g.h"

#endif //INF2_LABO4_COLLECTION_G_H
