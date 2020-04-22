/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collectionImpl_g.h
 Auteur(s)   : Nicolas Crausaz, Melvyn Herzig, Quentin Forestier
 Date        : 22.04.2020

 But         : 

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef INF2_LABO4_COLLECTIONIMPL_G_H
#define INF2_LABO4_COLLECTIONIMPL_G_H

#include <algorithm>
#include "collection_g.h"
#include "exceptions.h"

template<typename T, template<typename, typename> class Conteneur>
void Collection<T, Conteneur>::ajouter(T item)
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
         throw std::out_of_range("Erreur d'indice");
      }


      auto it = conteneur.begin();
      std::advance(it, index);

      return *it;
   }
   catch (std::out_of_range& e)
   {
      std::cout << "Erreur dans Collection::get : " << std::endl;
      throw IndiceNonValide("n doit etre strictement plus petit que "
                            "collection.size()");
   }
}




template<typename T, template<typename, typename> class Conteneur>
bool Collection<T, Conteneur>::contient(T itemATrouver) const
{
   return std::find(conteneur.begin(), conteneur.end(), itemATrouver)
          != conteneur.end();
}

template<typename T, template<typename, typename> class Conteneur>
void Collection<T, Conteneur>::vider()
{
   conteneur.clear();
}

template<typename T, template<typename, typename> class Conteneur>
size_t Collection<T, Conteneur>::taille() const
{
   return conteneur.size();
}

template<typename T, template<typename, typename> class Conteneur>
template<typename Fonction>
void Collection<T, Conteneur>::parcourir(Fonction f)
{
   std::for_each(conteneur.begin(), conteneur.end(), f);
}


#endif //INF2_LABO4_COLLECTIONIMPL_G_H
