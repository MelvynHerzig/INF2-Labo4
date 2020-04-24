/*
 -------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collectionImpl_g.h
 Auteur(s)   : Nicolas Crausaz, Melvyn Herzig, Quentin Forestier
 Date        : 24.04.2020

 Compilateur : MinGW-g++ 6.3.0
 -------------------------------------------------------------------------------
 */

#ifndef INF2_LABO4_COLLECTIONIMPL_G_H
#define INF2_LABO4_COLLECTIONIMPL_G_H

#include "collection_g.h"
#include <algorithm>    // std::find, std::for_each
#include <iterator>     // std::advance
#include "exceptions.h" // IndiceNonValide



// ------------------------
//    Méthodes amies
// ------------------------

// Opérateur de flux pour la collection
template <typename T, template <typename, typename> class Conteneur>
std::ostream& operator<<(std::ostream& os, const Collection<T, Conteneur>& c)
{
   os << "[";
   for (size_t i = 0; i < c.taille(); ++i)
   {
      if (i != 0)
      { os << ", "; }
      os << c.get(i);
   }
   return os << "]";
}

// Obtention d'un élément dans la conteneur, renvoi une lvalue
template <typename T, template <typename, typename> class Conteneur>
const T& baseGet(const Collection<T, Conteneur>& collection, size_t index)
{
   if (index >= collection.taille())
   {
      throw IndiceNonValide("n doit etre strictement plus petit que "
                            "collection.size()");
   }

   auto it = collection.conteneur.begin();
   std::advance(it, index);

   return *it;
}

// ------------------------
//    Méthodes publiques
// ------------------------

// Constructeur
template <typename T, template <typename, typename> class Conteneur>
Collection<T, Conteneur>::Collection(const Conteneur<T, std::allocator<T>>& c)
        : conteneur(c)
{}

// Ajout d'un élément dans le conteneur
template <typename T, template <typename, typename> class Conteneur>
void Collection<T, Conteneur>::ajouter(const T& element)
{
   conteneur.push_back(element);
}

// Obtention d'un élément dans la conteneur, renvoi une lvalue
template <typename T, template <typename, typename> class Conteneur>
T& Collection<T, Conteneur>::get(size_t index)
{
   try
   {
      return (T&) baseGet(*this, index);
   }
   catch (const IndiceNonValide& e)
   {
      std::cout << "Erreur dans Collection::get : " << std::endl;
      throw e;
   }
}

// Obtention d'un élément dans la conteneur, renvoi une rvalue
template <typename T, template <typename, typename> class Conteneur>
const T& Collection<T, Conteneur>::get(size_t index) const
{
   try
   {
      return baseGet(*this, index);
   }
   catch (const IndiceNonValide& e)
   {
      std::cout << "Erreur dans Collection::get : " << std::endl;
      throw e;
   }
}

// Verification qu'un element est dans le conteneur
template <typename T, template <typename, typename> class Conteneur>
bool Collection<T, Conteneur>::contient(const T& element) const
{
   return std::find(conteneur.begin(),
                    conteneur.end(),
                    element) != conteneur.end();
}

// Le conteneur doit implémenter la méthode clear()
template <typename T, template <typename, typename> class Conteneur>
void Collection<T, Conteneur>::vider() noexcept
{
   conteneur.clear();
}

// Le conteneur doit implémenter la méthode size()
template <typename T, template <typename, typename> class Conteneur>
size_t Collection<T, Conteneur>::taille() const noexcept
{
   return conteneur.size();
}

// Applique une fonction donnée pour chaque élément du conteneur
template <typename T, template <typename, typename> class Conteneur>
template <typename UnaryFunction>
void Collection<T, Conteneur>::parcourir(UnaryFunction function)
{
   std::transform(conteneur.begin(),
                  conteneur.end(),
                  conteneur.begin(),
                  function);
}

//



#endif // INF2_LABO4_COLLECTIONIMPL_G_H
