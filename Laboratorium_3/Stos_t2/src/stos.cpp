#include "stos.h"

void Stos::push(int Nowy)
{
   if(Tablica == NULL)
   {
      Tablica = new int;
      wielkosc_tablicy++;
   }
  
   int nowa_ilosc = ilosc_elementow+1;
   if(nowa_ilosc <= wielkosc_tablicy)
   {
      Tablica[nowa_ilosc-1] = Nowy;
   }
   else
   {
      int nowa_ilosc = 2*ilosc_elementow;      // Podwajanie
      int *Wskaznik = new int[nowa_ilosc];
      for(int i = 0; i <= ilosc_elementow; i++)
	 Wskaznik[i] = Tablica[i];
    
      Wskaznik[ilosc_elementow] = Nowy;
      delete Tablica;
      Tablica = Wskaznik;
      wielkosc_tablicy*=2;
   }
   ilosc_elementow++;
  
  
}

void Stos::pop()
{
  if(ilosc_elementow < 0.25*wielkosc_tablicy)
  {
    int nowy_rozmiar = 0.5 * wielkosc_tablicy;
    int *Wskaznik = new int[nowy_rozmiar];
    for(int i = 0; i < ilosc_elementow; i++)
      Wskaznik[i] = Tablica[i];
    Tablica = Wskaznik;
    wielkosc_tablicy -= 0.5*wielkosc_tablicy;
  }
  ilosc_elementow = ilosc_elementow-1;
}

bool Stos::isEmpty()
{
  if(ilosc_elementow != 0)
    return true;
  return false;
}

void Stos::Show()
{
  for(int i = 0; i<ilosc_elementow; i++)
    cout << ">>> " << Tablica[i] << endl;
  
  cout << "\n############\n";
  cout << "Ilosc = " << ilosc_elementow << endl;
  cout << "############\n";
  cout << "\n############\n";
  cout << "Wielkosc = " << wielkosc_tablicy << endl;
  cout << "############\n";
}

int Stos::size()
{
   
  return ilosc_elementow;
}

int* Stos::Pobierz_dane()
{
   int *Tablica_danych;

   fstream plik;

   plik.open("Zakres_temp.txt", ios::in);
      
   if(plik.good())
      plik >> zakres; 
      
   plik.close();
   
   Tablica_danych = new int[zakres];
   plik.open("Dane_testowe.txt", ios::in);
   if(plik.good())
      for(int i = 0; i < zakres; i++)
	 plik >> Tablica_danych[i];
   else
   {
      cerr << "\nError: Nie otwarto pliku Dane_testowe.txt\n";
   }
   plik.close();
      
   return Tablica_danych;
}

int Stos::Opcje(int argc, char **argv)
{
   for(int i = 1; i < argc; i++)
   {
      if(argv[i][0] != '-')
      {
	 cerr << "Error: Blad w linii polecen. [-opcja parametr]\n";
	 return -1;
      }
      
      switch(argv[i][1])
      {
	 case 'z':
	 {
	    if(++i < argc)
	       zakres = atoi(argv[i]);
	    break;
	 }
	 default:
	 {
	    cerr << "\nError: Zly parametr wywolania.\n";
	    break;
	 }
      }
      
   }
   return 1;
}