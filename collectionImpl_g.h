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
#include <algorithm>       //std::find, std::for_each,
#include "exceptions.h"    //IndiceNonValide

template<typename T, template <typename, typename> class Conteneur>
Collection<T, Conteneur>::Collection(const Conteneur<T, std::allocator<T>>& c)
: conteneur(c)
{}

template<typename T, template<typename, typename> class Conteneur>
void Collection<T, Conteneur>::ajouter(const T& item)
{
   conteneur.push_back(item);
}

template<typename T, template<typename, typename> class Conteneur>
T& Collection<T, Conteneur>::get(size_t index)
{
   try
   {
      if (index >= taille() || index < 0)
      {
         throw IndiceNonValide("n doit etre strictement plus petit que "
                               "collection.size()");
      }

      auto it = conteneur.begin();
      std::advance(it, index);

      return *it;
   }
   catch (const IndiceNonValide& e)
   {
      std::cout << "Erreur dans Collection::get : " << std::endl;
      throw e;
   }
}

<<<<<<< HEAD
template<typename T, template<typename, typename> class Conteneur>
T Collection<T, Conteneur>::get(size_t index) const
{
   try
   {
      if (index >= taille() || index < 0)
      {
         throw IndiceNonValide("n doit etre strictement plus petit que "
                               "collection.size()");
      }

      auto it = conteneur.begin();
      std::advance(it, index);

      return *it;
   }
   catch (IndiceNonValide& e)
   {
      std::cout << "Erreur dans Collection::get : " << std::endl;
      throw e;
   }
}

=======
>>>>>>> master
template<typename T, template<typename, typename> class Conteneur>
bool Collection<T, Conteneur>::contient(const T& itemATrouver) const
{
   return std::find(conteneur.begin(), conteneur.end(), itemATrouver)!= conteneur.end();
}

template<typename T, template<typename, typename> class Conteneur>
void Collection<T, Conteneur>::vider() noexcept
{
   conteneur.clear();
}

template<typename T, template<typename, typename> class Conteneur>
size_t Collection<T, Conteneur>::taille() const noexcept
{
   return conteneur.size();
}

template<typename T, template<typename, typename> class Conteneur>
template<typename UnaryFunction>
void Collection<T, Conteneur>::parcourir(UnaryFunction function)
{
   std::for_each(conteneur.begin(), conteneur.end(), function);
}


#endif //INF2_LABO4_COLLECTIONIMPL_G_H
