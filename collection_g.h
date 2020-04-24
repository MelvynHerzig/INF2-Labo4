/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_g.h
 Auteur(s)   : Nicolas Crausaz, Melvyn Herzig, Quentin Forestier
 Date        : 24.04.2020

 But         : Implémenter une classe permettant de stocker des objets quelconques
               avec une type de conteneur choisi.

                - Vérifier l'appartenance d'un objet
                - Savoir le nombre d'objet
                - Accéder/modifier un objet en position choisie
                - Une fonction qui applique une modification à tous les objets.

 Remarque(s) : La fonction contient() nécessite que l'opérateur == soit implémenté
               pour le type T.
               La méthode vider nécessite l'implémentation de la méthode clear()
               pour le conteneur
               La méthode taille nécessite l'implémentation de la méthode size()
               pour le conteneur

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef INF2_LABO4_COLLECTION_G_H
#define INF2_LABO4_COLLECTION_G_H

template <typename T, template <typename, typename> class Conteneur>
class Collection;

template <typename T, template <typename, typename> class Conteneur>
std::ostream& operator<<(std::ostream& os, const Collection<T, Conteneur>& c);

template <typename T, template <typename, typename> class Conteneur>
const T& baseGet (const Collection<T, Conteneur>& collection, size_t index);

template <typename T, template <typename, typename> class Conteneur>
class Collection
{
   friend std::ostream& operator<< <T, Conteneur>(std::ostream& os,
                                                  const Collection<T, Conteneur>& c);
   friend const T& baseGet <T, Conteneur>(const Collection<T, Conteneur>& collection, size_t index);

public:
   Collection() = default;

   explicit Collection(const Conteneur<T, std::allocator<T>>& c);

   void ajouter(const T& element);

   const T& get(size_t index) const;

   T& get(size_t index);

   bool contient(const T& element) const;

   void vider() noexcept;

   size_t taille() const noexcept;

   template <typename UnaryFunction>
   void parcourir(UnaryFunction function);

private:
   Conteneur<T, std::allocator<T>> conteneur;

};

#include "collectionImpl_g.h"

#endif // INF2_LABO4_COLLECTION_G_H
