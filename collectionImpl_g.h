#ifndef INF2_LABO4_COLLECTIONIMPL_G_H
#define INF2_LABO4_COLLECTIONIMPL_G_H

#include <algorithm>
#include "collection_g.h"
#include "exceptions.h"

template<typename T, template<typename, typename> class Conteneur>
std::ostream& operator<<(std::ostream& os, Collection<T, Conteneur> c)
{
   os << "[";
   for(int i = 0; i < c.size(); ++i)
   {
      if(i != 0) os << ", ";

      os << c.get(i);
   }
   os << "] (taille = " << c.taille() << ")";
   return os;
}

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
      return conteneur.at(index);
   }
   catch (std::out_of_range& e)
   {
      std::cout << "Erreur dans Collection::get : " << std::endl;
      throw IndiceNonValide("n doit etre strictement plus petit que "
                            "collection.size()");
   }
}

template<typename T, template<typename, typename> class Conteneur>
bool Collection<T, Conteneur>::contient(T itemATrouver)
{
   return std::find(conteneur.begin(), conteneur.end(), itemATrouver)
          == conteneur.end();
}

template<typename T, template<typename, typename> class Conteneur>
void Collection<T, Conteneur>::vider()
{
   conteneur.clear();
}

template<typename T, template<typename, typename> class Conteneur>
size_t Collection<T, Conteneur>::taille()
{
   return conteneur.size();
}


#endif //INF2_LABO4_COLLECTIONIMPL_G_H
