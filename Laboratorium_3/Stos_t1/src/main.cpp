#include "stos.h"
#include <chrono>

using namespace std::chrono;

int main(int argc, char* argv[])
{
   // Tworzenie elementu stosu
   Stos A;

   int *Dane = A.Pobierz_dane();
   
   // Pomiar wypełnienia tablicy
   auto start=high_resolution_clock::now();
   for(int i = 0; i < A.zakres; i++)
      A.push(Dane[i]);
   auto diff=duration_cast<nanoseconds>(high_resolution_clock::now()-start);	      
   
   // Eksport danych
   A.Eksportuj_dane(diff.count());
}