#ifndef WPIS_H
#define WPIS_H

/*!
 * \file 
 * \brief Definicja klasy Wpis
 * Plik zawiera definicję klasy Wpis.
*/
#include <string>
#include <iostream>

using namespace std;

/*! 
* \brief Modeluje pojęcie wpisu.
* Posiada pola zawierające klucz oraz wartość danego wpisu.
*/

template<typename K , typename V >
class Wpis 
{
public:
   // Pola
/*!
 * \brief Inicjalizuje wartosc klucz.
 */ 
   K key;
/*! 
 * \brief Inicjalizuje zmienna wartość.
 */
   V *wart;
	
   // Konstruktory
   Wpis()
   {
      wart=new V;
   }
   
   Wpis (K klucz , V wartosc)
   {
      key = klucz;
      wart = new V;
      *wart = wartosc;
   }

};

#endif