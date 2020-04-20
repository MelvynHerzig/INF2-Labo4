/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : exceptions.h
 Auteur(s)   : Nicolas Crausaz, Forestier Quentin, Herzig Melvyn
 Date        : 20.04.2020

 But         : Implémenter deux classes exceptions pour:

               -  La manipulation de prix.
               -  L'utilisation d'incides.

 Remarque(s) : Les deux classes héritent de std::logic_error

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef INF2_LABO4_EXCEPTIONS_H
#define INF2_LABO4_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class IndiceNonValide : public std::logic_error
{
public:
   explicit IndiceNonValide (const std::string& s) : logic_error(s) {};
   explicit IndiceNonValide (const char* s)        : logic_error(s) {};
};

class PrixNonValide : public std::logic_error
{
public:
   explicit PrixNonValide (const std::string& s) : logic_error(s) {};
   explicit PrixNonValide (const char* s)        : logic_error(s) {};
};

#endif //INF2_LABO4_EXCEPTIONS_H
