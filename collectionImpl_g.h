/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collectionImpl_g.h
 Auteur(s)   : Nicolas Crausaz, Melvyn Herzig, Quentin Forestier
 Date        : 22.04.2020

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef INF2_LABO4_COLLECTIONIMPL_G_H
#define INF2_LABO4_COLLECTIONIMPL_G_H

#include "collection_g.h"
#include <algorithm>    // std::find, std::for_each
#include <iterator>     // std::advance
#include "exceptions.h" // IndiceNonValide

template <typename T, template <typename, typename> class Conteneur>
Collection<T, Conteneur>::Collection(const Conteneur<T, std::allocator<T>>& c)
        : conteneur(c) {}

template <typename T, template <typename, typename> class Conteneur>
void Collection<T, Conteneur>::ajouter(const T& element)
{
   conteneur.push_back(element);
}

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

template <typename T, template <typename, typename> class Conteneur>
bool Collection<T, Conteneur>::contient(const T& element) const
{
   return std::find(conteneur.begin(), conteneur.end(), element) != conteneur.end();
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

template <typename T, template <typename, typename> class Conteneur>
template <typename UnaryFunction>
void Collection<T, Conteneur>::parcourir(UnaryFunction function)
{
   std::for_each(conteneur.begin(), conteneur.end(), function);
}

template <typename T, template <typename, typename> class Conteneur>
const T& baseGet (const Collection<T, Conteneur>& collection, size_t index)
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

#endif // INF2_LABO4_COLLECTIONIMPL_G_H
