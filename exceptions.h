/*
 -------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : exceptions.h
 Auteur(s)   : Nicolas Crausaz, Melvyn Herzig, Quentin Forestier
 Date        : 24.04.2020

 But         : Implémenter deux classes exceptions pour:

               -  La vérification de prix.
               -  L'utilisation d'indices.

 Remarque(s) : Les deux classes héritent de std::logic_error

 Compilateur : MinGW-g++ 6.3.0
 -------------------------------------------------------------------------------
 */

#ifndef INF2_LABO4_EXCEPTIONS_H
#define INF2_LABO4_EXCEPTIONS_H

#include <stdexcept> // std::logic_error
#include <string>    // std::string

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

#endif // INF2_LABO4_EXCEPTIONS_H
