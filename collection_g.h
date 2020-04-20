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

template <typename T, template<typename, typename> class Conteneur>
class Collection
{
   friend std::ostream& operator<<(std::ostream& os,
                                   Collection<T, Conteneur> c);
public:
   void ajouter(T item);
   T& get(size_t index);
   bool contient(T itemATrouver);
   void vider();
   size_t taille();
private:
   Conteneur<T, std::allocator<T>> conteneur;
};

#include "collectionImpl_g.h"

#endif //INF2_LABO4_COLLECTION_G_H
