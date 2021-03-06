#include "obiekt.h"

Obiekt Obiekt::operator+(const Obiekt &Nowy)
{
   int ilosc = Tablica[0] + Nowy.Tablica[0] +1; 
   int *Wskaznik = new int[ilosc]; 
   Obiekt Temp(Wskaznik);
   
   
   Temp.Tablica[0] = ilosc-1;
   
   for(int i = 1; i <= Tablica[0]; i++)
     Temp.Tablica[i] = Tablica[i];
 
   for(int i = Tablica[0]+1; i <= ilosc; i++)
     Temp.Tablica[i] = Nowy.Tablica[i-Tablica[0]];
   
   return Temp;
}
  
Obiekt & Obiekt::operator=(const Obiekt &Nowy)
{
  if(this != &Nowy)
  {
    delete [] Tablica;
    Tablica = new int[Nowy.Tablica[0]];
    for(int i = 0; i <= Nowy.Tablica[0]; i++)
      Tablica[i] = Nowy.Tablica[i];
  }
  return *this;
}
   
bool Obiekt::operator==(const Obiekt &Nowy)
{
  if(Tablica[0] != Nowy.Tablica[0])
     return false;
   else
     for(int i = 1; i < Tablica[0]; i++)
	if(Tablica[i] != Nowy.Tablica[i])
	  return false;
	
   return true;
}
  
void Obiekt::Show() 
{ 
    if(Tablica != NULL)
    {
      for(int i = 1; i <= Tablica[0]; i++) 
	cout << i << ". " << Tablica[i] << endl; 
      cout << "\n###########\n";
    }
    else
      cerr << "\nError: Wskazana tablica jest pusta!\n";
}  

void Obiekt::Pobierz_dane(string nazwa_pliku)
{
    fstream plik;
    plik.open(nazwa_pliku.c_str(), ios::in | ios::out);
    
    if(plik.good())
    {
      int domyslna_ilosc, ilosc_wierszy = 0;
      if(!	plik.fail())
	 plik >> domyslna_ilosc;
      else
      {
	 cerr << "\nError: Bledna wartosc w pliku.\n";
	 exit(-1);
      }
      
      for(int i = 0 ; !plik.eof(); i++)
	 if(plik.get() == '\n')
	    ilosc_wierszy++;
	 
      if(domyslna_ilosc == ilosc_wierszy)
      {
	 int ilosc = domyslna_ilosc;
	 Tablica = new int[ilosc+1];
	 Tablica[0] = ilosc;
    
	 for(int i = 1; !plik.eof(); i++)
	 {
	    if(!plik.fail())
	       plik >> Tablica[i];
	    else
	    {
	       cerr << "\nError: Bledna wartosc w pliku.\n";
	       exit(-1);
	    }
	 }
      
	 plik.close();
      }
      else
      {
	 cerr << "\nError: Niepoprawny format pliku.\n";
	 exit(-1);
      }
    }
    else
    {
       cerr << "\nError: Bledna nazwa/sciezka pliku.\n";
       exit(-1);
    }
}

void Obiekt::Pomnoz(int mnoznik)
{
  for(int i = 1; i <= Tablica[0]; i++)
    Tablica[i] *= mnoznik;
}

void Obiekt::Czy_rowne(const Obiekt &Porownywany)
{ 
  if(*this==Porownywany)
    cout << "Rowne!\n";
  else
    cout << "Rozne!\n";   
}

void Obiekt::Zamien_elementy(int i, int j)
{
    int Temp;
    if(i == 0 && j == 0)
    {
      Temp = Tablica[i];
      Tablica[i] = Tablica[j];
      Tablica[j] = Temp;
    }
    else
    {
       cerr << "\nError: Mozna zamieniac miejscami wartosci 1-dlugosc_tablicy.\n";
       exit(-1);
    }
}

void Obiekt::Odwroc_kolejnosc()
{
    int *Wskaznik = new int[*Tablica];
    
    for(int i = 0; i <= Tablica[0]; i++)
      Wskaznik[i] = Tablica[i];
    
    for(int i = 1; i <= Tablica[0]; i++)
      Tablica[i] = Wskaznik[Wskaznik[0]-i+1];
}

void Obiekt::Dodaj_element(int Element)
{
    int nowa_ilosc = Tablica[0] + 1;
    int *Wskaznik = new int[nowa_ilosc];
    Wskaznik[0] = nowa_ilosc; 
    
    for(int i = 1; i <= nowa_ilosc-1; i++)
    {
	Wskaznik[i] = Tablica[i];
    }
    
    Wskaznik[nowa_ilosc] = Element;
    Tablica = Wskaznik;
}

void Obiekt::Dodaj_elementy(Obiekt &Nowy)
{
   int ilosc = Tablica[0] + Nowy.Tablica[0] +1; 
   int *Wskaznik = new int[ilosc]; 
   Obiekt Temp(Wskaznik);
   
   
   Temp.Tablica[0] = ilosc-1;
   
   for(int i = 1; i <= Tablica[0]; i++)
     Temp.Tablica[i] = Tablica[i];
 
   for(int i = Tablica[0]+1; i <= ilosc; i++)
     Temp.Tablica[i] = Nowy.Tablica[i-Tablica[0]];

   Tablica = Temp.Tablica;
}
