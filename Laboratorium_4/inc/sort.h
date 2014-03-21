#ifndef SORT_H
#define SORT_H

#include <iostream>
#include "obiekt.h"

using namespace std;

class Sort{
public:
   int *Zapisane_dane;
   
   void Zapisz_dane(const Obiekt Obiekt);
   void Wizualizuj_zmiany(const Obiekt Obiekt);
   
   void QuickSort(Obiekt& Obiekt, int pierwszy, int ostatni);
   void MergeSort(Obiekt& Obiekt);
};

#endif